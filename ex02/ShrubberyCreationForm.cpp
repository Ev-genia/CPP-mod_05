/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:24:21 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/26 22:18:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreation", 145, 137)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string enterTarget): 
												Form("ShrubberyCreation", 145, 137)
{
	target = enterTarget;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & broExec) const
{
// Вы должны убедиться, что форма подписана и что уровень бюрократа, 
// пытающегося заполнить форму, достаточно высок. 
// В противном случае создайте соответствующее исключение.
	executePermitted(broExec);
	
	std::ofstream	outfile;

	outfile.open(target + "_shrubbery");
	if (outfile.is_open() != true)
	{
		std::cerr << "Error opening file" << std::endl;
		throw std::ios::failure("Error opening file");
	}
	outfile << ASCII_THREE << std::endl;
	outfile.close();
}

void	ShrubberyCreationForm::beSinged(Bureaucrat const & broSind)
{
	if (broSind.getGrade() < 1)
		throw Form::GradeTooLowException();
	if (broSind.getGrade() <= this->getGradeToSing())
		setSing(true);
}
