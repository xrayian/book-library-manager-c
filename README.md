# Library Management System - C Program

## Version 0.2

This is a C program for managing a library. It allows users to add new books, issue and return books, view book lists, and save library data to a file.

### Features

- Add new books to the library
- Issue books to patrons
- Return books
- View a list of all books or available books only
- Save library data to a file
- Load library data from a file (on startup, or if the file doesn't exist, creates a new library with some seed data)

### Usage

1. Compile the program using a C compiler (e.g., gcc library_management.c -o library_manager)
2. Run the program (e.g., ./library_manager)
3. Follow the on-screen prompts to interact with the library management system

### User Interface

The program uses a simple text-based menu to allow users to select the desired operation. Valid options are:

- `A/a` - Add a new book 📚
- `I/i` - Issue a book 📤
- `R/r` - Return a book 📥
- `L/l` - List books (shows all books by default, use 'l' for available books only) 📜
- `S/s` - Save library data 🗄️
- `E/e` - Exit the program 🚪

### Seed Data

The program includes a preset list of 30 books loaded if no library data file is found.

### Contributing

This is an open-source project. Feel free to clone the repository, make changes, and submit pull requests!
