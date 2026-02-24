#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	public:
	
	void	add_contact(void);
    void	add_first_name(void);
    void	add_last_name(void);
    void	add_nickname(void);
    void	add_phone_number(void);
    void	add_darkest_secret(void);

	private:
	
	std::string _firstName; 
	std::string _lastName; 
	std::string _nickName; 
	std::string _phoneNumber; 
	std::string _darkestSecrets;
};

#endif