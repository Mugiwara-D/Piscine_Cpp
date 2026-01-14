/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:06:36 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 12:09:47 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int	main(void)
{
	Weapon sword = Weapon("Wood Sword");
	HumanA bob("Bob", sword);
	bob.attack();
	sword.setType("broken spiked club");
	bob.attack();


	Weapon club = Weapon("spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("bloody spiked club");
	jim.attack();

	return 0;
}
