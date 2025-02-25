/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:55:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 12:55:54 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("NoName"), grade(150)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	// name = rhs.name;
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
	std::string	temp;
	const char	*str;

	temp += "Caught GradeTooLowException ";
	if (!m_error.empty())
		temp += m_error;
	str = temp.c_str();
	return (str);
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
	std::string	temp;
	const char	*str;

	temp += "GradeTooHighException ";
	if (!m_error.empty())
		temp += m_error;
	str = temp.c_str();
	return (str);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat & bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (out);
}
