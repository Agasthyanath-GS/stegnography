#include"main.h"

int encode(structure_data * data)
{
  FILE *fp1,*fp2,*fp3;
  int i = 54,msg_size,status,j=0,k=31; 
  char ch,buff[8],str[3];
   int size[5];
 
   fp1 = fopen(data->image_name,"r");
   fp2 = fopen(data->message_name,"r");
   fp3 = fopen(data->encoded_image_name,"w");

   strcpy(str,magic_string);

  	while(i--) 
  	{ 
 
		ch = fgetc(fp1);
        fputc(ch,fp3);
    }

   fseek(fp2,0,SEEK_END);
   msg_size = ftell(fp2);
   fseek(fp2,0,SEEK_SET);
   printf("message file size :%d\n",msg_size);

   
   for(i=0;i<2;i++)
  {
    fread(buff,1,8,fp1);
    status = adding_bits_to_lsb(str[i],buff);
    if(status == 0)
       fwrite(buff,1,8,fp3);
    else
       printf("failure at loading magic string\n");
    }

     i = 24;

    for(j=0;j<4;j++)
     {
	  fread(buff,1,8,fp1);
      ch  = (((((1<<8)-1) << i) & msg_size ) >> i);
      status = adding_bits_to_lsb(ch,buff);  
  	  if(status == 0)
          {
           fwrite(buff,1,8,fp3);
           i = i-8;
           }
       else
           printf("error in sending size of message bits\n");
        } 


 for(i=0;i<msg_size;i++)
  {
    fread(buff,1,8,fp1);
    ch=fgetc(fp2);
    status = adding_bits_to_lsb(ch,buff);
     if(status == 0)
       fwrite(buff,1,8,fp3);
    else
       printf("failure at loading msg bits\n");
    }

 
    int rd;
  do
   {
        rd = fread(buff,1,8,fp1);
        fwrite(buff,1,8,fp3);
        
    }while(rd == 8);
  printf("status : encoding sucess....!!!!!!!\n");
return sucess;
}