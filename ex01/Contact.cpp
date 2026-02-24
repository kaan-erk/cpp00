#include "Contact.hpp"

void	Contact::add_first_name(void)
{
	std::string str;

	while(str.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout <<"\n EOF detected. Exiting program..." << std::endl;
			exit(1);
		}
	}
	_firstName = str;
}

void	Contact::add_last_name(void)
{
	std::string str;

	while(str.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout <<"\n EOF detected. Exiting program..." << std::endl;
			exit(1);
		}
	}
	_lastName = str;
}

void	Contact::add_nickname(void)
{
	std::string str;

	while(str.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout <<"\n EOF detected. Exiting program..." << std::endl;
			exit(1);
		}
	}
	_nickName = str;
}

void	Contact::add_phone_number(void)
{
	std::string str;

	while(str.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout <<"\n EOF detected. Exiting program..." << std::endl;
			exit(1);
		}
	}
	_phoneNumber = str;
}

void	Contact::add_darkest_secret(void)
{
	std::string str;

	while(str.empty())
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, str);
		if(std::cin.eof())
		{
			std::cout <<"\n EOF detected. Exiting program..." << std::endl;
			exit(1);
		}
	}
	_darkestSecrets = str;
}

void	Contact::add_contact(void)
{
	add_first_name();
	add_last_name();
	add_nickname();
	add_phone_number();
	add_darkest_secret();
}
