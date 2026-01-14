/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:14 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 15:52:05 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
	std::cout << _name << " have been terminated" << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << _name << " attack with their " << _weapon.getType()
		<< std::endl;
}
