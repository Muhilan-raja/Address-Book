#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "valid.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>
#include <unistd.h>   

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    int n = addressBook->contactCount;
    int index3[n];

    // Initialize index array
    for (int i = 0; i < n; i++)
    {
        index3[i] = i;
    }

    // Bubble sort on index array based on sortCriteria
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            int cmp = 0;
            switch (sortCriteria) 
            {
                case 1: // Sort by name
                    cmp = strcmp(addressBook->contacts[index3[j]].name,addressBook->contacts[index3[j + 1]].name);
                    break;
                case 2: // Sort by phone
                    cmp = strcmp(addressBook->contacts[index3[j]].phone,addressBook->contacts[index3[j + 1]].phone);
                    break;
                case 3: // Sort by email
                    cmp = strcmp(addressBook->contacts[index3[j]].email,addressBook->contacts[index3[j + 1]].email);
                    break;
                default:
                    printf("Invalid sort criteria.\n");
                    return;
            }

            if (cmp > 0) {
                // Swap index3
                int temp = index3[j];
                index3[j] = index3[j + 1];
                index3[j + 1] = temp;
            }
        }
    }

    // Print using sorted index3
    for (int i = 0; i < n; i++) 
    {
        int idx = index3[i];
        printf("\n\nFor the student [%d]\n", i + 1);
        printf("Name is %s\n", addressBook->contacts[idx].name);
        printf("Phone is %s\n", addressBook->contacts[idx].phone);
        printf("Email is %s\n\n", addressBook->contacts[idx].email);
        sleep(1);
    }
}

    


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    // saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    // Create a new contact
    // Get user input for contact details
    // Add the contact to the address book
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
    // Print all contacts in the address book
    int  i = n;
    printf("Contact found at index %d\n", i+1);
    printf("Name : %s\n", addressBook->contacts[i].name);
    printf("Phone: %s\n", addressBook->contacts[i].phone);
    printf("Email: %s\n", addressBook->contacts[i].email);
    return;
}
int searchName(AddressBook *addressBook)
{
    // Search for a contact by name
    // Get user input for the name to search for
    // Return the index of the contact if found, -1 otherwise say " Contact not found"
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
    // Search for a contact by phone number
    // Get user input for the phone number to search for
    // Return the index of the contact if found, -1 otherwise say " Contact not found"
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
    // Search for a contact by email
    // Get user input for the email to search for
    // Return the index of the contact if found, -1 otherwise say " Contact not found"
    int i = 0;

    char name[50];
    printf("Enter Email to search for: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < addressBook->contactCount; i++)  // Loop through all contacts in the address book
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
    // Search for a contact by name, phone number or email
    // Get user input for the search criteria
    // Display the contact details if found, otherwise say "Contact not found"
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
    // Edit a contact by name, phone number or email
    // Get user input for the search criteria
    // Ask the details to edit the contact
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

    if (index == -1) // If no contact found
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
    int choice2; // Choice to edit
    scanf("%d", &choice2);
    switch (choice2)
    {
        case 1: // edit name
        getValidatedName(addressBook,addressBook->contacts[index].name);
        break;
        case 2: // edit phone
        getValidatedPhone(addressBook,addressBook->contacts[index].phone);
        break;
        case 3: // edit email
        getValidatedEmail(addressBook,addressBook->contacts[index].email);
        break;
        case 4: // edit all
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
    // Search for contact to delete
    // If contact found, remove it from the list
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
