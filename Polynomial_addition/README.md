# DS-Project


# Polynomial Addition Using Linked Lists

## About the Project

This project implements polynomial addition using
Singly Linked Lists in the C programming language.

Each node stores:
- Coefficient
- Exponent
- Pointer to the next node

The program adds two polynomials by comparing
their exponents and combining like terms.

## Features

- Create two polynomials.
- Insert terms in descending exponent order.
- Combine terms with equal exponents.
- Add two polynomials.
- Remove zero-coefficient terms.
- Display polynomial expressions.
- Dynamic memory allocation.
- Menu-driven interface.

## Technologies Used

- Programming Language: C
- Data Structure: Singly Linked List
- Compiler: GCC
- Editor: Visual Studio Code

## Project Structure

Polynomial-Addition-Using-Linked-Lists/
|
|-- main.c
|-- README.md
|-- .gitignore
|
|-- screenshots/
    |-- output.png

## How to Run

### Step 1: Clone the repository

git clone YOUR_REPOSITORY_URL

### Step 2: Open the project folder

cd Polynomial-Addition-Using-Linked-Lists

### Step 3: Compile the program

gcc main.c -o polynomial

### Step 4: Run the program

Windows:
polynomial.exe

Linux / macOS:
./polynomial

## Sample Output

First Polynomial:
5x^3 + 4x^2 - 2x + 7

Second Polynomial:
3x^4 - 5x^3 + 6x - 7

Result:
3x^4 + 4x^2 + 4x

## Algorithm

1. Read two polynomial expressions.
2. Store their terms in linked lists.
3. Sort terms by descending exponent.
4. Compare the exponents of both lists.
5. Add coefficients of equal exponents.
6. Store the resulting terms in a new linked list.
7. Display the final polynomial.

## Time Complexity

Polynomial addition: O(m + n)

Where:
m = Number of terms in first polynomial.
n = Number of terms in second polynomial.

## Applications

- Mathematical computations
- Symbolic algebra
- Engineering calculations
- Sparse polynomial representation

## Contributors

1. Member 1 - Project Documentation
2. Member 2 - PPT Presentation
3. Member 3 - Coding Implementation
4. Member 4 - Coding and Testing
5. Member 5 - Output and Demonstration

## Conclusion

This project demonstrates how linked lists can
be used to represent and add polynomial expressions
efficiently using dynamic memory allocation.
