/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:31:13 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 10:04:24 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardon", 25, 5) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string enterTarget): Form("PresidentialPardon", 25, 5)
{
	target = enterTarget;
}

void	PresidentialPardonForm::execute(Bureaucrat const & broExec) const
{
	executePermitted(broExec);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
