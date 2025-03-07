/*
Name :- Prakash Chandra Singha
Date:- 10/08/2024
description :- This is the header file for addressBook project, Which contain Contcat details of persons you can add,edit,delete,display,save,search contacts through this addressbook.
*/


#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

enum option
{
    e_create=1,
    e_search,
    e_edit,
    e_delete,
    e_display,
    e_save,
    e_exit,
};
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
