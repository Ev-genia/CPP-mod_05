/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:55:25 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/26 17:34:42 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &);
	Bureaucrat(const Bureaucrat &);
	virtual ~Bureaucrat();

	Bureaucrat(std::string, int);
	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException();
		const char	*what() const throw();
		~GradeTooLowException() throw();
	};

	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException();
		const char* what() const throw();
		~GradeTooHighException() throw();
	};

	void	singForm(const Form &);
	void	executeForm(Form const & form);
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat &);

#endif