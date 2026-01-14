#include "RPN.hpp"

RPN::RPN() {
    std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN& RPN::operator=(const RPN& src) {
	(void) src;
	return *this;
}

RPN::~RPN() {
}

static int	ft_stoi( const std::string& str )
{
	int	n;
	std::stringstream	ss(str);

	ss >> n;
	return n;
}

bool	RPN::exprCheck( const std::string& expr )
{
	if (expr.find_first_not_of("0123456789+-*/ ") == std::string::npos || std::isdigit(expr[expr.length() - 1]))
		return true;
	return false;
}

long long RPN::calculate(const std::string& expr)
{
    int left;
    int right;
    int result;
    std::stringstream postfix(expr);
    std::stack<int> temp;
    std::string s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (temp.size() < 2)
                throw NoResultException();
            right = temp.top();
            temp.pop();
            left = temp.top();
            temp.pop();
            switch (s.at(0))
            {
                case '+': result =  left + right ; break;
                case '-': result =  left - right ; break;
                case '/':
                    if (right != 0)
                        result =  left / right;
                    else
                        throw DivisionByZeroException();
                break;
                case '*': result =  left * right ; break;
            }
            temp.push(result);
        }
        else
            temp.push(ft_stoi(s));
    }
	return temp.top();
}

const char*	RPN::NoResultException::what() const throw() {
	return "RPN exception: No result. Wrongly formatted expression";
}

const char*	RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: division by zero";
}
