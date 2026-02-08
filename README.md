##🏦 Bank Token Management System (Priority Queue – C++)

A console-based Bank Token Management System implemented in C++ using a Priority Queue.
This project simulates how banks manage customer service tokens by prioritizing urgent services over normal ones, reflecting real-world banking operations.

This project is developed as a DSA Mini Project by undergraduate Computer Science students of Kathmandu University.

## 🚀 Key Features

* **Priority Queue–Based Token Handling**: Customers are served according to priority rather than arrival time.
* **Dynamic Token Generation**:Each customer receives a unique token number.
* **Service Time Tracking**: 
-Token issue time
-Service start time
-Service end time
* **Priority-Based Service Types**: Supports different service categories with different priorities (e.g., urgent,disabilities  vs normal people as well services).
* **Object-Oriented Design**: 
-Clear separation of responsibilities
-Modular, maintainable code structure
* **Realistic Bank Simulation**: 
-Mimics actual bank token counters
-Ensures higher-priority customers are served first

## 📑 How It Works

### Priority Queue Algorithm

The system follows a priority-based scheduling approach:

1. **Customer Arrival**:
* Customer requests a banking service.
* System generates a unique token.

2. **Priority Assignment**:
   * Each token is assigned a priority based on service type.
   * Higher priority = served earlier.

3. **Token Storage**:
   * Tokens are stored in a C++ STL priority queue.
   * A custom comparator ensures correct ordering.

4. **Customer Service**:
* The highest-priority token is extracted.
* Service start and end times are recorded.
* Customer details are displayed.
 
### The Technical Stack

* **Language**: C++
* **Compiler**: g++
* **Data Structures**: Circular Queue, class & Objects
* **Core Concepts**: 
      * Priority Queue (STL)
      * Custom Comparator
      * Object-Oriented Programming
      * Time Handling (time_t)

## ⏱️ Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert Token  |O(log n) | O(1) |
| Serve Customer |O(log n) | O(1) |
| Peek Token | O(1) | O(1) |

**Efficiency Note**: Using a priority queue ensures that urgent customers are always served first without scanning the entire list.


## 🛠️ Installation & Usage

### Prerequisites

* C++ Compiler (GCC / MinGW / Clang)
*Basic Knowledge of Terminal and command prompt

### Compile & Run

**Linux/macOS:**
```bash
cd Bank-Token-System
g++ -Iinclude src/*.cpp -o bank
./bank


**Windows(CMD/PowerShell):**
```Powershell
cd Bank-Token-System
g++ -Iinclude src/*.cpp -o bank
bank.exe
```




### System Flow

1. 🧾 Customer requests a banking service
2. 🔢 System generates a token
3. ⚡ Priority is assigned
4. 📥 Token enters priority queue
5. 🏦 Highest-priority customer is served
6. ⏱️ Service timing is recorded and displayed

## 📂 Project Structure

### Project Organization

```
Bank-Token-System/
│
├── src/
│   ├── main.cpp                # Program entry point and menu
│   ├── Token.cpp               # Token class implementation
│   └── BankTokenSystem.cpp     # Core system logic
│
├── include/
│   ├── Token.h                 # Token class declaration
│   ├── BankTokenSystem.h       # System interface
│   └── ComparePriority.h       # Custom priority comparator
│
├── screenshots/
│   ├── menu.png
│   ├── token_generation.png
│   └── serving_customer.png
│
└── README.md

```

### 🧱 Core Structures

**Token Class:**
```c++
class Token {
    int tokenNumber;
    string customerName;
    int priority;
    time_t issueTime;
    time_t serviceStartTime;
    time_t serviceEndTime;
};
```

**Priority Comparator:**
```c++
class ComparePriority {
public:
    bool operator()(Token a, Token b) {
        return a.priority < b.priority;
    }
};
This comparator ensures higher-priority tokens are served first.
```

###  🖥️ Sample Output
``` markdown 

------ Bank Token Management System ------

1. Generate Token
2. Serve Customer
3. Display Next Token
4. Exit

Enter your choice: 1

Enter Customer Name: Krishna
Service Type:
1. Normal
2. Urgent
Choice: 2

Token Generated Successfully!
Token Number: 5
Priority: High
-----------------------------------------

Serving Customer...
Token Number: 5
Customer Name: Krishna
Service Completed Successfully!

```

## 🤝 Contributing

Feel free to fork this project and submit pull requests. Future improvements could include:

* **Advanced Priority Handling:** Introduce multiple priority levels such as senior citizens, VIP customers, and emergency services
* **Multiple Service Counters:** Manage multiple bank counters to serve customers in parallel
* **Persistent Storage:** Save and restore token data using file handling or databases
* **Graphical User Interface:** Develop a GUI version using frameworks like Qt or a web-based interface
* **Advanced Scheduling Policies:** Implement hybrid scheduling such as priority + FIFO or time-based priority escalation
* **Analytics & Reporting:** Generate reports for average waiting time, service duration, and daily customer statistics
* **Authentication & Access Control:** Add staff login and role-based access for secure operations


## 📚 Learning Outcomes
This project demonstrates:

✅ Priority Queue implementation using STL
✅ Custom comparator design
✅ Practical application of OOP
✅ Time tracking in C++
✅ Modular multi-file project organization
✅ Real-world DSA problem solving that were learned

## 🔮 Possible Enhancements
 * Multiple service counters
 * Customer categories (senior citizens, VIPs)
 * Persistent data storage (file handling)
 * GUI-based interface
 * Statistical reports (average waiting time)

## 👨‍💻 Authors
Ankit Stha
Krishna Mohan Sah
Utsaha Karki
Samyog Rayamajhi


## 📄 License

This project is developed strictly for academic and educational purposes as a DSA Mini Project.

---------

**Made using** <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" alt="++"/>

**DSA Mini Project** - Priority Queue Implementation
