/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:28:46 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/26 23:46:59 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &);
	RobotomyRequestForm(RobotomyRequestForm const &);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm(std::string);
	void	execute(Bureaucrat const &)const;
	void	beSing(Bureaucrat const &);
};



#endif