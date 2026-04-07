# 📘 ECE-150 Projects

> A collection of programming assignments, tutorials, and practice problems from **ECE 150 - Fundamentals of Programming** at the University of Waterloo.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![University of Waterloo](https://img.shields.io/badge/University%20of%20Waterloo-FFB900?style=for-the-badge&logo=university&logoColor=black)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

## 📋 Table of Contents

- [About](#-about)
- [Course Overview](#-course-overview)
- [Project Structure](#-project-structure)
- [Assignments](#-assignments)
  - [Assignment 1 — Grade Calculator](#assignment-1--grade-calculator)
  - [Assignment 2 — Loops, Patterns & Bit Manipulation](#assignment-2--loops-patterns--bit-manipulation)
  - [Assignment 3 — Arrays, Pointers & Dynamic Memory](#assignment-3--arrays-pointers--dynamic-memory)
  - [Assignment 4 — C-Style Strings & Algorithms](#assignment-4--c-style-strings--algorithms)
  - [Assignment 5 — Classes, Linked Lists & OOP](#assignment-5--classes-linked-lists--oop)
- [Additional Practice](#-additional-practice)
- [Tutorial Files](#-tutorial-files)
- [How to Compile & Run](#-how-to-compile--run)
- [Technologies Used](#-technologies-used)
- [License](#-license)

---

## 🎯 About

This repository documents my journey through **ECE 150: Fundamentals of Programming**, a foundational computer engineering course at the University of Waterloo. Each assignment progressively builds upon core C++ concepts — from basic I/O and control flow to dynamic memory management, pointer arithmetic, string manipulation, and object-oriented programming.

This repo serves as both a **learning portfolio** and a **reference** for key programming concepts covered throughout the term.

---

## 📚 Course Overview

**ECE 150** introduces students to structured programming using C++. Key topics covered include:

- ✅ Basic syntax, I/O, and data types
- ✅ Control structures (loops, conditionals)
- ✅ Functions and modular programming
- ✅ Arrays and pointer arithmetic
- ✅ Dynamic memory allocation (`new`/`delete`)
- ✅ C-style string manipulation
- ✅ Sorting and searching algorithms
- ✅ Classes, objects, and linked data structures

---

## 🗂️ Project Structure
ECE-150-Projects/
├── Assignment 1/ # Grade Calculator (I/O, conditionals, weighted averages)
├── Assignment 2/ # Loops, Patterns, Bit Manipulation & Utility Functions
├── Assignment 3/ # Arrays, Pointers, Dynamic Memory & Math Functions
├── Assignment 4/ # C-Style Strings & Custom Algorithms
├── Assignment 5/ # Classes, Linked Lists & Object-Oriented Programming
├── Other Practice/ # Extra practice problems & lecture examples
├── Tut 11/ # Tutorial 11 files (header, implementation, solutions)
└── README.md


---

## 📝 Assignments

### Assignment 1 — Grade Calculator 🧮
**File:** [`project_1.cpp`](./Assignment%201/project_1.cpp)

A console-based program that calculates a student's final course grade based on:
- Final examination grade (weighted)
- Mid-term examination grade (weighted)
- Five project grades (equally weighted)

The program implements **input validation** using `while` loops and calculates the final grade using the course's weighted grading scheme, with conditional logic for exam grade thresholds (40% and 60%).

**Key Concepts:** I/O, conditionals, loops, input validation, floating-point arithmetic

---

### Assignment 2 — Loops, Patterns & Bit Manipulation 🔁
**File:** [`project_2.cpp`](./Assignment%202/project_2.cpp)

A multi-function assignment covering:
- **Pattern printing** using nested `for` loops to create star (`*`) patterns
- **`log10()`** — computes the base-10 logarithm of an integer
- **`count()`** — counts occurrences of a specific bit (0 or 1) in a number's binary representation
- **`swap_bytes()`** — swaps two byte positions within a 32-bit integer using bitwise operations

**Key Concepts:** Nested loops, pattern generation, bitwise operators, assertions (`assert>`)

---

### Assignment 3 — Arrays, Pointers & Dynamic Memory 📊
**File:** [`project_3.cpp`](./Assignment%203/project_3.cpp)

Implements several mathematical and array-based functions:
- **`power()`** — computes base raised to an integer exponent
- **`geometric()`** — generates a geometric sequence array using dynamic memory allocation
- **`cross_correlation()`** — computes the cross-correlation of two double arrays
- **`shift_duplicates()`** — removes duplicate elements from an integer array in-place

**Key Concepts:** Dynamic arrays (`new`/`delete`), pointer arithmetic, array manipulation, mathematical sequences

---

### Assignment 4 — C-Style Strings & Algorithms 🧵
**Files:** [`project_4.cpp`](./Assignment%204/project_4.cpp), [`p_4_header.hpp`](./Assignment%204/p_4_header.hpp)

A comprehensive string manipulation library implementing custom versions of common string functions:
- **`length()`** — returns the length of a C-style string
- **`compare()`** — lexicographically compares two strings
- **`assign()`** — copies one string to another
- **`distance()`** — calculates edit distance between two strings
- **`is_sorted()`** — checks if a char array is sorted
- **`insert()`** — inserts a character into an array at a given position
- **`insertion_sort()`** — sorts a character array using insertion sort
- **`remove_duplicates()`** — removes duplicate characters from an array
- **`find()`** — searches for a substring within a word array
- **`free_word_array()`** — deallocates dynamically allocated word arrays

**Key Concepts:** C-style strings (`char*`), header files, string algorithms, sorting, memory management

---

### Assignment 5 — Classes, Linked Lists &
