#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;

	public:
		AForm();
		AForm( std::string name, int signGrade, int execGrade, bool sign );
		AForm( const AForm& src );
		AForm& operator=( const AForm& src );
		virtual ~AForm();

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned( const Bureaucrat& bureaucrat );

		virtual void	execute( const Bureaucrat& executor ) const = 0;

		class toHighException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To High";}
		};
		class toLowException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To Low";}
		};
		class notSignedException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Form not signed";}
		};

};

std::ostream&   operator<<( std::ostream& ost, const AForm& src );

#endif // FORM_HPP
