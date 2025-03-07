/*
Name :- Prakash Chandra Singha
Date:- 10/08/2024
description :- This is the main file for addressBook project, Which contain Contcat details of persons you can add,edit,delete,display,save,search contacts through this addressbook.
*/
#include <stdio.h>
#include<stdlib.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    
    initialize(&addressBook); // Initialize the address book
    
     
    do {
        printf("\n-----Address Book Menu-----\n");         //showing options to user
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Display contacts\n");
        printf("6. Save Contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {                    //calling fuctions as per user choice
            case e_create:
                createContact(&addressBook);
                break;
            case e_search:
                searchContact(&addressBook);
                break;
            case e_edit:
                editContact(&addressBook);
                break;
            case e_delete:
                deleteContact(&addressBook);
                break;
            case e_display:
               /* printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice);*/
                listContacts(&addressBook, 1);
                break;
            case e_save:
                   saveContactsToFile(&addressBook);
                   break;
            case e_exit:
                saveContactsToFile(&addressBook);
                //printf("Saving and Exiting...\n");
                
		         exit(0);
                 break;
            default:
                printf("Invalid choice. Please try again.\n");     //massage for invalid user input
        }
    } while (choice!=7);
  
       return 0;
}
