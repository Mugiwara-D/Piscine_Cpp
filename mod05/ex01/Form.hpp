#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form( std::string name, int signGrade, int execGrade);
		Form( const Form& src );
		Form& operator=( const Form& src );
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned( const Bureaucrat& bureaucrat );

		class toHighException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To High";}
		};
		class toLowException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To Low";}
		};

};

std::ostream&   operator<<( std::ostream& ost, const Form& src );

#endif // FORM_HPP
