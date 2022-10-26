/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:50:49 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/26 17:41:41 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				singed;
	const int			gradeToSing;
	const int			gradeToExecute;
protected:
	std::string			target;
public:
	Form();
	Form	&operator=(const Form &);
	Form(const Form &);
	virtual ~Form();

	Form(const std::string, const int, const int);
	const std::string	getName() const;
	bool				getSinged() const;
	const int			getGradeToSing() const;
	const int			getGradeToExecute() const;
	virtual void		beSinged(const Bureaucrat &);

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
	
	virtual void	execute(Bureaucrat const & executor) const = 0;
	void			setSing(const bool);
	void			executePermitted(Bureaucrat const &) const;

	class FormIsNotSingException: public std::exception
	{
	public:
		FormIsNotSingException();
		const char * what() const throw();
		~FormIsNotSingException() throw();
	};
	
};

std::ostream	&operator<<(std::ostream &, const Form &);

#endif