#include <iostream>
#include <mysql.h>
#include "Class.h"
#include <Windows.h>
#include "Validators.h"
#include <string>


using namespace std;

void checkChoiceFromMainMenu(int choice);
void loggedUser();
void registerUser();
void saveUserInDatabase(User user);
void fetchAllBooks();
void checkChoiceFromLoggedUser(int choice);
void borrowBook(int id_book);
bool checkCountOfBook(int id_book);
void mainMenu();
void adminMenu();
void earlyScreen();
void fetchAllUsers();
void saveBook(Book book);
void borrowBookViaAdmin();
void addBook();

int id_user;

MYSQL* connection;
string query;

void signInAdmin()
{   
    string email, password;
    cout << "\n\n";
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----Welcome in Library Managment System - ADMIN----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----                   Sign In                 ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;

    while (email.length() == 0)
    {
        cout << "                                    E-mail: ";
        cin >> email;
    }

    while (password.length() == 0)
    {
        cout << "                                    Password: ";
        cin >> password;
    }

    query = "SELECT * FROM USERS WHERE ROLE='ROLE_ADMIN'";
    mysql_query(connection, query.c_str());

    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row;
        
    while (row = mysql_fetch_row(res))
    {
            
        if (row[3] == email && row[4] == password)
            
        {
                id_user = *row[0] - '0';
                adminMenu();
                return;
                break;
        }
        
    }
    cout << "                 User not found in database..." << endl;
    earlyScreen();
}

void earlyScreen()
{
    cout << "\n\n";
    cout << "                 -------------------------------------------" << endl;
    cout << "                 ----Welcome in Library Managment System----" << endl;
    cout << "                 -------------------------------------------" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----              1) ADMIN             ----" << endl;
    cout << "                 ----              2) USER              ----" << endl;
    cout << "                 ----              3) EXIT              ----" << endl;
    cout << "                 -------------------------------------------" << endl;
    

    int choice = 0;
    while (choice != 1 &&  choice != 2 && choice != 3)
    {
        cout << "                 >> ";
        cin >> choice;
    }

    switch (choice)
    {   
        case 1:
            signInAdmin();
            break;

        case 2:
            mainMenu();
            break;
        case 3:
            break;
    }
}

void adminMenu()
{
    cout << "\n\n";
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----Welcome in Library Managment System - ADMIN----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----               1) Add user                 ----" << endl;
    cout << "                 ----               2) Display all users        ----" << endl;
    cout << "                 ----               3) Add book                 ----" << endl;
    cout << "                 ----               4) Borrow book              ----" << endl;
    cout << "                 ----               5) Return book              ----" << endl;
    cout << "                 ----               6) Logout                   ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;

    int choice = 0;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
    {
        cout << "                 >> ";
        cin >> choice;
    }

    switch (choice)
    {
    case 0:
        earlyScreen();
        break;
    case 1:
        registerUser();
        break;
    case 2:
        fetchAllUsers();
        cout << "                 Type 'b' to back" << endl;
        char choice;
        cout << "                 >> ";
        cin >> choice;
        while (choice != 'b')
        {
            cout << "                 Type 'b' to back" << endl;
            cout << "                 >> ";
            cin >> choice;
        }
        adminMenu();
        break;
    case 3:
        addBook();
        break;
    case 4:
        borrowBookViaAdmin();
        break;
    case 5:
        
        break;
    case 6:
        earlyScreen();
        break;
    }
}

bool checkIdUser(char user_id)
{
    query = "SELECT EXISTS(SELECT * FROM USERS WHERE ID_USER = '" + to_string(user_id-'0') + "')";
    mysql_query(connection, query.c_str());
    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row = mysql_fetch_row(res);

    if (*row[0] == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkIdBook(char book_id)
{
    query = "SELECT EXISTS(SELECT * FROM BOOKS WHERE ID_BOOK = '"+to_string(book_id-'0')+"')";
    mysql_query(connection, query.c_str());
    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row = mysql_fetch_row(res);
    
    if (*row[0] == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void borrowBookViaAdmin()
{
    fetchAllUsers();
    cout << endl;
    cout << "                 If you want back type 'b'" << endl;
    cout << "                 Choose user by id" << endl;
    cout << "                 >> ";
    char user_id;
    cin >> user_id;
    while (!isdigit(user_id) || !checkIdUser(user_id))
    {
        if (user_id == 'b')
        {
            adminMenu();
            break;
            return;
        }
        cout << "                 Choice user by id" << endl;
        cout << "                 >> ";
        cin >> user_id;
    }

    query = "SELECT * FROM BOOKS";
    mysql_query(connection, query.c_str());
    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row;
    cout << endl;
    CHECK:while (row = mysql_fetch_row(res))
    {
        cout << "                 " << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << " " << row[6] << endl;
    }
    cout << endl;
    cout << "                 Now choose book which user want to borrow by id" << endl;
    cout << "                 >> ";
    char book_id;
    cin >> book_id;
    while (!isdigit(book_id) || !checkIdBook(book_id))

    {
        if (book_id == 'b')
        {
            adminMenu();
            break;
            return;
        }
        cout << "                 Choose book which user want to borrow by id" << endl;
        cout << "                 >> ";
        cin >> book_id;
        
        
    }
        query = "SELECT COUNTBOOKS FROM BOOKS WHERE ID_BOOK = '" + to_string(book_id - '0') + "'";
        mysql_query(connection, query.c_str());
        MYSQL_RES* r = mysql_store_result(connection);
        MYSQL_ROW rw = mysql_fetch_row(r);

        if (*rw[0] == '0')
        {
            cout << "                 No copy in stock" << endl;
            goto CHECK;
        }
        cout << endl;
        cout << "                 Borrowing a book..." << endl;
    query = "INSERT INTO BORROWS VALUES('" + to_string(user_id-'0') + "', '" + to_string(book_id-'0') + "')";
    mysql_query(connection, query.c_str());
    query = "UPDATE BOOKS SET COUNTBOOKS = COUNTBOOKS-1 WHERE ID_BOOK = '" + to_string(book_id - '0') + "'";
    mysql_query(connection, query.c_str());
    adminMenu();
}

void addBook()
{
    string author, title, typeOfBook, yearOfPublishment, countBook;
    cout << "                                 Author: ";
    cin.ignore();
    getline(cin, author);
    cout << "                                 Year Of Publishment (f.e 1874): ";
    getline(cin, yearOfPublishment);
    cout << "                                 Title: ";
    getline(cin, title);
    cout << "                                 Type of book: ";
    getline(cin, typeOfBook);
    cout << "                                 Number of copies: ";
    getline(cin, countBook);

    Book book = Book(author, yearOfPublishment, title, typeOfBook, countBook);
    //book.rep_str();
    saveBook(book);
}

void saveBook(Book book)
{
    query = "INSERT INTO BOOKS(author, yearOfPublishment, title, typeOfBook, countBooks) VALUES('" + book.getAuthor() + "', '"+book.getYearOfPublishment()+"', '" + book.getTitle() + "', '" + book.getTypeOfBook() + "', '"+book.getCountBooks()+"')";
    mysql_query(connection, query.c_str());
    cout << endl;
    cout << "                                 Book added to database..." << endl;
    cout << endl;   
    adminMenu();
}

void fetchAllUsers()
{
    query = "SELECT * FROM USERS";
    mysql_query(connection, query.c_str());

    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row;
    cout << "USERS " << endl;
    while (row = mysql_fetch_row(res))
    {
        cout << "                 " << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[5] << " " << row[6] << endl;
    }
}

void mainMenu()
{   
    cout << "\n\n";
    cout << "                 -------------------------------------------" << endl;
    cout << "                 ----Welcome in Library Managment System----" << endl;
    cout << "                 -------------------------------------------" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----            1) Sign In             ----" << endl;
    cout << "                 ----            2) Sign Up             ----" << endl;
    cout << "                 ----            3) Change password     ----" << endl;
    cout << "                 ----            4) Exit                ----" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 ----                                   ----" << endl;
    cout << "                 -------------------------------------------" << endl;
    
    int answer;
    cout << "                 '0' to back" << endl;
    cout << "                 >> ";
    cin >> answer;
    if (answer == 0)
    {
        earlyScreen();
    }
    else
    {
        checkChoiceFromMainMenu(answer);
    }
    
}

void connectToDatabase()
{
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, "localhost", "root", "abc123", "Library", 3306, NULL, 0);
}

bool authenticate(string email, string password)
{   
    query = "SELECT * FROM USERS WHERE ROLE = 'ROLE_USER'";
    const char* q = query.c_str();
    int qstate = mysql_query(connection, q);
    if (!qstate)
    {
        MYSQL_RES* res = mysql_store_result(connection);
        MYSQL_ROW row;
        while (row = mysql_fetch_row(res))
        {
            if (row[3] == email && row[4] == password)
            {   
                id_user = *row[0] - '0';
                return true;
            }
        }
    }
    return false;
}

void signIn() {
    system("CLS");
    string email, password;
    cout << "\n\n";
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----    Welcome in Library Managment System    ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----                  Sign In                  ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
   
    while (email.length() == 0)
    {
        cout << "                                       E-mail: ";
        cin >> email;
    }

    while (password.length() == 0)
    {
        cout << "                                       Password: ";
        cin >> password;
    }

    bool result = authenticate(email, password);

    if (result)
    {
        loggedUser();
    }
    else
    {   
        cout << "\n                      User not found in database...";
        mainMenu();
    }


}


void checkChoiceFromMainMenu(int choice) 
{
    switch (choice) 
    {
        case 1:
            signIn();
            break;
        case 2:
            registerUser();
            break;
        case 3:
            cout << "Zmiana hasła" << endl;
            break;
    }
}

void loggedUser() 
{
    cout << "\n\n";
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----    Welcome in Library Managment System    ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----            1) Browse all books            ----" << endl;
    cout << "                 ----            2) Search for a book           ----" << endl;
    cout << "                 ----            3) View the borrowed books     ----" << endl;
    cout << "                 ----            4) Logout                      ----" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ----                                           ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;

    int choice;
    cout << "                 >> ";
    cin >> choice;
    checkChoiceFromLoggedUser(choice);
}
void searchBookByName()
{
    string name;
    
    cout << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----               Searching Book              ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 >> ";

    /*cin >> name;*/
    cin.ignore();
    getline(cin, name);
    query = "SELECT EXISTS(SELECT * FROM BOOKS WHERE TITLE = '" + name + "')";
    mysql_query(connection, query.c_str());
    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row = mysql_fetch_row(res);
   
    if (*row[0] == '1')
    {
        query = "SELECT * FROM BOOKS WHERE TITLE = '" + name + "'";
        mysql_query(connection, query.c_str());
        MYSQL_RES* res = mysql_store_result(connection);
        MYSQL_ROW row = mysql_fetch_row(res);

        cout << "ID: " << row[0] << endl;
        char choice;
        cout << "                 Book found " << endl;
        cout << "                 If you want borrow this book type 'y' if you want back to main menu type 'b'" << endl;
        cout << "                 ---------------------------------------------------" << endl;
        cout << "                 >> ";
        cin >> choice;

        if (choice == 'y')
        {
            borrowBook(*row[0] - '0');
            loggedUser();
        }
        else if (choice == 'b')
        {
            loggedUser();
        }
    }
    else
    {
        char choice;
        cout << "                 Book not found..." << endl;
        cout << "                 If you want search again type 'y' if you want back to main menu type 'b'" << endl;
        cout << "                 ---------------------------------------------------" << endl;
        cout << "                 >> ";
        cin >> choice;

        if (choice == 'y')
        {
            searchBookByName();
        }
        else if (choice == 'b')
        {
            loggedUser();
        }
    }


}

void viewAllBorrowsBooks()
{
    query = "select Borrows.id_user, Books.* from (Borrows inner join Books ON Borrows.id_book = Books.id_book) where Borrows.id_user = "+to_string(id_user)+"";
    mysql_query(connection, query.c_str());

    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row;

    cout << endl;
    while (row = mysql_fetch_row(res))
    {
        cout << "                 " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << endl;
    }
    char choice = 'n';
    while (choice != 'b')
    {
        cout << "                 Type 'b' to back to main menu" << endl;
        cout << "                 >> ";
        cin >> choice;
    }
    loggedUser();
}

void checkChoiceFromLoggedUser(int choice)
{
    switch (choice)
    {
        case 1:
            fetchAllBooks();
            break;
        case 2:
            searchBookByName();
            break;
        case 3:
            viewAllBorrowsBooks();
            break;
        case 4:
            mainMenu();
            break;
    }
}

void fetchAllBooks()
{
    query = "SELECT * FROM BOOKS";

    const char* q = query.c_str();
    int qstate = mysql_query(connection, q);
    
    if (qstate == 0) {
        MYSQL_RES* res = mysql_store_result(connection);
        MYSQL_ROW row;
        int i = 0;
        while (row = mysql_fetch_row(res))
        {
            cout << "                 " << i+1 << ") "  << row[1] << " " << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << endl;
            i++;
        }
        cout << endl;
        cout << "               If you want to borrow type number of book otherwise press 'b' to back to menu" << endl;
        cout << "                 >> ";
        char choice;
        cin >> choice;
        while ((choice - '0' > i || choice - '0' < 0)) 
        {
            if (choice == 'b')
            {   
                loggedUser();
                break;
            }
            cout << "                 >> ";
            cin >> choice;
        }
        if (checkCountOfBook(choice - '0'))
        {
            cout << "                 Book available..." << endl;
            borrowBook(choice - '0');
            fetchAllBooks();
        }
        else
        {   
            cout << "                 Book not available " << endl;
            fetchAllBooks();
        }
    }
}

bool checkCountOfBook(int id_book)
{
    query = "SELECT * FROM BOOKS WHERE ID_BOOK = '"+to_string(id_book)+"'";
    mysql_query(connection, query.c_str());

    MYSQL_RES* res = mysql_store_result(connection);
    MYSQL_ROW row = mysql_fetch_row(res);
    if ((int) row[5] > 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void borrowBook(int id_book)
{
    query = "INSERT INTO BORROWS(id_user, id_book) VALUES('"+to_string(id_user)+"', '"+to_string(id_book)+"')";
    mysql_query(connection, query.c_str());

    query = "UPDATE BOOKS SET COUNTBOOKS = COUNTBOOKS - 1 WHERE ID_BOOK = '"+to_string(id_book)+"'";
    mysql_query(connection, query.c_str());
}

void registerUser() 
{
    system("CLS");
    string firstName, lastName, email, password, phoneNumber;
    cout << "\n\n";
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----    Welcome in Library Managment System    ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;
    cout << "                 ----                Registration               ----" << endl;
    cout << "                 ---------------------------------------------------" << endl;

    while (checkNames(firstName) != true) {
        cout << "                               First name: ";
        cin >> firstName;
    }

    while (checkNames(lastName) != true) {
        cout << "                               Last name: ";
        cin >> lastName;
    }

    while (checkEmail(email) != true) {
        cout << "                               E-mail: ";
        cin >> email;
    }

    while (checkPassword(password) != true) {
        cout << "                               Password: ";
        cin >> password;
    }

    while (checkPhoneNumber(phoneNumber) != true) {
        cout << "                               Phone number: ";
        cin >> phoneNumber;
    }
    
    User user = User(firstName, lastName, email, password, phoneNumber);
    saveUserInDatabase(user);
}

void saveUserInDatabase(User user) 
{
    cout << "\n\n";

    cout << "                 Checking the connection.\n";
    Sleep(2500);
    cout << "                 Checking the connection..\n";
    Sleep(1800);
    cout << "                 Checking the connection...\n";
    Sleep(800);

    if (connection)
    {   
        // simulate delay 
        cout << "\n\n";
        cout << "                 Connection established" << endl;
        Sleep(5000);
        //system("CLS");
        cout << "                 I add the record, one more moment" << endl;
        Sleep(2000);
        cout << "                 I am finishing" << endl;
        Sleep(1000);
        cout << "                 Done" << endl;
        Sleep(900);
        system("CLS");

        query = "INSERT INTO USERS(FirstName, LastName, Email, Password, PhoneNumber, Role) VALUES('"+user.getFirstName()+"', '"+user.getLastName()+"', '"+user.getEmail()+"', '"+user.getPassword()+"', '"+user.getPhoneNumber()+"', '"+user.getRole()+"')";
        mysql_query(connection, query.c_str());
        signIn();
    }
}




int main()
{
    connectToDatabase();
    earlyScreen();
}

