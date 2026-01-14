#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

int	main(void) 
{
	t_data data;
	uintptr_t uint;

	data.str = std::string("test");
	uint = Serializer::serialize(&data);

	std::cout << "OG data adress = " << &data 
		<< "\ndata str = " << data.str << std::endl;

	std::cout << "Reinterpreted data value = " << uint << std::endl;

	t_data *deser;

	deser = Serializer::deserialize(uint);

	std::cout << "deserialise adress = " << deser 
		<< "\ndata str = " << deser->str << std::endl;

	return 0;
}
