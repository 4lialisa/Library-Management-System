# 📚 Library Management System (LMS)

## 📘 Overview
The **Library Management System (LMS)** is a console-based C++ application designed to simplify and automate library operations.  
It enables librarians to efficiently manage books — including adding, editing, deleting, viewing, and issuing — while allowing students to search, borrow, and return books through an easy-to-use interface.

This project was developed as part of the **Computer Programming (TCP1121)** course.
---

## 👥 Collaborators

| No | Student ID | Name 
|----|-------------|------
| 1 | 1211306353 | Yii Chin Joo 
| 2 | 1211103754 | Noor Alia Alisa binti Kamal 
| 3 | 1211103698 | Ummi Syahirah binti Muhammad Rozaidee 
| 4 | 1211100633 | Nur Maisarah binti Mohammad Saifrol 
| 5 | 1211311786 | Ng Jing Wei  

---

## 🎯 Objectives

- To create a library management system that simplifies book borrowing and returning for students and librarians.  
- To enable administrators to **add, delete, edit, issue, and manage** books efficiently in real time.  
- To provide **data security** by implementing password protection for admin access.  
- To develop an **intuitive, user-friendly interface** for easy navigation and accessibility.  
- To minimize human errors and **reduce time consumption** in manual record handling.

---

## ⚙️ Program Scope

The system supports:
- **Admin Functions:**  
  - Add, update, delete, view, and search books  
  - Issue, reissue, and track borrowed books  
  - Manage data files (`Booksdata.txt`, `student.txt`)  

- **Student Functions:**  
  - View book list by section  
  - Search books by ID  
  - Borrow and return books  
  - Exit system  

**System Constraints:**
- Admin password is fixed (`"123"`) for security purposes.  
- Student menu is limited to 5 main options to maintain simplicity.  
- Invalid entries are handled with input validation prompts.  

---

## 🖥️ System Features

✅ **Object-Oriented Programming (OOP)** implementation using C++ classes and encapsulation  
✅ **File handling** to store and update book records in `.txt` files  
✅ **Password-protected** admin access  
✅ **Section-based book organization** (Computer, Electrical, Civil, Electronics, Mechanical, Architectural)  
✅ **Automatic quantity tracking** for borrowing/returning  
✅ **Error validation** for input correctness (e.g., integer validation)  
✅ **Persistent data storage** using binary file operations  

---

## 🧩 System Design

### 🔸 Class Structure
**Class:** `admin`  
**Attributes:**  
- `bookname`, `auname`, `bookid`, `id`, `quantity`, `section`, `price`

**Key Methods:**
- `addBook()`, `deleteBook()`, `updateBook()`, `searchBook()`, `viewBooks()`,  
  `issueBook()`, `viewIssueBook()`, `reissueBook()`,  
  `BorrowBook()`, `ReturnBook()`, `student()`, `admin_run()`, `login()`

### 🔸 File Handling
- Books are stored in `Booksdata.txt`
- Issued books are recorded in `student.txt`
- Temporary files like `temp.txt` used for update/delete operations  

---

## 🧮 Example Program Flow

### **Main Menu**

1. Student
2. Administrator
3. Exit

### **Admin Menu**

1. Add books
2. Delete books
3. Edit books
4. Search books
5. View all books
6. Issue books
7. View issued books
8. Reissue books
9. Logout

### **Student Menu**

1. View Book List
2. Search for a Book
3. Borrow Book
4. Return Book
5. Close Application

