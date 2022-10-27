/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:12:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 11:36:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Form	*createShrobberyCreation(std::string);
	Form	*createRobotomyRequest(std::string);
	Form	*createPresidentialPardon(std::string);
public:
	Intern();
	Intern	&operator=(const Intern &);
	Intern(const Intern &);
	virtual ~Intern();

	Form	*makeForm(const std::string, const std::string);
};


#endif