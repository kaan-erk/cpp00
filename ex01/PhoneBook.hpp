#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{
	public:
	PhoneBook();
    ~PhoneBook() {};
	void	addContact(void);
	void	searchContact(void);
	
	private:
	Contact	_contacts[8];
	int		_totalContacts;
};

#endif