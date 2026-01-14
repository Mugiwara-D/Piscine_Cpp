/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:11:36 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 13:59:25 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

std::string Weapon::getType( void ) const
{
	return (this->_type);
}

std::string	Weapon::setType( std::string type )
{
	this->_type = type;
	return(this->_type);
}
