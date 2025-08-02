#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>
int val_mail(AddressBook *,  char *);
int val_name(AddressBook * ,char *);
int val_num(AddressBook *,char *);
int is_found_name(AddressBook *, char *);
int is_found_mail(AddressBook *, char *);
int is_found_num(AddressBook *, char *);



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
    if (is_found_num(addressBook, str)) {
        printf("Num already exists in the address book\n");
        return 0;
    }
    return 1; 
}

int val_mail(AddressBook *addressBook ,char str[])
{
   
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
            printf("Enter valid mail 1 \n");
            return 0;
        }
    }

    for (int i = dot_found + 1; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            printf("Enter valid mail 2 \n");
            return 0;
        }
    }
    if (is_found_mail(addressBook, str)) {
        printf("Email already exists in the address book\n");
        return 0;
    }

    return 1;
}


void listContacts(AddressBook *addressBook, int sortCriteria) 
{
     for (int i = 0; i < addressBook->contactCount; i++) 
     {
        printf("\n\nFor the student [%d]\n",i+1);
        printf("Name is %s\n",addressBook->contacts[i].name);
        printf("Phone is %s\n",addressBook->contacts[i].phone);
        printf("Email is %s\n\n",addressBook->contacts[i].email);
     }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    for (int i = addressBook->contactCount; i < addressBook->contactCount + 1; i++) 
    {
    printf("Creating contact [%d]:\n", i + 1);
    getValidatedName(addressBook,addressBook->contacts[i].name);
    getValidatedPhone(addressBook,addressBook->contacts[i].phone);
    getValidatedEmail(addressBook,addressBook->contacts[i].email);
    }

    addressBook->contactCount++;
   
}


void print(AddressBook *addressBook , int n )
{
    int  i = n;
    printf("Contact found at index %d\n", i+1);
    printf("Name : %s\n", addressBook->contacts[i].name);
    printf("Phone: %s\n", addressBook->contacts[i].phone);
    printf("Email: %s\n", addressBook->contacts[i].email);
    return;
}
int searchName(AddressBook *addressBook)
{
    int i = 0;
    int found = 0;
    char name[50];
    printf("Enter name to search for: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0) 
        {
            return i;
        }
    }
    printf("Contact not found.\n");
    return -1;
}

int searchPhone(AddressBook *addressBook)
{
    int i = 0;
    int found = 0;
    char name[50];
    printf("Enter phone number to search for: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].phone, name) == 0) 
        {
            return i ;
        }
    }
    printf("Contact not found.\n");
    return -1;
}
int searchEmail(AddressBook *addressBook)
{
    int i = 0;

    char name[50];
    printf("Enter Email to search for: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].email, name) == 0) 
        {
            return i ;
        }
    }
    printf("Contact not found.\n");
    return -1;
}
void searchContact(AddressBook *addressBook,int choice ) 
{
    int index2 = -1;
    switch (choice)
    {
        case 1:
            index2 = searchName(addressBook);
            break;
        case 2:
            index2 = searchPhone(addressBook);
            break;
        case 3:
            index2 = searchEmail(addressBook);
            break;
        default:
            printf("Invalid search choice.\n");
    }
    if (index2 != -1)
    {
        print(addressBook, index2);
    }

        
}

void editContact(AddressBook *addressBook, int choice)
{
    int index = -1;

    switch (choice)
    {
        case 1:
            // Edit by Name
            index = searchName(addressBook);
            break;
        case 2:
            // Edit by Phone
            index = searchPhone(addressBook);
            break;
        case 3:
            // Edit by Email
            index = searchEmail(addressBook);
            break;
        default:
            printf("Invalid edit option.\n");
            return;
    }

    if (index == -1)
    {
        printf("Contact not found. Cannot edit.\n");
        return;
    }

    printf("Enter new details for contact:\n");
    printf("What do you need to validate\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. All\n");
    int choice2;
    scanf("%d", &choice2);
    switch (choice2)
    {
        case 1:
        getValidatedName(addressBook,addressBook->contacts[index].name);
        break;
        case 2:
        getValidatedPhone(addressBook,addressBook->contacts[index].phone);
        break;
        case 3:
        getValidatedEmail(addressBook,addressBook->contacts[index].email);
        break;
        case 4:
        getValidatedName(addressBook,addressBook->contacts[index].name);
        getValidatedPhone(addressBook,addressBook->contacts[index].phone);
        getValidatedEmail(addressBook,addressBook->contacts[index].email);
        break;
        default:
        printf("Invalid choice.\n");
        return;

    }

    printf("Contact updated successfully.\n");
}


void deleteContact(AddressBook *addressBook)
{
    int index = searchName(addressBook);
    if (index == -1) {
        printf("Contact not found. Cannot delete.\n");
        return;
    }

    for (int i = index; i < addressBook->contactCount - 1; i++)
     {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;
    printf("Contact deleted successfully.\n");
}
