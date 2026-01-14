/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:40 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 16:15:06 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		std::string	_name;
		Weapon	*_weapon;
	public :
		HumanB( std::string name );
		~HumanB();
		void	attack( void );
		void	setWeapon( Weapon& weapon );
};

#endif
