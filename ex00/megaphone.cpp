#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	std::string	str;
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return (0);
	}
	while (1)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			str += std::toupper(av[i][j]);
			j++;
		}
		i++;
		if (av[i] == NULL)
			break;
		else 
			str += " ";
	}
	std::cout << str << std::endl;
	return (0);
}