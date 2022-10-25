/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:18 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 17:29:18 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form	f1("form1", 0, 149);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	f2("form1", 20, 159);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	a("Bureaucrat(100)", 100);
		std::cout << a;
		Form		fA("formA", 99, 149);
		std::cout << fA;
		fA.beSinged(a);
		a.singForm(fA);
		a.decrementGrade();
		fA.beSinged(a);
		a.singForm(fA);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	return 0;
}
