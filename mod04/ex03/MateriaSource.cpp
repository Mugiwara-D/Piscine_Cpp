#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for(int i = 0; i < 4; i++)
	{
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;

	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (src._materias[i])
				_materias[i] = src._materias[i];
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_materias[i])
		{
			delete _materias[i];
			_materias[i] = NULL;
		}
}

AMateria*	MateriaSource::getMateria( const std::string &type ){
	for (int i = 0; i < 4; i++)
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i];
	return NULL;
}

AMateria*	MateriaSource::creatMateria( const std::string &type ){
	for (int i = 0; i < 4; i++)
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	return NULL;
}

void	MateriaSource::learnMateria( AMateria* m ){
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << "Materia Source " << m->getType() << " created" << std::endl;
			return ;
		}
	}
}
