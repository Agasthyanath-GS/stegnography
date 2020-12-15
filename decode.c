#include"main.h"
int decode(structure_data *data)
{
   FILE *fp1,*fp2;
      
   char buff[8],image_size,str[3],ch,status;
   int i,j;
   unsigned int msg_bits = 0;

  fp1=fopen(data->encoded_image_name,"r");

  fp2=fopen(data->decoded_message,"w");
   
  str[2] = '\0';  

  fseek(fp1,0,SEEK_END);
  image_size = ftell(fp1);
  fseek(fp1,54,SEEK_SET);

  for(i=0;i<(image_size-54);i++)
   {
     for(j=0;j<2;j++)
      {
     	fread(buff,1,8,fp1);
      	status = detecting_bits_from_lsb(buff);
        str[j] = status;
         
      }
    
      if( strcmp(str,magic_string) == 0 )
       {
         printf("magic_string_match\n");
         break;
       }
      else
       {
         fseek(fp1,-15,SEEK_CUR);
       }
    }
     
  j = 32;
  int k;
  for(i=0;i<4;i++)
  {
      j = j-8; 
     fread(buff,1,8,fp1);
     status = detecting_bits_from_lsb(buff);
     msg_bits = msg_bits | (status << j) ;

  }
      data->message_size = msg_bits;



 printf("decoded message size :%d\n",data->message_size);

  
    
   for(j=0;j<data->message_size;j++)
    {
       fread(buff,1,8,fp1);
       ch = detecting_bits_from_lsb(buff);
       fputc(ch,fp2);
     }
printf("status : sucessfully decoded....!!!!\n");
}