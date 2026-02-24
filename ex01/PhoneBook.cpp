#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_totalContacts = 0;
}

void PhoneBook::addContact(void)
{
	int	index = _totalContacts % 8;
	_contacts[index].add_contact();
	_totalContacts++;
}

void PhoneBook::searchContact(void)
{
	if (_totalContacts == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << std::right << "First Name" << "|"
              << std::setw(10) << std::right << "Last Name" << "|"
              << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    int limit = _totalContacts;
    if (limit > 8)
        limit = 8;
    for (int i = 0; i < limit; i++)
    {
        _contacts[i].viewContactRow(i);
    }
    std::cout << "---------------------------------------------" << std::endl;
	std::string input;
    std::cout << "Enter index to view details: ";
    if (!std::getline(std::cin, input))
    {
        exit(1);
    }
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
    {
        int index = input[0] - '0';
        if (index < limit)
            _contacts[index].viewContactDetails();
        else
        {
            std::cout << "Invalid index: No contact at this index." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input: Please enter a valid single digit index." << std::endl;
    }
}