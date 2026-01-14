#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: AForm( "ShrubberyCreationForm", 145, 137, false ), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm( src ), _target( src._target ){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	(void) src;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if ( this->getSigned() == false )
		throw AForm::notSignedException();
	else if ( executor.getGrade() > this->getExecGrade() )
		throw AForm::toLowException();

	std::ofstream file;
	file.open((this->getName() + "_shrubbery").c_str());
	file << "            .        +          .      .          ." << std::endl;
	file << "     .            _        .                    ." << std::endl;
	file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	file << "                     ,    `./  \\:. `.   )==-'  ." << std::endl;
	file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;	
	file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	file << "              \\:  `  X` _| _,/'   .-'" << std::endl;
	file << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	file << "                    \\::.  :\\/:'  /              +" << std::endl;
	file << "   .                 `.:.  /:'  }      ." << std::endl;
	file << "           .           ):_(:;   \\           ." << std::endl;
	file << "                      /:. _/ ,  |" << std::endl;
	file << "                   . (|::.     ,`                  ." << std::endl;
	file << "     .                |::.    {/" << std::endl;
	file << "                      |::.\\  \\ `." << std::endl;
	file << "                      |:::(\\    |" << std::endl;
	file << "              O       |:::/{ }  |                  (o" << std::endl;
	file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	file << "~~~~~~~~~~~~~~~~~~~~~~~MADERUEL~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	file.close();

}
