/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:50:49 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 17:48:14 by mlarra           ###   ########.fr       */
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
	~Form();

	Form(const std::string, const int, const int);
	const std::string	getName() const;
	bool				getSinged() const;
	const int			getGradeToSing() const;
	const int			getGradeToExecute() const;
	void				beSinged(const Bureaucrat &);

	class GradeTooLowException: public std::exception
	{
	private:
		std::string	m_error;
	public:
		GradeTooLowException(const std::string &);
		const char	*what() const throw();
		~GradeTooLowException() throw();
	};
	
	class GradeTooHighException: public std::exception
	{
	private:
		std::string	m_error;
	public:
		GradeTooHighException(const std::string &);
		const char* what() const throw();
		~GradeTooHighException() throw();
	};
	
	virtual void	execute(Bureaucrat const & executor) const = 0;
	void			setSing(const bool);
};

std::ostream	&operator<<(std::ostream &, const Form &);

#endif