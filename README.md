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
