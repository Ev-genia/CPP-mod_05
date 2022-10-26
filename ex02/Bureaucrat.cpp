/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:55:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 00:27:30 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("NoName"), grade(150)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	grade = rhs.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string enterName, int enterGrade): name(enterName)
{
	if (enterGrade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (enterGrade > 150)
		throw Bureaucrat::GradeTooHighException();
	grade = enterGrade;
}

const std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ((char *) "Caught GradeTooLowException Bureaucrat");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ((char *) "Caught GradeTooHighException Bureaucrat");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

void	Bureaucrat::singForm(const Form &forma)
{
	if (forma.getSinged() == true)
		std::cout << this->getName() << " singed " << forma << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign " << forma << " because " << 
			forma.getName() << " don't singed" << std::endl;
}

// void	executeForm(Form const & form);
// Наконец, добавьте функцию-член executeForm(Form const & form) в Bureaucrat. Он должен попытаться выполнить форму.
// В случае успеха напечатайте что-то вроде:

// <бюрократ> казнен <форма>

// Если нет, выведите явное сообщение об ошибке.
void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (Form::FormIsNotSingException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << ", because form isn't sinded" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << ", because grade is too low" << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat & bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (out);
}
