/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:50:38 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 17:47:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("NoNameForm"), singed(false), gradeToSing(150), 
				gradeToExecute(150)
{
}

Form	&Form::operator=(const Form &rhs)
{
	singed = rhs.singed;
	return (*this);
}

Form::Form(const Form & src): name(src.name), gradeToSing(src.gradeToSing), 
								gradeToExecute(src.gradeToExecute)
{
	*this = src;
}

Form::~Form()
{
}

Form::Form(const std::string enterName, const int enterGradeToSinged, 
		const int enterGradeToExecute): name(enterName), 
		gradeToSing(enterGradeToSinged), gradeToExecute(enterGradeToExecute),
		singed(false)
{
	if (gradeToSing < 1)
		throw Form::GradeTooLowException("gradeToSing Form < 1");
	if (gradeToSing > 150)
		throw Form::GradeTooHighException("gradeToSing Form > 150");
	if (gradeToExecute < 1)
		throw Form::GradeTooLowException("gradeToExecute Form < 1");
	if (gradeToExecute > 150)
		throw Form::GradeTooHighException("gradeToExecute Form > 150");
}

const std::string	Form::getName() const
{
	return (name);
}

bool	Form::getSinged() const
{
	return (singed);
}

const int	Form::getGradeToSing() const
{
	return (gradeToSing);
}

const int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	Form::beSinged(const Bureaucrat &bro)
{
	if (bro.getGrade() < 1)
		throw Form::GradeTooLowException("grade Bureaucrat < 1 for singed Form");
	if (bro.getGrade() <= gradeToSing)
		singed = true;
	else
		singed = false;
}

Form::GradeTooLowException::GradeTooLowException(const std::string &enterError):
												m_error(enterError)
{
}

const char	*Form::GradeTooLowException::what() const throw()
{
	// return ((char *) "Caught GradeTooLowException Form");
	std::string	temp;

	temp += "GradeTooLowException ";
	if (!m_error.empty())
		temp += m_error;
	return (temp.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooHighException::GradeTooHighException(const std::string &enterError):
												m_error(enterError)
{
}

const char	*Form::GradeTooHighException::what() const throw()
{
	// return ((char *) "Caught GradeTooHighException Form");
	std::string	temp;

	temp += "GradeTooHighException ";
	if (!m_error.empty())
		temp += m_error;
	return (temp.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

std::ostream	&operator<<(std::ostream &out, const Form &forma)
{
	out << "NameForm: " << forma.getName() << ", singed: " << forma.getSinged() << 
		", gradeToSing: " << forma.getGradeToSing() << ", gradeToExecute: " << 
		forma.getGradeToExecute();
	return (out);
}
