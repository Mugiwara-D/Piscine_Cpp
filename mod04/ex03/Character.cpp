#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( const std::string& name ) : _name(name) {
	this->_bag[0] = NULL;
	this->_bag[1] = NULL;
	this->_bag[2] = NULL;
	this->_bag[3] = NULL;

	std::cout << "Character " << this->_name << " created" << std::endl;
}

Character::Character(const Character& src) {
	_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._bag[i])
			_bag[i] = src._bag[i];
		else
			_bag[i] = NULL;
	}
}

Character& Character::operator=(const Character& src) {
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._bag[i])
			this->_bag[i] = src._bag[i];
		else
			_bag[i] = NULL;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_bag[i])
		{
			delete this->_bag[i];
			_bag[i] = NULL;
		}
	std::cout << this->_name << " have been destroy" <<std::endl;
}

const std::string	&Character::getName() const {
	return this->_name;
}

void	Character::equip( AMateria* m ){
	for (int i = 0; i < 4; i++)
		if (this->_bag[i] == NULL)
		{
			this->_bag[i] = m;
			if (m != NULL)
				std::cout << this->_name << " equiped " << m->getType() << std::endl;
			return;
		}
	std::cout << this->_name << " couldn't equip " << m->getType() << std::endl; 
}

void	Character::unEquip( int idx ){
	std::string n;

	if (this->_bag[idx])
	{
		n = this->_bag[idx]->getType();
		delete this->_bag[idx];
		this->_bag[idx] = NULL;
		std::cout << this->_name << " dropped his " << n << " on da floor" << std::endl; 
	}
	std::cout << this->_name << " can't unequip something that he don't have" << std::endl;
}

void	Character::use( int idx, ICharacter& target ){
	if (this->_bag[idx])
	{
		std::cout << this->_name << " use " << this->_bag[idx]->getType() << std::endl;
		this->_bag[idx]->use(target);
	}
	else
		std::cout << this->_name << " unable to can do want we want to do" << std::endl; 
}

void    Character::showStats()
{

     std::cout << "\nName: " << _name << std::endl;
     std::cout << "Equiped:" << std::endl;
     
     std::cout << "\nInventory:" << std::endl;
     
	 for (int i = 0; i < 4; i++)
	 {
		 if (_bag[i])
			 std::cout << _bag[i]->getType() << std::endl; 
		 else
			 std::cout << "nothing" << std::endl;
	 }
}

