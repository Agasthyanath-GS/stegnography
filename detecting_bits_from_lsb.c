#include"main.h"


char detecting_bits_from_lsb(char * buff)
{ 
   char i,ch,x;


  for(i=0;i<8;i++)
   {
       x = buff[i] & 1;     
       x = x << (7-i);
       ch = ch | x ;
   }
 if(i == 8)
    return ch;
 
}