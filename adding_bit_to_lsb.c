#include"main.h"
int adding_bits_to_lsb(char data , char * buff)
{
int i;
char data1,image;

	for(i=0;i<=7;i++)
	{
		data1 = 1<<(7-i) & data;

        data1 = data1 >> (7-i);

        buff[i] = buff[i] & ~1;
 
        buff[i] = buff[i] | data1 ;
   //printf("%d",(data1 & 1)?1:0);
               
     }
           
 
//check condition
	if (i == 8)
	{
		return sucess;
	}
	else
	{
		return failure;
	}


}