/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:35 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 16:16:20 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name)
{
}

HumanB::~HumanB()
{
	std::cout << _name << "have been terminated" << std::endl;
}

void	HumanB::attack()
{
	std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	_weapon = &type;
}
