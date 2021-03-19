#include <iostream>

using namespace std;

class User {
	private:
		string firstName;
		string lastName;
		string email;
		string password;
		int phoneNumber;

	public:
		string getFirstName() 
		{
			return firstName;
		}

		string getLastName() 
		{
			return lastName;
		}

		string getEmail() 
		{
			return email;
		}

		string getPassword() 
		{
			return password;
		}

		int getPhoneNumber() 
		{
			return phoneNumber;
		}

		User()
		{
		}

		User(string _firstName, string _lastName, string _email, string _password, int _phoneNumber) {
			firstName = _firstName;
			lastName = _lastName;
			email = _email;
			password = _password;
			phoneNumber = _phoneNumber;
		}
};

		

