#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct	s_data {

	std::string	str;
}	t_data;

class	Serializer {
	private :
		Serializer() {}
		~Serializer() {}

	public :
		static uintptr_t	serialize( t_data *ptr );
		static t_data		*deserialize( uintptr_t raw );
};

#endif
