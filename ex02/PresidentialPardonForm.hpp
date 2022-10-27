/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:31:22 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 09:45:05 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDPNFPRM_HPP
# define PRESIDENTIALPARDPNFPRM_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &);
	PresidentialPardonForm(PresidentialPardonForm const &);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm(std::string);
	void	execute(Bureaucrat const &)const;
	void	beSing(Bureaucrat const &);
};

#endif