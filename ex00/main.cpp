/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:18 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 12:34:37 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	a;
		std::cout << a;
		Bureaucrat	b("Bureaucrat(0)", 0);
		std::cout << b;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	c("Bureaucrat(154)", 154);
		std::cout << c;
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	try
	{
		Bureaucrat	d("Bureaucrat(149)", 149);
		std::cout << d;
		d.incrementGrade();
		std::cout << d;
		d.incrementGrade();
		std::cout << d;
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	try
	{
		Bureaucrat	f("Bureaucrat(2)", 2);
		std::cout << f;
		f.decrementGrade();
		std::cout << f;
		f.decrementGrade();
		std::cout << f;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	return 0;
}
