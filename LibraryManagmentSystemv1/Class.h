
#include <iostream>

using namespace std;

class User {
	private:
		string firstName;
		string lastName;
		string email;
		string password;
		string phoneNumber;
		string role;

	public: 
		string getFirstName() {
			return firstName;
		}
		string getLastName() {
			return lastName;
		}
		string getEmail() {
			return email;
		}
		string getPassword() {
			return password;
		}
		string getPhoneNumber() {
			return phoneNumber;
		}
		string getRole() {
			return role;
		}

		void setFirstName(string value) {
			firstName = value;
		}
		void setLastName(string value) {
			lastName = value;
		}
		void setEmail(string value) {
			email = value;
		}
		void setPassword(string value) {
			password = value;
		}
		void setPhoneNumber(string value) {
			phoneNumber = value;
		}
		void setRole(string value) {
			role = value;
		}

		User() {

		}

		User(string _firstName, string _lastName, string _email, string _password, string _phoneNumber) {
			setFirstName(_firstName);
			setLastName(_lastName);
			setEmail(_email);
			setPassword(_password);
			setPhoneNumber(_phoneNumber);
			setRole("ROLE_USER");
		}
};

class Book {
	private:
		string author;
		string yearOfPublishment;
		string title;
		string typeOfBook;
		string countBooks;

	public:
		string getAuthor() {
			return author;
		}
		string getYearOfPublishment() {
			return yearOfPublishment;
		}
		string getTitle() {
			return title;
		}
		string getTypeOfBook() {
			return typeOfBook;
		}
		string getCountBooks() {
			return countBooks;
		}

		void setAuthor(string value) {
			author = value;
		}
		void setYearOfPublishment(string value) {
			yearOfPublishment = value;
		}
		void setTitle(string value) {
			title = value;
		}
		void setTypeOfBook(string value) {
			typeOfBook = value;
		}
		void setCountBook(string value) {
			countBooks = value;
		}

		void rep_str()
		{
			cout << "Author: " << getAuthor() << endl;
			cout << "YearOfPublishment: " << getYearOfPublishment() << endl;
			cout << "Title: " << getTitle() << endl;
			cout << "TypeOfBook: " << getTypeOfBook() << endl;
			cout << "CountBooks: " << getCountBooks() << endl;
		}

		Book() {

		}

		Book(string _author, string _yearOfPublishment, string _title, string _typeOfBook, string _countBooks) {
			setAuthor(_author);
			setYearOfPublishment(_yearOfPublishment);
			setTitle(_title);
			setTypeOfBook(_typeOfBook);
			setCountBook(_countBooks);
		}
};
