
#include <iostream>
#include <ctype.h>

using namespace std;

bool checkNames(string value) 
{
	if (value.length() >= 3) 
	{
		return true;
	} return false;
}

bool checkEmail(string value) 
{
	if (value.find('@') < value.length())
	{
		return true;
	} return false;
}

bool checkPhoneNumber(string value)
{
	if (value.length() > 9 || value.length() < 9)
	{
		return false;
	}
	int digits = 0;
	for (int i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]))
		{
			return false;
		}
	}
	return true;
}

bool checkPassword(string value)
{
	int digits = 0;
	int lowerLetters = 0;
	int upperLetters = 0;
	int specialChars = 0;

	for (int i = 0; i < value.length(); i++)
	{
		if (isdigit(value[i]))
		{
			digits++;
		}
		else if (islower(value[i]))
		{
			lowerLetters++;
		}
		else if (isupper(value[i]))
		{
			upperLetters++;
		}
		else if (!isalnum(value[i]))
		{
			specialChars++;
		}
	}

	if (digits <= 3 && digits >= 1) 
	{
		if (lowerLetters >= 5)
		{
			if (upperLetters >= 1 && upperLetters <= 3) 
			{
				if (specialChars == 1) 
				{
					return true;
				}
			}
			else 
			{
				return false;
			}
		}
		else 
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}