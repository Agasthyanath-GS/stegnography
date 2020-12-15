#ifndef MAIN_H
#define MAIN_H

#define sucess 0;       
#define failure 1;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define magic_string "#@"             //declaring magic string

typedef struct image                  //declaring structure to store image and secret msg details
{
  char image_name[20];
  char message_name[20];
  char encoded_image_name[20];
  int image_size;
  int image_metadata_size;
  unsigned int message_size;
  unsigned int magic_string_size;
  char type[5];
  char decoded_message[20];
  }structure_data;

int size_check(structure_data *);          //function for check wheater the message bits fits inside the image bytes or not
int encode(structure_data *);              //function for encoding
int adding_bits_to_lsb(char,char *);       //function for loading bits in the lsb bit of image
int decode(structure_data *);              //function for decoding
char detecting_bits_from_lsb(char *);      //function for decoding bits from lsb bits of image
#endif