#include <iostream>
#include <string>
using namespace std;

// 2D array to store library data
const int MAX_BOOKS = 20;
const int MAX_TITLE_LENGTH = 50;B
string books[MAX_BOOKS][MAX_TITLE_LENGTH];

// Function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to trim whitespace from a string
string trim(const string& str) {
    string trimmedStr;
    for (char c : str) {
        if (!isspace(c)) {
            trimmedStr += c;
        }
    }
    return trimmedStr;
}

// Main menu function
void displayMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add a new book\n";
    cout << "2. Display all books\n";
    cout << "3. Search for a book by title\n";
    cout << "4. Check out a book\n";
    cout << "5. Return a book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    int bookCount = 0;
    int choice;
    bool running = true;

    cout << "Welcome to the Library Management System!\n";

    while (running) {
        displayMenu();
        
        // Get user choice with input validation
        if (!(cin >> choice)) {
            cout << "Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();  // Clear input buffer for subsequent input
        
        // Process user choice
        switch (choice) {
            case 1: {  // Add a new book
                if (bookCount < MAX_BOOKS) {
                    string title;
                    cout << "Enter book title: ";
                    getline(cin, title);
                    books[bookCount][0] = trim(title);
                    bookCount++;
                } else {
                    cout << "The library is full and cannot add more books.\n";
                }
                break;
            }
            case 2: {  // Display all books
                if (bookCount == 0) {
                    cout << "\n===== Library Inventory =====\n";
                    cout << "The library is empty please add some books.\n";
                } else {
                    cout << "\n===== Library Inventory =====\n";
                    for (int i = 0; i < bookCount; ++i) {
                        cout << "\nBook #" << (i + 1) << ": " << books[i][0] << "\n";
                    }
                    cout << "----------------------------\n";
                }
                break;
            }
            case 3: {  // Search by title
                string searchTitle;
                cout << "Enter title to search: ";

                // Use getline to get the entire line of input, including spaces
                // This is necessary because cin will only get up to the first space
                // and then stop, which is not what we want when searching for a title
                getline(cin, searchTitle);
   
                bool found = false;
                cout << "\n===== Search Results =====\n";
                
                for (int i = 0; i < bookCount; ++i) {
                    string title = books[i][0];
                    transform(title.begin(), title.end(), title.begin(), ::tolower);
                    
                    string search = searchTitle;
                    transform(search.begin(), search.end(), search.begin(), ::tolower);
                    
                    if (title.find(search) != string::npos) {
                        cout << "\nBook #" << (i + 1) << ": " << books[i][0] << "\n";
                        found = true;
                    }
                }
                
                if (!found) {
                    cout << "No books found matching that title.\n";
                }
                break;
            }
            case 4: {  // Check out a book
                if (bookCount > 0) {
                    cout << "Enter the book number to check out: ";
                    int bookIndex;
                    cin >> bookIndex;
                    clearInputBuffer();
                    
                    if (bookIndex >= 1 && bookIndex <= bookCount) {
                        cout << "Book \"" << books[bookIndex - 1][0] << "\" has been checked out.\n";
                    } else {
                        cout << "Invalid book number.\n";
                    }
                } else {
                    cout << "There are no books in the library.\n";
                }
                break;
            }
            case 5: {  // Return a book
                if (bookCount > 0) {
                    cout << "Enter the book number to return: ";
                    int bookIndex;
                    cin >> bookIndex;
                    clearInputBuffer();
                    
                    if (bookIndex >= 1 && bookIndex <= bookCount) {
                        cout << "Book \"" << books[bookIndex - 1][0] << "\" has been returned.\n";
                    } else {
                        cout << "Invalid book number.\n";
                    }
                } else {
                    cout << "There are no books in the library.\n";
                }
                break;
            }
            case 6:  // Exit
                cout << "Thank you for using the Library Management System. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}