#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct 
{
    char name[50];
    char phone[20];
    char email[50];
    
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

// Core Operations
void createContact(AddressBook *);
void deleteContact(AddressBook *);
void listContacts(AddressBook *, int);
void editContact(AddressBook *, int);
void searchContact(AddressBook *, int);
void initialize(AddressBook *);

// Searchers
int searchName(AddressBook *);
int searchPhone(AddressBook *);
int searchEmail(AddressBook *);

// Print
void print(AddressBook *, int);

// File 
void saveContactsToFile(AddressBook *);
#endif
