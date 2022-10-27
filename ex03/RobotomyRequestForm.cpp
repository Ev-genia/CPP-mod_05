/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:28:30 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 00:22:42 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequest", 72, 45) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string enterTarget): Form("RobotomyRequest", 72, 45)
{
	target = enterTarget;
}

void	RobotomyRequestForm::execute(Bureaucrat const & broExec) const
{
	executePermitted(broExec);

	std::cout << "I'm a DRRRRRRRRRRill" << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully " << std::endl;
	else
		std::cout << "robotomy" << target << "failed" << std::endl;
}

void	RobotomyRequestForm::beSing(Bureaucrat const &broRobo)
{
	if (broRobo.getGrade() < 1)
		throw Form::GradeTooLowException();
	if (broRobo.getGrade() <= this->getGradeToSing())
		setSing(true);
}
