#include <iostream>
#include <mysql.h>
#include "Class.h"



using namespace std;

void checkChoiceFromMainMenu(int choice);
void loggedUser();
void registerUser();

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
    User user = User();

}







int main()
{

    mainMenu();
    /*MYSQL *mysql;
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, "localhost", "root", "abc123", "Library", 3306, NULL, 0);

    if (mysql)
    {
        
    }*/


}

