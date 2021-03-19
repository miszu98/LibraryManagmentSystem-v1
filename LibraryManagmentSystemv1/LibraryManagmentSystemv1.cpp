#include <iostream>
#include <mysql.h>
#include "Class.h"
#include <Windows.h>


using namespace std;

void checkChoiceFromMainMenu(int choice);
void loggedUser();
void registerUser();
void saveUserInDatabase(User user);

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


void checkChoiceFromMainMenu(int choice) {
    switch (choice) 
    {
        case 1:
            loggedUser();
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
    cout << "                               First name: ";
    cin >> firstName;
    cout << "                               Last name: ";
    cin >> lastName;
    cout << "                               E-mail: ";
    cin >> email;
    cout << "                               Password: ";
    cin >> password;
    cout << "                               Phone number: ";
    cin >> phoneNumber;

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
    //system("CLS");
    cout << "                 Checking the connection..\n";
    Sleep(1800);
    //system("CLS");
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

    mainMenu();
    


}

