/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:12:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 11:43:33 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern	&Intern::operator=(const Intern &rhs)
{
	return (*this);
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

Form	*Intern::createShrobberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::createRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(const std::string nameForm, std::string enterTarget)
{
	Form	*(Intern::*funcArr[3])(std::string) = {&Intern::createShrobberyCreation,
												&Intern::createRobotomyRequest,
												&Intern::createPresidentialPardon};
	std::string	nameRequest[3] = {"Shrobbery Creation", "Robotomy Request", 
									"Presidential Pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (nameRequest[i] == nameForm)
			return ((this->*funcArr[i])(enterTarget));
	}
	throw "Form is not found";
	return (NULL);
}
