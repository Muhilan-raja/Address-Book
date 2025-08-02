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
// Input Validators
int val_name(AddressBook *, char *);
int val_num(AddressBook *, char *);
int val_mail(AddressBook *, char *);

// Existence Checkers
int is_found_name(AddressBook *, char *);
int is_found_num(AddressBook *, char *);
int is_found_mail(AddressBook *, char *);

// Input Prompts
void getValidatedName(AddressBook *, char *);
void getValidatedPhone(AddressBook *, char *);
void getValidatedEmail(AddressBook *, char *);

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

// File (move to file.h if separate)
void saveContactsToFile(AddressBook *);
#endif
