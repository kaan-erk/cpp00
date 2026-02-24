#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class Contact {
	public:
	
	void	add_contact(void);
    void	add_first_name(void);
    void	add_last_name(void);
    void	add_nickname(void);
    void	add_phone_number(void);
    void	add_darkest_secret(void);
	void    viewContactRow(int index) const;
    void    viewContactDetails(void) const;
	private:
	
	std::string _firstName; 
	std::string _lastName; 
	std::string _nickName; 
	std::string _phoneNumber; 
	std::string _darkestSecrets;
	std::string _truncateString(std::string str) const;
};

#endif