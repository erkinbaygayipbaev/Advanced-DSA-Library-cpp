# Advanced-DSA-Library-cpp
My personal collection of complex data structures and algorithms in C++. I'm building this to dive deeper into memory management and write code that's not just correct, but efficient and clean.

# Advanced DSA Library (C++)
This repository is a deep dive into complex data structures and algorithms, focusing on high performance, memory efficiency, and clean code principles.

## Goals
* Implement self-balancing trees (AVL, Red-Black Trees).
* Optimize memory management using smart pointers.
* Provide clear, production-ready C++ code.
  
## Tech Stack
* **Language:** C++17 or higher.
* **Concepts:** OOP, Templates, Memory Management.

## Current Progress
- [x] AVL Tree Implementation 
- [x] LRU Cache
- [x] Graph Algorithms

## 💻 How to Build and Run
You can compile the AVL Tree implementation using any standard C++ compiler (like g++).

### Prerequisites
* C++17 compiler or later
* Git

### Steps
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/erkinbaygayipbaev/Advanced-DSA-Library-cpp.git](https://github.com/erkinbaygayipbaev/Advanced-DSA-Library-cpp.git)
   cd Advanced-DSA-Library-cpp
   
  Compile the code:
  g++ -std=c++17 AVLTree.cpp -o avl_tree

  Run the executable:
  * On Linux/macOS:
    ./avl_tree
  * On Windows:
    avl_tree.exe
  Expected Output
When you run the program, you should see the elements printed in sorted order (proof that the AVL balancing worked):
Adding elements to AVL Tree: 10, 20, 30, 40, 50, 25
In-order traversal (Sorted): 10 20 25 30 40 50
