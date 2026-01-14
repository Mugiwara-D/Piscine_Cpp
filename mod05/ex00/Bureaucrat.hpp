#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& src );
		Bureaucrat& operator=( const Bureaucrat& src );
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void	incrGrade();
		void	decrGrade();

		class highException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To High";}
		};
		class lowException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Grade To Low";}
		};
};

std::ostream&   operator<<( std::ostream& ost, const Bureaucrat& src );

#endif // BUREAUCRAT_HPP
