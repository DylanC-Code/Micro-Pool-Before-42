# C Intensive Bootcamp - Preparation for 42 Piscine

Welcome to the C Intensive Bootcamp, a 10-day training program designed to help you master C programming fundamentals and prepare effectively for the 42 Piscine.

## 📌 Overview

This bootcamp covers key concepts of the C language, including syntax, memory management, pointers, data structures, and algorithms. Each day includes a set of topics and exercises to reinforce your understanding.

## 🚀 Program Breakdown

### **Day 1: Basic Syntax & Environment**

Install gcc, make, and configure your development environment.
Learn data types, variables, constants, and basic operators.
*Exercise*: Write a program that asks for the user's age and prints a personalized message.

### **Day 2: Loops & Conditions**

Master if, else, switch statements.
Learn loops (for, while, do...while) and control statements (break, continue).
*Exercise*: Print prime numbers from 1 to 100 & implement a multiplication table.

### **Day 3: Functions & Recursion**

Understand function declarations, definitions, and recursion.
*Exercise*: Implement factorial using recursion & sum of digits of a number.

### **Day 4: Arrays & Strings**

Work with one-dimensional and multi-dimensional arrays.
Use string manipulation functions (strlen, strcpy, strcmp).
*Exercise*: Reverse a string & implement strcpy().

### **Day 5: Pointers & Dynamic Memory**

Learn pointer arithmetic, malloc(), calloc(), free().
*Exercise*: Allocate and populate an integer array dynamically.

### **Day 6: Structures & File Handling**

Define and use struct to manage complex data.
Read and write files using fopen(), fscanf(), fprintf().
*Exercise*: Save and retrieve Person data from a file.

### **Day 7: Linked Lists**

Implement singly linked lists with dynamic memory allocation.
*Exercise*: Add elements to a linked list and print its contents.

### **Day 8: Sorting & Searching Algorithms**

Implement sorting algorithms (selection, insertion, quicksort).
Apply linear and binary search.
*Exercise*: Implement insertion sort & binary search.

### **Day 9: Classic 42 Exercises**

Work on common Piscine functions:
    ft_strlen() – Compute string length
    ft_strcpy() – Copy a string
    ft_strcmp() – Compare two strings
    ft_atoi() – Convert a string to an integer
    ft_putstr() – Print a string
    ft_putchar() – Print a character

### **Day 10: Mini Project - Simple Shell**

Read user input with getline().
Use fork(), execvp() to execute commands.
Implement a loop to process user commands until exit is entered.

## 🛠️ Requirements

Linux/macOS system with a terminal
Windows users can use a Docker container with Debian to ensure a UNIX-like environment
GCC Compiler (gcc)
Text Editor (vim, nano, VS Code)

## 📁 Project Structure

The project is organized into separate folders for each day, each containing its own Makefile for easier compilation and execution.

```css
Micro-Pool-Before-42/
│── day 1/
│   ├── Makefile
│   ├── day1.c
│   ├── ...
│── day 2/
│   ├── Makefile
│   ├── day2.c
│   ├── ...
│── ...
│── day 10/
│   ├── Makefile
│   ├── day10.c
│   ├── ...
```

## ⚡ How to Compile & Run 

To compile and run the exercises of a specific day, navigate to the corresponding folder and use make:

```sh
cd day01
make
./program
```

For cleanup:

```sh
make clean
```
