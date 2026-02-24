#include "Contact.hpp"
#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook myPhoneBook; // Orkestra şefimizi (beyni) yarattık
    std::string command;

    std::cout << "========================================" << std::endl;
    std::cout << "  WELCOME TO THE 80s AWESOME PHONEBOOK  " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

    while (true)
    {
        std::cout << "\n> ";

        if (!std::getline(std::cin, command))
        {
            std::cout << "\n[EOF] Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }
        if (command == "ADD")
        {
            myPhoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            myPhoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Contacts are lost forever! Goodbye." << std::endl;
            break;
        }
        else if (!command.empty())
        {
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT." << std::endl;
        }
    }

    return 0;
}