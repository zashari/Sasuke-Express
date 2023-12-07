# First Semester Project: Sasuke Express

### Introduction

This C program is a customer management system for a hypothetical company named "SASUKE-EXPRESS". It is a my assignment for my first-year of college, showcasing basic programming skills in C. The program provides functionalities to add, delete, search, edit, and display customer data, using file handling to store and retrieve data.

### Program Overview

1. **Data Structure**:
   - A `customer` structure is defined with fields for the customer's phone number, name, and address.

2. **Functionality**:
   - `add()`: Adds new customers to the system.
   - `delete_data()`: Deletes a customer's data based on the name.
   - `search()`: Searches for a customer's data by name and displays it.
   - `display()`: Displays all customer data in the system.
   - `edit()`: Edits an existing customer's data.

3. **File Handling**:
   - The program uses a text file (`cdata.txt`) to store and manage customer data.

4. **User Interface**:
   - A command-line interface allows the user to choose among various functionalities.

### Key Functionalities and Code Analysis

1. **Adding Customers (`add`)**:
   - Uses dynamic memory allocation with `calloc` for creating an array of customers.
   - Takes user input for multiple customers and writes their data to `cdata.txt`.

2. **Deleting Customers (`delete_data`)**:
   - Reads customer data from `cdata.txt` and writes all except the specified customer to `temp.txt`.
   - The data from `temp.txt` is then written back to `cdata.txt`, effectively removing the specified customer.

3. **Searching for a Customer (`search`)**:
   - Reads data from `cdata.txt` and matches the input name to display the relevant customer's details.

4. **Editing Customer Data (`edit`)**:
   - Works similarly to `delete_data`, but modifies the specified customer's data before writing it back to the file.

5. **Displaying All Customers (`display`)**:
   - Reads and displays all customer data from `cdata.txt`.

### Improvements

1. **Memory Leak Prevention**: Ensure proper management of dynamically allocated memory to prevent leaks.
2. **Input Validation**: Adding checks to validate user inputs for data integrity.
3. **Error Handling**: Include error handling for file operations and user inputs.
4. **User Experience**: Improve user interface design for better user experience and clarity.
5. **Modularity**: Refactor repetitive code segments into separate functions to enhance code readability and reusability.

### Conclusion

This C program effectively demonstrates the use of file handling, structures, and basic user interface design in C. It is a solid foundation for my first-year college assignment, showing essential programming skills. With additional features and improvements, this program could be developed into a more robust customer management system.
