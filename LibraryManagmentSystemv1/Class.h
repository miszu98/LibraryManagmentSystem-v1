
#include <iostream>

using namespace std;

class User {
	private:
		string firstName;
		string lastName;
		string email;
		string password;
		string phoneNumber;

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
		int setPhoneNumber(string value) {
			phoneNumber = value;
		}

		User() {

		}

		User(string _firstName, string _lastName, string _email, string _password, string _phoneNumber) {
			firstName = _firstName;
			lastName = _lastName;
			email = _email;
			password = _password;
			phoneNumber = _phoneNumber;
		}
};