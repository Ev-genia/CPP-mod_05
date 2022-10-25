/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:18 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/25 13:17:02 by mlarra           ###   ########.fr       */
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
		Bureaucrat	a("Bureaucrat(100)", 100);;
		std::cout << a;
		Form		fA("formA", 149, 149);
		std::cout << fA;
		a.singForm(fA);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	return 0;
}
