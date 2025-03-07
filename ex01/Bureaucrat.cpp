/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:55:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 17:47:56 by mlarra           ###   ########.fr       */
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
		throw Bureaucrat::GradeTooLowException("grade < 1");
	else if (enterGrade > 150)
		throw Bureaucrat::GradeTooHighException("grade > 150");
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
		throw Bureaucrat::GradeTooHighException("grade then > 150");
}

void	Bureaucrat::decrementGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException("grade then < 1");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &errMesage)
															: m_error(errMesage)
{
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	// return ((char *) "Caught GradeTooLowException");
	std::string	temp;

	temp += "GradeTooLowException ";
	if (!m_error.empty())
		temp += m_error;
	return (temp.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *errMesage)
															: m_error(errMesage)
{
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	// return ((char *) "Caught GradeTooHighException");
	std::string	temp;

	temp += "GradeTooHighException ";
	if (!m_error.empty())
		temp += m_error;
	return (temp.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

void	Bureaucrat::singForm(const Form &forma)
{
	if (forma.getSinged() == true)
		std::cout << this->getName() << " singed " << forma.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign " << forma.getName() << " because " << 
			forma.getName() << " don't singed" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat & bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (out);
}
