#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
	std::cout << GREEN <<  _name << EOC << " constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	isValidGrade(grade);
	std::cout << GREEN <<  _name << EOC << " constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED <<  _name << EOC << " destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
	: _name(bur._name), _grade(bur._grade)
{
	*this = bur;
	std::cout << YELLOW <<  _name << EOC << " copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &bur)
{
	if (this == &bur)
		return (*this);
	return (*this);
}

std::ostream& operator << ( std::ostream &out, const Bureaucrat &bur )
{
	out << BLUE;
	out << bur.getName();
	out << EOC;
	out << ", bureaucrat grade ";
	out << bur.getGrade();
	return out;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade++;
}

void Bureaucrat::isValidGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " sign " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}
