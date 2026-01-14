#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "Default constructor called" << std::endl; 
	_name = "Unnamed";
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
    std::cout << "parametize construtor called" << std::endl;
    this->_name = name;
    this->ClapTrap::_name = name + "_ClapTrap";

    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;

}

DiamondTrap::DiamondTrap( DiamondTrap &src ){
    *this = src;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap& src ){
    if (this != &src)
    {
        _name = src.getName();
    }
    return *this;
}

std::string DiamondTrap::getName() const {
    return (_name);
}

void    DiamondTrap::WhoAmi() {
    std::cout << "I am a DimanondTrap named " << this->_name << ", derivating from " <<
        ClapTrap::_name << std::endl;
}
