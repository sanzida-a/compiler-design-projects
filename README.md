# Compiler Tools Repository

This repository contains implementations of fundamental compiler components including lexical analyzers, parsers, and symbol table management. The projects demonstrate various aspects of compiler design using Lex/Yacc and C/C++.

## 📋 Table of Contents

- [Calculator using Lex and Yacc](#Calculator using lex and yacc code)
- [Lexical Analyzer for Pascal Subset](#lexical-analyzer-for-pascal-subset)
- [Symbol Table Implementation](#symbol-table-implementation)
- [Prerequisites](#prerequisites)
- [General Setup](#general-setup)
- [Contributing](#contributing)

## 🎯 Projects Overview

### 1. **Calculator using Lex and Yacc**
A complete calculator implementation that can evaluate arithmetic expressions with variables and assignment operations.

### 2. **Lexical Analyzer for Pascal Subset**
A lexical analyzer that tokenizes Pascal-like code and maintains a symbol table for identifiers.

### 3. **Symbol Table Implementation**
A standalone hash table-based symbol table with full CRUD operations for compiler symbol management.

---

## 🧮 Calculator using Lex and Yacc

### Features
- **Arithmetic Operations**: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- **Parentheses Support**: Proper precedence handling with parentheses
- **Variable Assignment**: Support for both lowercase (a-z) and uppercase (A-Z) variables
- **Expression Evaluation**: Real-time expression parsing and evaluation

### Files
- `calc.l` - Lexical analyzer specification
- `calc.y` - Grammar rules and parser specification  
- `in.txt` - Sample input file with test expressions
- `Readme.md` - Build instructions

### Build and Run
```bash
# Navigate to the calculator directory
cd "Calculator using lex and yacc code"

# Generate lexical analyzer
flex calc.l

# Generate parser
yacc -d calc.y

# Compile the components
g++ -c -w lex.yy.c y.tab.c

# Link and create executable
g++ -o mycalc y.tab.o lex.yy.o

# Run with input file
./mycalc < in.txt > out.txt
```

### Sample Input
```
f = 5+3-2*2 ;
F = (f-1) ;
Y = (f + 3)+12 ;
```

### Sample Output
The calculator will show step-by-step evaluation and final results for each expression.

---

## 🔍 Lexical Analyzer for Pascal Subset

### Features
- **Token Recognition**: Identifies Pascal keywords, operators, identifiers, and literals
- **Symbol Table Integration**: Automatically maintains a hash-based symbol table
- **Comment Handling**: Supports single-line (//) and multi-line (/* */, { }) comments
- **String Literals**: Recognizes double-quoted strings
- **Operator Classification**: Categorizes operators as RELOP, ADDOP, MULOP, etc.

### Supported Tokens
- **Keywords**: program, if, then, else, begin, end, while, do, function, procedure, etc.
- **Operators**: Arithmetic (+, -, *, /), Relational (=, <, >, <=, >=, <>), Assignment (:=)
- **Identifiers**: Variable names following Pascal naming conventions
- **Numbers**: Integer and floating-point numbers with scientific notation
- **Delimiters**: Parentheses, brackets, semicolons, commas, colons

### Files
- `sample.l` - Lexical analyzer specification with symbol table integration
- `in.txt` - Sample Pascal-like code for testing
- `Readme.md` - Build instructions

### Build and Run
```bash
# Navigate to the lexical analyzer directory
cd "Lexical analyzer for a subset of pascal"

# Generate C code from Lex specification
flex -t sample.l > sample.c

# Compile the generated code
g++ -c -o sample.o sample.c

# Link with flex library
g++ -o samp sample.o -ll

# Run with input file
./samp < in.txt > out.txt
```

---

## 🗂️ Symbol Table Implementation

### Features
- **Hash Table Based**: Efficient O(1) average-case operations using hash table
- **Collision Handling**: Uses chaining to handle hash collisions
- **CRUD Operations**: Complete Create, Read, Update, Delete functionality
- **Interactive Menu**: User-friendly command-line interface
- **Flexible Storage**: Stores symbol name and type information

### Operations
1. **Insert**: Add new symbol with name and type
2. **Search**: Find symbol by name and type
3. **Delete**: Remove symbol from table
4. **Display**: Show all symbols in the table
5. **Update**: Modify existing symbol's type

### Files
- `symbolT.cpp` - Complete symbol table implementation with interactive interface

### Build and Run
```bash
# Navigate to the symbol table directory
cd "Symbol Table in C"

# Compile the program
g++ -o symboltable symbolT.cpp

# Run the interactive program
./symboltable
```

### Usage Example
```
Select option:
1 = Insert
2 = Search  
3 = Delete
4 = Show
5 = Update

Enter your choice: 1
Input the data as this following format
Name/Symbol,Type
variable1,int
```

---

## 🛠️ Prerequisites

### Required Software
- **GCC/G++**: C/C++ compiler
- **Flex**: Fast lexical analyzer generator
- **Yacc/Bison**: Parser generator
- **Linux/Unix Environment**: Ubuntu or similar (recommended)

### Installation (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install flex bison gcc g++ build-essential
```

---

## ⚙️ General Setup

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd <repository-name>
   ```

2. **Navigate to desired project directory**
   ```bash
   cd "Calculator using lex and yacc code"
   # or
   cd "Lexical analyzer for a subset of pascal"  
   # or
   cd "Symbol Table in C"
   ```

3. **Follow the specific build instructions** for each project as outlined above

## 📝 Input File Format

Most projects use similar input file formats:
- Statements should end with semicolons (;)
- Variables can be single letters (a-z, A-Z)
- Expressions support standard arithmetic operations
- Assignment uses = for calculator, := for Pascal analyzer

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🔗 Related Topics

- Compiler Design
- Lexical Analysis
- Syntax Analysis  
- Symbol Table Management
- Lex and Yacc Programming
- Hash Table Implementation

---

*For specific questions or issues with individual components, please refer to the respective project directories and their documentation.*
