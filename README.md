# Bank Token System

A **DSA Mini Project** implemented in **C++** that simulates a bank token management system using **Priority Queue** and **Object-Oriented Programming (OOP)** concepts.

---

## Project Overview

The **Bank Token System** manages customer service tokens in a bank environment.  
Each customer is assigned a token, and customers are served based on **priority**, ensuring efficient and fair service handling.

This project demonstrates practical usage of **Data Structures and Algorithms** in a real-world scenario.

---

## Features

- Generate unique tokens for customers
- Assign priority based on service type
- Serve customers according to priority order
- Track service timings:
  - Token issue time
  - Service start time
  - Service end time
- Display customer and token details

---

## Technologies Used

- **Programming Language:** C++
- **Core Concepts:**
  - Data Structures & Algorithms
  - Priority Queue (STL)
  - Custom Comparator
  - Object-Oriented Programming (OOP)
- **Compiler:** g++

---

## 📁 Project Structure

Bank-Token-System/
│
├── src/
│ ├── main.cpp
│ ├── Token.cpp
│ ├── BankTokenSystem.cpp
│
├── include/
│ ├── Token.h
│ ├── BankTokenSystem.h
│ ├── ComparePriority.h
│
├── docs/
│ └── Project_Report.pdf
│
├── .gitignore
└── README.md


---

## How to Compile and Run

# Step 1: Navigate to project directory
cd Bank-Token-System

# Step 2: Compile the program
g++ -Iinclude src/*.cpp -o bank

# Step 3: Run the program
./bank
OR
bank.exe


### Working Principles

-Customer requests a service
-System generates a token with assigned priority
-Tokens are stored in a priority queue
-The highest-priority customer is served first
-Service timing details are recorded and displayed


### Learning Outcomes

-Understanding and implementing priority queues
-Applying custom comparator classes
-Using OOP principles in C++
-Managing a multi-file C++ project
-Using Git and GitHub for version control


### Author
1. Ankit Stha
   https://github.com/raikoo004
2. Utsaha Karki
   https://github.com/kekw99
3. Samyog Raymaji
4. Krishna Mohan Sah

### License
This project is developed for academic purposes as a DSA mini project.









