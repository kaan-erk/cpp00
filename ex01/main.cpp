#include "Contact.hpp"

int main()
{
	Contact x;

	x.add_contact();
	std::cout << x._firstName << std::endl;
	std::cout << x._lastName << std::endl;
	std::cout << x._nickName << std::endl;
	std::cout << x._phoneNumber << std::endl;
	std::cout << x._darkestSecrets << std::endl;
}