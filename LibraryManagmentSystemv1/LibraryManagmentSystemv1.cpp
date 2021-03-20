#include <iostream>
#include <mysql.h>
#include "Class.h"
#include <Windows.h>
#include "Validators.h"


using namespace std;

void checkChoiceFromMainMenu(int choice);
void loggedUser();
void registerUser();
void saveUserInDatabase(User user);


MYSQL* connection;


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

    cout << "                 >> ";
    cin >> answer;
    checkChoiceFromMainMenu(answer);
}

void connecToDatabase()
{
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, "localhost", "root", "abc123", "Library", 3306, NULL, 0);
}

bool authenticate(string email, string password)
{   
    string querry = "SELECT * FROM USERS";
    const char* q = querry.c_str();
    int qstate = mysql_query(connection, q);
    if (!qstate)
    {
        MYSQL_RES* res = mysql_store_result(connection);
        MYSQL_ROW row;
        while (row = mysql_fetch_row(res))
        {
            if (row[3] == email && row[4] == password)
            {   
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



void checkChoiceFromMainMenu(int choice) {
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



void loggedUser() {
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
}

void registerUser() {
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

void saveUserInDatabase(User user) {
    MYSQL *connection;
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, "localhost", "root", "abc123", "Library", 3306, NULL, 0);
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

        string query = "INSERT INTO USERS(FirstName, LastName, Email, Password, PhoneNumber) VALUES('"+user.getFirstName()+"', '"+user.getLastName()+"', '"+user.getEmail()+"', '"+user.getPassword()+"', '"+user.getPhoneNumber()+"')";
        cout << query;
        mysql_query(connection, query.c_str());
    }
}







int main()
{
    connecToDatabase();
    mainMenu();
    


}

