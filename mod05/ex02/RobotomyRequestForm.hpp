#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

		RobotomyRequestForm();

	public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
		~RobotomyRequestForm();

		void	execute( const Bureaucrat& executor ) const;
};

std::ostream&   operator<<( std::ostream& o, const RobotomyRequestForm& rhs );

#endif // ROBOTOMYREQUESTFORM_HPP
