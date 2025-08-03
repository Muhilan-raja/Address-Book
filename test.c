// use without the main .c to run test cases for this project 

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// #include "contact.h"
// #include "valid.h"
// #include "populate.h"


// // run through : gcc test.c contact.c valid.c populate.c file.c -o test
// // run through : ./test


// // Helper to print test result
// void printTestResult(const char *testName, int result) {
//     printf("[%s] : %s\n", testName, result ? "PASSED" : "FAILED");
// }

// // Name validation tests
// void testNameValidation(AddressBook *ab) {
//     printTestResult("Valid name (John Doe)", val_name(ab, "John Doe") == 1);
//     printTestResult("Invalid name (John123)", val_name(ab, "John123") == 0);
//     strcpy(ab->contacts[ab->contactCount].name, "Alice");
//     ab->contactCount++;
//     printTestResult("Duplicate name (Alice)", val_name(ab, "Alice") == 0);
// }

// // Phone validation tests
// void testPhoneValidation(AddressBook *ab) {
//     printTestResult("Valid phone (9876543210)", val_num(ab, "9876543210") == 1);
//     printTestResult("Invalid phone (short)", val_num(ab, "12345") == 0);
//     printTestResult("Invalid phone (alpha)", val_num(ab, "98ab543210") == 0);
//     strcpy(ab->contacts[ab->contactCount].phone, "1234567890");
//     ab->contactCount++;
//     printTestResult("Duplicate phone", val_num(ab, "1234567890") == 0);
// }

// // Email validation tests
// void testEmailValidation(AddressBook *ab) {
//     printTestResult("Valid email", val_mail(ab, "test@mail.com") == 1);
//     printTestResult("Invalid email (no @)", val_mail(ab, "testmail.com") == 0);
//     printTestResult("Invalid email (starts with digit)", val_mail(ab, "1test@mail.com") == 0);
//     printTestResult("Invalid email (missing .)", val_mail(ab, "test@mailcom") == 0);
//     strcpy(ab->contacts[ab->contactCount].email, "duplicate@mail.com");
//     ab->contactCount++;
//     printTestResult("Duplicate email", val_mail(ab, "duplicate@mail.com") == 0);
// }

// // Search helper
// int testSearchByName(AddressBook *ab, const char *name) {
//     for (int i = 0; i < ab->contactCount; i++) {
//         if (strcmp(ab->contacts[i].name, name) == 0) {
//             return i;
//         }
//     }
//     return -1;
// }

// // Add & search test
// void testAddAndSearch(AddressBook *ab) {
//     strcpy(ab->contacts[ab->contactCount].name, "Test User");
//     strcpy(ab->contacts[ab->contactCount].phone, "1234567890");
//     strcpy(ab->contacts[ab->contactCount].email, "test@user.com");
//     ab->contactCount++;

//     int found = testSearchByName(ab, "Test User");
//     printTestResult("Search by name (Test User)", found != -1);

//     found = testSearchByName(ab, "Ghost User");
//     printTestResult("Search by name (Ghost User)", found == -1);
// }

// // Edit contact test
// void testEditContact(AddressBook *ab) {
//     strcpy(ab->contacts[ab->contactCount].name, "EditMe");
//     strcpy(ab->contacts[ab->contactCount].phone, "9999999999");
//     strcpy(ab->contacts[ab->contactCount].email, "edit@me.com");
//     int idx = ab->contactCount;
//     ab->contactCount++;

//     // Simulate edit
//     strcpy(ab->contacts[idx].name, "Edited Name");
//     strcpy(ab->contacts[idx].phone, "8888888888");
//     strcpy(ab->contacts[idx].email, "edited@mail.com");

//     printTestResult("Edit contact name", strcmp(ab->contacts[idx].name, "Edited Name") == 0);
//     printTestResult("Edit contact phone", strcmp(ab->contacts[idx].phone, "8888888888") == 0);
//     printTestResult("Edit contact email", strcmp(ab->contacts[idx].email, "edited@mail.com") == 0);
// }

// // Delete contact test
// void testDeleteContact(AddressBook *ab) {
//     // Add contact to delete
//     strcpy(ab->contacts[ab->contactCount].name, "ToDelete");
//     strcpy(ab->contacts[ab->contactCount].phone, "0000000000");
//     strcpy(ab->contacts[ab->contactCount].email, "delete@me.com");
//     ab->contactCount++;

//     int index = testSearchByName(ab, "ToDelete");

//     // Simulate deletion
//     if (index != -1) {
//         for (int i = index; i < ab->contactCount - 1; i++) {
//             ab->contacts[i] = ab->contacts[i + 1];
//         }
//         ab->contactCount--;
//     }

//     int found = testSearchByName(ab, "ToDelete");
//     printTestResult("Delete contact (ToDelete)", found == -1);
// }

// int main() {
//     AddressBook ab;
//     ab.contactCount = 0;

//     printf("------ Running Address Book Tests ------\n");

//     testNameValidation(&ab);
//     testPhoneValidation(&ab);
//     testEmailValidation(&ab);
//     testAddAndSearch(&ab);
//     testEditContact(&ab);
//     testDeleteContact(&ab);

//     printf("------ All Tests Complete ------\n");
//     return 0;
// }

