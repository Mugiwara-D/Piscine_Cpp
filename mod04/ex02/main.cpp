#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal	*Animals[10];	

	for (int k = 0; k < 10; k++)
	{
		if (k % 2 == 0)
			Animals[k] = new Dog();
		else
			Animals[k] = new Cat();

	}

	j->makeSound();
	i->makeSound();


	std::cout << "\033[33m" << "Deep Copy Test Cat Copy\n"<< "\033[0m";
	Cat cat;
	Cat copy_cat(cat);
	Dog dog;

	std::cout << std::endl;

	cat.getBrain()->setIdea("shippi shippi shappa shappa");
	cat.getBrain()->showIdea();
	dog.getBrain()->setIdea("stick and food");
	dog.getBrain()->showIdea();

	Animals[1]->makeSound();

	delete j;//should not create a leak
	delete i;

	for (int k = 0; k < 10; k++)
		delete Animals[k];
	return 0;
}
