/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:06:29 by maderuel          #+#    #+#             */
/*   Updated: 2024/03/07 12:31:44 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Claptrap constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap( const std::string &name )
{
	std::cout << "Claptrap naming constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap( ClapTrap &src )
{
	std::cout << "Claptrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

int		ClapTrap::getHp( void ) const
{
	return (_hitPoints);
}

int		ClapTrap::getEp( void ) const
{
	return (_energyPoints);
}

int		ClapTrap::getAd( void ) const
{
	return (_attackDamage);
}

void	ClapTrap::displayStats( void )
{
	std::cout << "name: " << _name << std::endl;
	std::cout << "Hit points: " << _hitPoints << std::endl;
	std::cout << "Energy points: " << _energyPoints << std::endl;
	std::cout << "Attack damage: " << _attackDamage << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap, " << _name << " attacks, " << target << 
			" causing, " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints == 0)
		std::cout << "can't attack. reason:" << _name << " is dead." << std::endl;
	else
		std::cout << "can't attack. reason:" << _name << " is tired" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0)
		std::cout << _name << " already dead" << std::endl;
	else
	{
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
			std::cout << "you beat him up, he dead" << std::endl;
		else
			std::cout << amount << " : damage done\n" << this->_hitPoints
				<< " : health left" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints <= 0)
		std::cout << "no energy left, let me die pleas" << std::endl;
	else
	{
		if (amount == 0)
			std::cout << "how funny of you" << std::endl;
		else
		{
			this->_energyPoints--;
			this->_hitPoints += amount;
			std::cout << "gained : " << amount << " of hitPoints\nnow being : "
				<< this->_hitPoints << std::endl;
		}
	}
	return ;
}
