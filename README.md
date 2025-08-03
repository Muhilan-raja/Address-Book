# Address Book Management System – Documentation

📋 **Program Name:**
C-based Address Book System

👨‍💼 **Developed By:**
Muhilan R

🗓️ **Date:**
02/08/2025

---

## 📌 Description

This Address Book program allows users to manage a list of contacts with features like:

* Adding new contacts
* Searching contacts (by name, phone, or email)
* Editing contact details
* Deleting contacts
* Listing all contacts

Each contact stores a name, phone number, and email address with validations and duplicate checks to ensure data integrity.

---

## 🧱 File Structure

| File         | Description                                |
| ------------ | ------------------------------------------ |
| `main.c`     | Main driver file for the menu and user I/O |
| `contact.c`  | Implementation of all core functions       |
| `contact.h`  | Header file for structures and prototypes  |
| `file.c`     | File I/O functions (optional/extendable)   |
| `populate.c` | Pre-fills initial data (optional)          |
| `test.c`     | Automated unit test coverage for functions |

---

## 📂 Data Structures

```c
typedef struct {
    char name[100];
    char phone[20];
    char email[100];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;
```

---

## ⚙️ Features & Functions

### 🌟 Create Contact

* Validates name (alphabet only), phone (10-digit numeric), and email (basic format check).
* Prevents duplicates.

### 🔍 Search Contact

* Search by name, phone, or email.
* Displays contact details if found.

### ✏️ Edit Contact

* Allows editing name, phone, email, or all.
* Validates and prevents duplicates.

### 🗑️ Delete Contact

* Deletes a contact by name.
* Shifts the contact array to fill the gap.

### 📜 List Contacts

* Displays all stored contacts.
* Sorts based on name, phone, or email using index-based sort.

### 📀 Save & Load Contacts (optional)

* Hooks available to integrate file-based storage using `saveContactsToFile()`.

---

## 🛡️ Validation Logic

| Field | Criteria                                  |
| ----- | ----------------------------------------- |
| Name  | Alphabet & space only, no duplicates      |
| Phone | Exactly 10 digits, numeric, no duplicates |
| Email | Must contain @, . and be valid format     |

---

## 🧪 Example Test Cases (`test.c`)

Automated tests are implemented in `test.c` and cover:

* Valid and invalid entries
* Duplicate checks
* Editing and deletion logic

### Sample Test Coverage Table

| Test Case                       | Expected Result           |
| ------------------------------- | ------------------------- |
| Create valid contact            | Contact added             |
| Duplicate phone/email/name      | Error: Already exists     |
| Invalid phone (letters/short)   | Error: Invalid phone      |
| Invalid email (no @ or dot)     | Error: Invalid email      |
| Search for non-existent contact | Contact not found         |
| Edit contact's email            | Updated if valid          |
| Delete contact by name          | Contact deleted           |
| List all contacts               | Shows all current records |

---

## 🧹 Sorting

`listContacts()` implements index-based bubble sort to avoid altering the original structure. It supports:

* Sort by Name
* Sort by Phone
* Sort by Email

This avoids changing the actual position of the contacts inside the array.

---

## 🚼 Improvements To Consider

* File-based persistent storage
* Input sanitization using `fgets()` instead of `scanf()`
* Case-insensitive comparison using `strcasecmp()`
* Dynamic resizing using `malloc/realloc` if `MAX_CONTACTS` is exceeded
* Command-line options or GUI integration

---

## 📌 How to Compile

```bash
gcc main.c contact.c valid.c file.c populate.c -o addressbook
./addressbook
```

---

## 🔚 Conclusion

This program serves as a basic address book application with robust validation, sorting, and modular code organization. With support for testing and extensibility, it is ideal for beginners looking to understand structured C programming projects.
