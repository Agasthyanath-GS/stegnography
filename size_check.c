#include"main.h"
  
int size_check(structure_data *data)
{
   
   FILE *fp;
   int height,width;
   char ch;
   int image_size_ftell;
   fp = fopen(data->message_name,"r");
   
   fseek(fp,0,SEEK_END);
   data->message_size = ftell(fp);
   fclose(fp);
  
   fp = fopen(data->image_name, "r");
  
   fseek(fp,18,SEEK_SET);
   fread(&width, sizeof(int), 1, fp);
   fread(&height, sizeof(int), 1, fp);

  
   data->image_size = height * width * 3;
   fclose(fp);
   
     
  if(data->image_size  >= ((data->message_size + data->magic_string_size)*8) )
	{
       printf("message size is lesser than image_size \n");
      return sucess;
		}
  else
     printf("message size is grater than image size \n");
      exit(0);
   


}