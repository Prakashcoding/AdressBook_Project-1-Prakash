/*
Name :- Prakash Chandra Singha
Date:- 10/08/2024
description :- This is the file for addressBook project fuction defination part, Which contain logic for add,edit,delete,display,save,search contacts through this addressbook.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"



void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
   //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
     loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
  char name[30];
  char number[11];                         //Declarations of variables to get input from user
  char gmail[30];
  int i,numflag=0;
   int flag=0;
  printf("\nEnter the Name : ");          //taking input from user and storing in name
  getchar();
  scanf("%[^\n]",name);
  strcpy(addressBook->contacts[addressBook->contactCount].name,name);  //storing name in structure variable
  
  printf("\nEnter Mobile number : ");
  scanf("%s",number);                     //taking user input and storing in number
  int numlen=strlen(number);              //finding the length of user input
   if(numlen==10)                         //checking user input 10 digit or not
   {
     for(i=0;number[i]!='\0';i++)
     {
      if(number[i] >= '0' && number[i] <= '9')  //checking all string characters are numerical or not
      {
        numflag++;                             //if condition true increasing flag
      }
     }
      if(numflag==10)                          //all characters are numerical or not
       {
         for(i=0;i<addressBook->contactCount;i++)
         {
            if(strstr(addressBook->contacts[i].phone,number)!=NULL)
            {                                                       //checking string present in structure or not
              flag=1; 
              break;
            }
         }
         if(flag==0)
         {
            strcpy(addressBook->contacts[addressBook->contactCount].phone,number);    //if all condition true storing user input into structure
         }
         else
         {
            printf("Phone Number found in AddressBook !");         //else again take input form user
            return;
         }
       }
       else
       {
         printf("Enter a Valid Phone number !");
         return;
       }
       
   }
   else
   {
      printf("Please Enter a valid Number !");
      return;
   }

printf("\nEnter the Gmail ID : ");       //taking user input and storing in structure
scanf("%s",gmail);

char com[]=".com";
char at[]="@";                    //initializeing two strings for validation of email

if(strstr(gmail,at)!=NULL && strstr(gmail,com)!=NULL)        //checking for valid email
{
  strcpy(addressBook->contacts[addressBook->contactCount].email,gmail);   //storing in structure
  printf("\nContact Details Saved to AddressBook...");
  addressBook->contactCount++;                               //increment contact count
}
else
 {
   printf("Please Enter a Valid Gmail ID !");    //if user input invalid try again massage
   return;
 }
}


void listContacts(AddressBook *addressBook, int sortCriteria) 
{
  //printing all the contact details present in Addressbook.
    int i;
    printf("\n---------------------------------------------------------\n");
    printf("Sl no.\t  NAME . \t  Mobile No. \t   Email.");
    printf("\n---------------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++)
    {
    printf("%-10d",i+1);
    printf("%-10s \t%-10s \t%-10s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    
    }
    printf("\n----------------------------------------------------------\n");
    printf("\t\t[[ %d Contacts Found ! ]]",i);
    printf("\n----------------------------------------------------------\n");
}
void deleteContact(AddressBook *addressBook)
{
	char search[50];                    //declaring variables for delete contacts
  int i;
  int flag=0;
  printf("\n--Choose a Option--\n");
  printf("1.Search by name.\n");        //giving search option to user
  printf("2.search by Mobile no.\n");
  printf("3.Search by Email.\n");
  int index;
  int choice=0;
  scanf("%d",&choice);              //taking user input from given options
  if(choice==1)
  {
    printf("\nEnter the Name : \n");
    getchar();                       //taking user input if choice is 1
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].name,search)!=NULL)     //searching substring is present or not
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                                    //printing the results found                                   
    }
    if(flag==0)
    {
      printf("\nContact not Found !\n");     //if substring not found print massage and return
      return;
    }
    if(flag)
    {
      printf("\nEnter Sl no. of Contact to Delete : ");   //taking input from user for delete contact
      scanf("%d",&index);
      for(i=index-1;i<addressBook->contactCount-1;i++)
      {
        addressBook->contacts[i]=addressBook->contacts[i+1];   //deleting user choosen structure array by shifting
      }
       printf("--Contact Deleted Successfully--");  //after deletion printing massage
       (addressBook->contactCount)--;               //decrementing structure array size
    }
  }
  if(choice==2)
  {
    printf("Enter the Number : ");
    getchar();
    scanf("%[^\n]",search);                   //taking user input if choice is 2
    
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].phone,search)!=NULL)    //checking substring is present or not
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                       //if substing present then printing results
    }
    if(flag)
    {
      printf("\nContact Not Found !\n");   //if substring not found printing massage and return
      return;
    }
    if(flag)
    {
      printf("\nEnter Sl no. of Contact to Delete : ");
      scanf("%d",&index);                                   //taking user choosen input for delete
      for(i=index-1;i<addressBook->contactCount-1;i++)
      {
        addressBook->contacts[i]=addressBook->contacts[i+1];  //deleteing the structure array by shifting
      }
       printf("--Contact Deleted Successfully--");   //printing massage after deletion
       (addressBook->contactCount)--;              //after deletion decrement the array size count
    }

  }
  if(choice==3)
  {
    printf("Enter the Email : ");       //taking inputfrom user if choice is 3
    getchar();
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].phone,search)!=NULL)  //checking substing present in structur or not
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                       //if present printing all results
    }
    if(flag==0)
    {
      printf("\nContact Not Found !");        //if not found printing massage and returning to main
      return;
    }
    if(flag)
    {
      printf("\nEnter Sl no. of Contact to Delete :");   //taking input which contact user wants to delete
      scanf("%d",&index);
      for(i=index-1;i<addressBook->contactCount-1;i++)
      {
        addressBook->contacts[i]=addressBook->contacts[i+1];  //deleting the structure array by shifting
      }
       printf("--Contact Deleted Successfully--");    //printing massage after deletion
       (addressBook->contactCount)--;                  //decrementing contactcount
  }
   }   
}
void searchContact(AddressBook *addressBook)
{
  char search[50];                     //declaration of variable to search contact
  int i;
  int flag=0;
  printf("\n--Choose a Option--\n");
  printf("1.Search by name.\n");        //printing massages to user for choose
  printf("2.search by Mobile no.\n");
  printf("3.Search by Email.\n");
  int index;
  int choice;
  scanf("%d",&choice);                 //taking user choice input
  if(choice==1)
  {
    printf("\nEnter the Name : \n");     //taking user input for name
    getchar();
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].name,search)!=NULL)     //finding substing is present in array structure or not
      {
        flag++;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                   //printing results if substring present
    }
    if(flag)
    {
      printf("\n%d Contact Found !\n",flag);              //printing  massage
    }
    else{
      printf("\nContact Details Not Found ! \nPlease Try Again...\n");    //if not fount try again
      return;
    }
  }
  if(choice==2)
  {
    printf("Enter the Number : ");
    getchar();                                //taking user input for number and checking
    scanf("%[^\n]",search);
    
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].phone,search)!=NULL)
      {
        flag++;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                         //if substring found printing results
    }
    if(flag)
    {
      printf("\n%d Contact Found !\n",flag);    
    }
    else
    {
      printf("\nContact Details Not Found ! \nPlease Try Again...\n"); //if not found try again massage
      return;
    }

  }
  if(choice==3)
  {
    printf("Enter the Email : ");
    getchar();                            //taking user input for email
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].email,search)!=NULL)    //checking substing is present or not
      {
        flag++;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                   //if substing present printing resuls
    }
    if(flag)
    {
      printf("\n%d Contact Found !\n",flag);
    }
    if(flag==0)
    {
      printf("Contact not found !\nPlease Try Again...\n");  //if not found printing try again massage and return
      return;
    }
   }  
}
void editContact(AddressBook *addressBook)
{
  char search[50];
  int i;
  int flag=0;
  printf("\n--Choose a Option--\n");
  printf("1.Search by name.\n");       //showing searching options to user
  printf("2.search by Mobile no.\n");
  printf("3.Search by Email.\n");
  int index;
  int choice;
  scanf("%d",&choice);                //taking option input from user
  if(choice==1)
  {
    printf("\nEnter the Name : \n");
    getchar();                         //taking user input for name
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].name,search)!=NULL)    //checking substring is present in structure or not
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                 //if substring found printing the results
    }
    if(flag)
    {
      printf("\nEnter Contact Sl no.\n");       //taking user input for a specific contact
      scanf("%d",&index); 
    }
    else
    {
      printf("\nContact Details Not Found ! \nPlease Try Again...\n");   //if not found printing try again and return
      return;
    }
  }
  if(choice==2)
  {
    printf("Enter the Number : ");
    getchar();                            //if choice 2 taking number as input
    scanf("%[^\n]",search);
    
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].phone,search)!=NULL)    //checking substring present or not in structure
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                              //if present printing the results
    }
    if(flag)
    {
       printf("\nEnter Contact Sl no.\n");       //taking user input for a specific contact       
      scanf("%d",&index);
    }
    else{
      printf("\nContact Details Not Found ! \nPlease Try Again...\n");  //if not found try again massage and return
      return;
    }

  }
  if(choice==3)
  {
    printf("Enter the Email : ");
    getchar();                       //taking user input for email
    scanf("%[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
      if(strstr(addressBook->contacts[i].phone,search)!=NULL)    //checking substring present or not in structure
      {
        flag=1;
        printf("%d. Name : %s Phone : %s Email : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      }                                                          //if present printing the results
    }
    if(flag)
    {
      printf("\nEnter Contact Sl no.\n");              //user input for specific contact
      scanf("%d",&index);
    }
   else
   {
    printf("\nContact Details Not Found ! \nPlease Try Again...\n"); //if not found printing try again massage and return
    return;
   }  
  }
   printf("\nPlease enter details to edit..\n");


  char name[30];
  char number[11];
  char gmail[30];                        //Declaration of variables
  int numflag=0;
   int eflag=0;
  printf("\nEnter the new Name : ");
  getchar();                            //taking user input to edit name
  scanf("%[^\n]",name);               
  strcpy(addressBook->contacts[index-1].name,name);    //storing name in structure member
  printf("Name Saved to addressBook...\n");
  int yes;
  printf("Do you Want to Edit number ?\n1.Yes\n2.No\n");
  scanf("%d",&yes);
  if(yes==2)
  {
    return;
  }
  else
{
  printf("\nEnter New Mobile number : ");
  scanf("%s",number);                       //taking user input to edit number
  int numlen=strlen(number);
   if(numlen==10)                         //validating number length is 10 or not
   {
     for(i=0;number[i]!='\0';i++)
     {
      if(number[i] >= '0' && number[i] <= '9')   //validating all characters are numeric or not
      {
        numflag++;
      }
     }
      if(numflag==10)
       {
         for(i=0;i<addressBook->contactCount;i++)           //checking mobile number is present or not in structure array
         {
            if(strstr(addressBook->contacts[i+1].phone,number)!=NULL)
            {
              eflag=1; 
              break;
            }
         }
         if(eflag==0)
         {
            strcpy(addressBook->contacts[index-1].phone,number);    //storing number in structure member
         }
         else
         {
            printf("\nPhone Number found in AddressBook !\n---Please Try Again---");
            return;                                                 //if number present in structure printing try again massage and return
         }
       }
       else
       {
         printf("\nEnter a Valid Phone number !\n");
         return;                                      //if number is not valid printing invalid and returning
       }
       
   }
   else
   {
      printf("\nPlease Enter a valid Number !\n");
      return;                                      //if number is not valid printing invalid and returning
   }
  }
int no;
  printf("Contact Number Saved...\n");
printf("Do you want to edit Email?\n1.Yes\n2.No\n");
scanf("%d",&no);
if(no==2)
{
  return;
}
else{
printf("\nEnter New Gmail ID : "); 
scanf("%s",gmail);

char com[]=".com";                                //declareing srings for email validation
char at[]="@";
if(strstr(gmail,at)!=NULL && strstr(gmail,com)!=NULL)   //checking string are present or not
{
  strcpy(addressBook->contacts[index-1].email,gmail);    //storing email to the array of structure member
  printf("\nContact Details Saved to AddressBook...");
}
else
 {
   printf("\nPlease Enter a valid Gmail Address\n");    //if string are not matched printing massage invalid and return
    return;
 }
}
}
