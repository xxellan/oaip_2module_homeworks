//1 task (структуры)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string name;
    int age;
    string position;
    double salary;
};

int main() {
    cout << "Employee records\n" << endl;

    int count;
    cout << "Enter number of employees: ";
    cin >> count;
    cin.ignore();

    vector<Employee> employees(count);
    double totalSalary = 0;

    for (int i = 0; i < count; i++) {
        cout << "\nEnter data for employee " << (i + 1) << ":\n";

        cout << "Enter employee name: ";
        getline(cin, employees[i].name);

        cout << "Enter employee age: ";
        cin >> employees[i].age;
        cin.ignore();

        cout << "Enter employee position: ";
        getline(cin, employees[i].position);

        cout << "Enter employee salary: ";
        cin >> employees[i].salary;
        cin.ignore();

        totalSalary += employees[i].salary;
    }

    int youngestIndex = 0;
    int oldestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (employees[i].age < employees[youngestIndex].age) {
            youngestIndex = i;
        }
        if (employees[i].age > employees[oldestIndex].age) {
            oldestIndex = i;
        }
    }

    cout << "\nResults:\n";
    cout << "Youngest employee: "
        << employees[youngestIndex].name
        << ", age: " << employees[youngestIndex].age
        << ", position: " << employees[youngestIndex].position
        << ", salary: " << employees[youngestIndex].salary << endl;

    cout << "Oldest employee: "
        << employees[oldestIndex].name
        << ", age: " << employees[oldestIndex].age
        << ", position: " << employees[oldestIndex].position
        << ", salary: " << employees[oldestIndex].salary << endl;

    cout << "Average salary of all employees: "
        << (totalSalary / count) << endl;

    return 0;
}


//2 task
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BankAccount {
    string accountNumber;
    string ownerName;
    double balance;
};

int findAccountByNumber(const vector<BankAccount>& accounts, const string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << "Bank Account System\n" << endl;

    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\nChoose an action:\n";
        cout << "1. Create a new bank account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Show account information\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            BankAccount newAccount;

            cout << "Enter account number: ";
            getline(cin, newAccount.accountNumber);

            if (findAccountByNumber(accounts, newAccount.accountNumber) != -1) {
                cout << "An account with this number already exists!\n";
                break;
            }

            cout << "Enter owner's name: ";
            getline(cin, newAccount.ownerName);

            newAccount.balance = 0.0;
            accounts.push_back(newAccount);

            cout << "Bank account created.\n";
            break;
        }

        case 2: {
            string accountNumber;
            double amount;

            cout << "Enter account number for deposit: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "Account not found!\n";
                break;
            }

            cout << "Enter deposit amount: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "Amount must be positive!\n";
                break;
            }

            accounts[index].balance += amount;
            cout << "Account credited with " << amount << " units.\n";
            break;
        }

        case 3: {
            string accountNumber;
            double amount;

            cout << "Enter account number for withdrawal: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "Account not found!\n";
                break;
            }

            cout << "Enter withdrawal amount: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "Amount must be positive!\n";
                break;
            }

            if (accounts[index].balance < amount) {
                cout << "Insufficient funds!\n";
                cout << "Available: " << accounts[index].balance << " units\n";
                break;
            }

            accounts[index].balance -= amount;
            cout << amount << " units withdrawn from the account.\n";
            break;
        }

        case 4: {
            string accountNumber;

            cout << "Enter account number to view information: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "Account not found!\n";
                break;
            }

            cout << "\nAccount information:\n";
            cout << "Account number: " << accounts[index].accountNumber << "\n";
            cout << "Owner name: " << accounts[index].ownerName << "\n";
            cout << "Balance: " << accounts[index].balance << " units\n";
            break;
        }

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}


//3 task
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

void addBook(vector<Book>& library) {
    Book newBook;

    cout << "Enter book title: ";
    getline(cin, newBook.title);

    cout << "Enter book author: ";
    getline(cin, newBook.author);

    cout << "Enter year of publication: ";
    cin >> newBook.year;
    cin.ignore();

    cout << "Enter book genre: ";
    getline(cin, newBook.genre);

    library.push_back(newBook);
    cout << "Book '" << newBook.title << "' added to the library.\n";
}

void removeBook(vector<Book>& library, const string& title) {
    for (size_t i = 0; i < library.size(); i++) {
        if (library[i].title == title) {
            cout << "Book '" << library[i].title << "' removed from the library.\n";
            library.erase(library.begin() + i);
            return;
        }
    }
    cout << "Book with title '" << title << "' not found.\n";
}

void findBooksByAuthor(const vector<Book>& library, const string& author) {
    bool found = false;
    cout << "\nBooks by '" << author << "':\n";

    for (const auto& book : library) {
        if (book.author == author) {
            cout << "  - " << book.title
                << " (" << book.year
                << ", " << book.genre << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No books by this author found.\n";
    }
}

void displayAllBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "The library is empty.\n";
        return;
    }

    cout << "\nAll books in the library (" << library.size() << " books):\n";
    for (size_t i = 0; i < library.size(); i++) {
        cout << i + 1 << ". '" << library[i].title
            << "' - " << library[i].author
            << " (" << library[i].year
            << ", " << library[i].genre << ")\n";
    }
}

int main() {
    cout << "Library System\n" << endl;

    vector<Book> library;
    int choice;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Remove a book by title\n";
        cout << "3. Find books by author\n";
        cout << "4. Show all books\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBook(library);
            break;

        case 2: {
            string title;
            cout << "Enter book title to remove: ";
            getline(cin, title);
            removeBook(library, title);
            break;
        }

        case 3: {
            string author;
            cout << "Enter author to search for: ";
            getline(cin, author);
            findBooksByAuthor(library, author);
            break;
        }

        case 4:
            displayAllBooks(library);
            break;

        case 5:
            cout << "Exiting library program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}


//1 task (обьединения)
#include <iostream>
using namespace std;

union Variant {
    int intValue;
    double doubleValue;
    char charValue;
};

int main() {
    cout << "Storing different data types\n" << endl;

    Variant data;
    char typeChoice;

    cout << "Choose data type:\n";
    cout << "i - integer (int)\n";
    cout << "d - floating-point number (double)\n";
    cout << "c - character (char)\n";
    cout << "Your choice: ";
    cin >> typeChoice;

    switch (typeChoice) {
    case 'i':
    case 'I':
        cout << "Enter integer value: ";
        cin >> data.intValue;
        cout << "You entered integer: " << data.intValue << endl;
        break;

    case 'd':
    case 'D':
        cout << "Enter floating-point value: ";
        cin >> data.doubleValue;
        cout << "You entered floating-point number: " << data.doubleValue << endl;
        break;

    case 'c':
    case 'C':
        cout << "Enter character: ";
        cin >> data.charValue;
        cout << "You entered character: '" << data.charValue << "'" << endl;
        break;

    default:
        cout << "Invalid data type selection.\n";
        break;
    }

    cout << "\nSize of union Variant: " << sizeof(Variant) << " bytes" << endl;
    cout << "This is the maximum size among int, double, and char types." << endl;

    return 0;
}


//2 task
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

union ShapeData {
    struct {
        double radius;
    } circle;

    struct {
        double length;
        double width;
    } rectangle;
};

enum ShapeType { CIRCLE, RECTANGLE };

int main() {
    cout << "Geometric Shape Manager\n" << endl;

    ShapeData shapeData;
    ShapeType type;
    int choice;

    cout << "Choose a shape:\n";
    cout << "1 - Circle\n";
    cout << "2 - Rectangle\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        type = CIRCLE;
        cout << "Enter circle radius: ";
        cin >> shapeData.circle.radius;

        if (shapeData.circle.radius <= 0) {
            cout << "Error: radius must be a positive number!\n";
            return 1;
        }

        double area = M_PI * shapeData.circle.radius * shapeData.circle.radius;
        cout << "Circle area: " << fixed << setprecision(2)
            << area << endl;

        double circumference = 2 * M_PI * shapeData.circle.radius;
        cout << "Circle circumference: " << circumference << endl;
        break;
    }

    case 2: {
        type = RECTANGLE;
        cout << "Enter rectangle length: ";
        cin >> shapeData.rectangle.length;
        cout << "Enter rectangle width: ";
        cin >> shapeData.rectangle.width;

        if (shapeData.rectangle.length <= 0 || shapeData.rectangle.width <= 0) {
            cout << "Error: length and width must be positive numbers!\n";
            return 1;
        }

        double area = shapeData.rectangle.length * shapeData.rectangle.width;
        cout << "Rectangle area: " << area << endl;

        double perimeter = 2 * (shapeData.rectangle.length + shapeData.rectangle.width);
        cout << "Rectangle perimeter: " << perimeter << endl;
        break;
    }

    default:
        cout << "Invalid shape selection.\n";
        return 1;
    }

    cout << "\nData structure information:\n";
    cout << "Size of union ShapeData: " << sizeof(ShapeData) << " bytes" << endl;
    cout << "A union stores only one set of data at a time (circle or rectangle)." << endl;

    return 0;
}


//3 task
#include <iostream>
#include <iomanip>

using namespace std;

union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    } components;

    int allComponents[6];
};

bool isValidDate(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth;
    switch (month) {
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    return day <= daysInMonth;
}

bool isValidTime(int hour, int minute, int second) {
    return (hour >= 0 && hour <= 23) &&
           (minute >= 0 && minute <= 59) &&
           (second >= 0 && second <= 59);
}

int main() {
    cout << "Date and Time Storage\n" << endl;

    DateTime dt;

    cout << "Enter year: ";
    cin >> dt.components.year;

    cout << "Enter month (1-12): ";
    cin >> dt.components.month;

    cout << "Enter day: ";
    cin >> dt.components.day;

    if (!isValidDate(dt.components.year, dt.components.month, dt.components.day)) {
        cout << "Error: invalid date!\n";
        return 1;
    }

    cout << "Enter hour (0-23): ";
    cin >> dt.components.hour;

    cout << "Enter minute (0-59): ";
    cin >> dt.components.minute;

    cout << "Enter second (0-59): ";
    cin >> dt.components.second;

    if (!isValidTime(dt.components.hour, dt.components.minute, dt.components.second)) {
        cout << "Error: invalid time!\n";
        return 1;
    }

    cout << "\nResults:\n";

    cout << "Date and time: "
        << dt.components.year << "-"
        << setw(2) << setfill('0') << dt.components.month << "-"
        << setw(2) << setfill('0') << dt.components.day << " "
        << setw(2) << setfill('0') << dt.components.hour << ":"
        << setw(2) << setfill('0') << dt.components.minute << ":"
        << setw(2) << setfill('0') << dt.components.second << endl;

    cout << "Text format: ";
    cout << dt.components.day << "."
         << dt.components.month << "."
         << dt.components.year << " "
         << dt.components.hour << ":"
         << dt.components.minute << ":"
         << dt.components.second << endl;

    cout << "\nArray representation: ";
    for (int i = 0; i < 6; i++) {
        cout << dt.allComponents[i];
        if (i < 5) cout << ", ";
    }
    cout << endl;

    cout << "\nData structure information:\n";
    cout << "Size of union DateTime: " << sizeof(DateTime) << " bytes" << endl;
    cout << "All components share the same memory area." << endl;

    return 0;
}