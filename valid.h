#ifndef VALID_H
#define VALID_H

#include "contact.h"

// Existence Checkers
int is_found_name(AddressBook *, char *);
int is_found_num(AddressBook *, char *);
int is_found_mail(AddressBook *, char *);

// Input Prompts
void getValidatedName(AddressBook *, char *);
void getValidatedPhone(AddressBook *, char *);
void getValidatedEmail(AddressBook *, char *);


// Input Validators
int val_name(AddressBook *, char *);
int val_num(AddressBook *, char *);
int val_mail(AddressBook *, char *);





#endif