/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:58:29 by maderuel          #+#    #+#             */
/*   Updated: 2024/03/07 12:04:59 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected :
		std::string	_name;
		std::string	_type;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public :
		ClapTrap();
		ClapTrap( const std::string &name );
		ClapTrap( ClapTrap &src );
		~ClapTrap();

		int		getHp( void ) const;
		int		getEp( void ) const;
		int		getAd( void ) const;

		void	displayStats( void );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
