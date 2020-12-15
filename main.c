#include "main.h"

char *extension = ".bmp";              												//saving .bmp to a charecter pointer 
char *data_extension;
structure_data data;                  												//declaring a variable of structure 

int main(int argc,char* argv[])
 {
   
   strcpy(data.image_name,argv[1]);                          
   strcpy(data.encoded_image_name,"encoded_out.bmp") ;         						//saving data inside argv[1] as image name
   strcpy(data.decoded_message,"decoded_message.txt") ;        						//saving decoded message name and type
     data.magic_string_size = 2 ;                              						//setting magic_string size
   data.image_metadata_size = 54;                              						//setting metadata size of bmp file as 54 bytes

   switch(argc)                                               						//opening switch case with argc as switching element
	{
		case 3:
               if(strcmp(argv[2],"-d") == 0 ) 	              						//check the type  belongs to decoding  
                {   
					strcpy(data.type,argv[2]);                						//saving the type to structure
			   		data_extension = strrchr(argv[1],'.');    						//calling function to saving the bytes to a constant from '.'
               		if( strcmp (data_extension,extension) == 0)         			//comparing the input image extention matches '.bmp'
                     {
						printf("decoding started....\n");
						decode(&data);                                				//calling function with structure as argument for decoding
					}
			      else
					{
                      printf("data cannot decode file type missmatch\n");   		//print error message while decoding cannot possible
					  
					}
				}
									
				break;
        case 4:
   				if(strcmp(argv[2],"-e" ) == 0 )                          			//check the type belongs to encoding
				 { 
					strcpy(data.type,argv[2]);                           			//copying the data inside argv[2] to structure              
				   	strcpy(data.message_name,argv[3]);				 	 			//copying the message file name into structure
			   		data_extension = strrchr(argv[1],'.');               			//calling function to saving the bytes to a constant from '.'
               		if( strcmp (data_extension,extension) == 0)          			//checking the extension file
					 {
                      printf("encoding started..... \n"); 
                   size_check(&data);                                    			//function to check wheather the message bits will not exeeds the size of image bytes  
                   encode(&data);                                        			//calling the function to encode with passing argument as structure
					}
				else
					{
					printf("encoding cannot done....file type missmatch\n");       	//print error message while encoding cannot possible
                      return failure				
					}
				}
				break;
		default:
				printf("data missmatch");                                          	//default condition
				break;
	}

   return 0;
}