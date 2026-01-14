#include <iostream>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str adress = " << &str << std::endl;
	std::cout << "str value = " << str << std::endl;
	std::cout << "str ptr = " << stringPTR << ": " << *stringPTR << std::endl;
	std::cout << "str ref = " << &stringREF << ": " << stringREF << std::endl;

	return 0;
}
