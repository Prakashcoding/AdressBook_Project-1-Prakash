/*
Name :- Prakash Chandra Singha
Date:- 10/08/2024
description :- This file contains function defination to save contacts to file and load contacts from file.
*/
#include <stdio.h>
#include "file.h"
#include<stdlib.h>
#include<string.h>

void saveContactsToFile(AddressBook *addressBook)    //function defination for save file
{
    FILE *fptr;
     int i;
  fptr=fopen("addressbook.csv","w");           //opening file
  if(fptr==NULL)
  {
    printf("Error file not opened..");
    exit(1);
  }
    fprintf(fptr,"#%d\n",addressBook->contactCount);
    

    for(i=0;i<addressBook->contactCount;i++)     //printing contact details to file
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        

    }

   fclose(fptr);                            //closing file
   printf("Contact Saved Successfully...");
  
}

void loadContactsFromFile(AddressBook *addressBook) //function defination for load contacts from file
{
  FILE *fptr;
  
    fptr=fopen("addressbook.csv","r");       //opening file in read mode
  if(fptr==NULL)
  {
    printf("Error file not opened..");
    exit(1);
  } 
 char str[100];
 int i;

  
  
  if(fgets(str,sizeof(str),fptr)!=NULL)           //putting contacts to program from file
  {
    if(str[0]=='#')
    {
       //fseek(fptr,1,SEEK_SET);
       addressBook->contactCount=atoi(str+1);
        
      for(i=0;i<addressBook->contactCount;i++)
      {
      fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }
    }
  }
  
  fclose(fptr);     //closing file 

 
 
}
