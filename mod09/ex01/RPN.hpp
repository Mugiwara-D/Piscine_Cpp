#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>

class RPN
{

	public:
		RPN();
		RPN( const RPN& src );
		RPN& operator=( const RPN& src );
		~RPN();

		static bool			exprCheck( const std::string& expr );
		static long long	calculate( const std::string& expr );

		class NoResultException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class DivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif // RPN_HPP
