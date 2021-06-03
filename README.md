# LibraryManagmentSystem-v1
### Concept
## Assumptions
### The assumptions were to create a console system that would allow:

1. [Admin panel](#admin-panel)
   * [Login](#admin-login)
   * [Add user](#add-user)
   * [Display all users](#display-all-users)
      ** [Display borrowed books for each user](#display-borrowed-books)
   * [Add book](#add-book)
   * [Borrow book](#borrow-book)
   * [Return book](#return-book)
2. [User panel](#user-panel)
   * [Account registrations](#registration-form-user)
   * [Login](#login-page)
   * [Change password](#change-password)
   * [Browse all books](#browse-all-books)
   * [Search for a book](#search-for-a-book)
   * [View the borrowed books](#view-the-borrowed-books)

## Technologies and Dependecies

* C++ language
* MySQL

## Launch
Before starting, you need to install:
* MySQL Community Server
* MySQL Connector/C++
After this you have to update include and lib directories in your IDE.
f.e (your paths can looks different)
```
C\Program Files\MySQL\Connector C++\include
C\Program Files\MySQL\MySQL Server\include
C\Program Files\MySQL\Connector C++\lib\opt
C\Program Files\MySQL\MySQL Server\lib
```
Last step, now you need add two dependencies to your IDE:
```
mysqlcppconn.lib
libmysql.lib
```
Database tables:
```sql
create table Users(id_user int primary key auto_increment, FirstName varchar(50), LastName varchar(50), Email varchar(50), Password varchar(50), PhoneNumber int, Role varchar(100));
insert into USERS(FirstName, LastName, Email, Password, PhoneNumber, Role) values('Roman', 'Nowak', 'roman@wp.pl', '123', '123123123', 'ROLE_ADMIN');
create table Books(id_book int primary key auto_increment, Author varchar(50), YearOfPublishment varchar(50), Title varchar(100), TypeOfBook varchar(100), CountBooks varchar(50));
create table Borrows(id_user int, id_book int, foreign key (id_user) references Users(id_user), foreign key (id_book) references Books(id_book));
```
You can enter data into the tables yourself
