#include <stdio.h>
#include "valid.h"
#include "contact.h"
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

int val_mail(AddressBook *,  char *);
int val_name(AddressBook * ,char *);
int val_num(AddressBook *,char *);
int is_found_name(AddressBook *, char *);
int is_found_mail(AddressBook *, char *);
int is_found_num(AddressBook *, char *);
void getValidatedName(AddressBook *, char *);
void getValidatedMail(AddressBook *, char *);
void getValidatedNum(AddressBook *, char *);



int is_found_name( AddressBook *addressBook ,char str[])
{
    // check wheather the name or contact or mail is present in the stucture
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].name, str) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int is_found_num( AddressBook *addressBook ,char str[])
{
    // check wheather the name or contact or mail is present in the stucture
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].phone, str) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int is_found_mail( AddressBook *addressBook ,char str[])
{
    // check wheather the name or contact or mail is present in the stucture
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].email, str) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void getValidatedName(AddressBook *addressBook, char *dest)
 {
    // get the name from the user and validate it
    char temp[100];
    while (1) {
        printf("Enter name: ");
        scanf(" %[^\n]", temp);
        if (val_name(addressBook, temp))
        {
            strcpy(dest, temp);
            break;
        }
    }
}

void getValidatedPhone(AddressBook *addressBook, char *dest)
 {
    // get the phone from the user and validate it
    char temp[100];
    while (1) {
        printf("Enter phone number: ");
        scanf(" %[^\n]", temp);
        if (val_num(addressBook, temp)) 
        {
            strcpy(dest, temp);
            break;
        }
    }
    
}

void getValidatedEmail(AddressBook *addressBook, char *dest)
{
    // get the email from the user and validate it
    char temp[100];
    while (1) {
        printf("Enter email: ");
        scanf(" %[^\n]", temp);
        if (val_mail(addressBook, temp)) 
        {
            strcpy(dest, temp);
            break;
        }
    }
}

int val_name( AddressBook *addressBook ,char str[])
{
    // check if the name is already in the address book
    // if it is, return 1, otherwise return 0
for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isalpha(str[i]) && str[i] != ' ' )
        {
            printf("Enter Valid name , only name and spaces are allowed\n");
            return 0;
        }
    }
    if (is_found_name(addressBook, str)) {
        printf("Name already exists in the address book\n");
        return 0;
    }
    
    return 1; 
}
int val_num(AddressBook *addressBook ,char str[])
{
    // check if the phone number is already in the address book ,if it is, return 1, otherwise return 0
    // validation :
    // check if the phone number is a 10 digit number , if it is not, print an error message and return 0
    // check if the phone number contains only digits ,if it does not, print an error message and return 0
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i])) 
        {
            printf("Enter Valid number\n");
            return 0;
        }
    }
    if(strlen(str) != 10)
    {
        printf("Number must be 10 digit");
        return 0;
    }
    if (is_found_num(addressBook, str)) 
    {
        printf("Num already exists in the address book\n");
        return 0;
    }
    return 1; 
}

int val_mail(AddressBook *addressBook ,char str[])
{
    // check if the email is already in the address book ,if it is, return 1
    // validation :
    // check if the email contains '@' , if it does not, print an error message and return 0
    // check if the email contains '.' , if it does not, print an error message and return 0
    // check if the email contains only alphanumeric characters and '@' and '.' if not  return 0
   
    if (isdigit(str[0]))
    {
        printf("Enter valid mail , do not start with number\n");
        return 0;
    }

    int isat = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
        {
            isat = i;
            break;
        }
    }

    if (isat <= 0)
    {
        printf("Enter valid mail, not enough character before @ \n");
        return 0;
    }

    int dot_found = 0;
    for (int i = isat + 1; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            dot_found = i;
            break;
        }
    }

    for(int i = isat+1 ; i < dot_found ; i++ )
    {
        if(!isalpha(str[i]))
        {
            printf("Enter valid mail \n");
            return 0;
        }
    }

    for (int i = dot_found + 1; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            printf("Enter valid mail \n");
            return 0;
        }
    }
    if (is_found_mail(addressBook, str)) 
    {
        printf("Email already exists in the address book\n");
        return 0;
    }
    int has_at=0;
    int has_dot=0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
        {
            has_at++;
        }
        if (str[i] == '.')
        {
            has_dot++;
        }
    }
    if (has_at == 0 || has_dot == 0 || has_at > 1 || has_dot > 1 )
    {
        printf("Enter valid mail \n");
        return 0;
    }
   

    return 1;
}