/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:18 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/27 11:55:48 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern	someRandomIntern1;
		Form	*rrf1;

		rrf1 = someRandomIntern1.makeForm("wrong request", "Bender");
		delete rrf1;
	}
	catch (const char *str)
	{
		std::cerr << str << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Intern	someRandomIntern;
		Form	*rrf;
		Bureaucrat	bro("bro", 50);

		rrf = someRandomIntern.makeForm("Shrobbery Creation", "Bender");
		rrf->beSinged(bro);
		bro.executeForm(*rrf);
		delete rrf;
	}
	catch (const char *str)
	{
		std::cerr << str << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
/*
{
	std::cout << "==1==" << std::endl;
	try
	{
		Bureaucrat	a("Bureaucrat(146)", 146);
		std::cout << a;
		ShrubberyCreationForm	berry("home");
		berry.beSinged(a);
		a.singForm(berry);
		berry.execute(a);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==2==" << std::endl;
	try
	{
		Bureaucrat	b("Bureaucrat(139)", 139);
		std::cout << b;
		ShrubberyCreationForm	berryb("work");
		berryb.beSinged(b);
		b.singForm(berryb);
		berryb.execute(b);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==3==" << std::endl;
	try
	{
		Bureaucrat	c("Bureaucrat(135)", 135);
		std::cout << c;
		ShrubberyCreationForm	berryc("lake");
		berryc.beSinged(c);
		c.executeForm(berryc);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==4==" << std::endl;
	try
	{
		Bureaucrat	d("Bureaucrat(70)", 70);
		std::cout << d;
		RobotomyRequestForm	berryd("horse");
		berryd.beSinged(d);
		d.executeForm(berryd);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==5==" << std::endl;
	try
	{
		Bureaucrat	f("Bureaucrat(40)", 40);
		std::cout << f;
		RobotomyRequestForm	berryf("cat");
		berryf.beSinged(f);
		f.executeForm(berryf);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==6==" << std::endl;
	try
	{
		Bureaucrat	g("Bureaucrat(7)", 7);
		std::cout << g;
		PresidentialPardonForm	berryg("dog");
		berryg.beSinged(g);
		g.executeForm(berryg);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << "==7==" << std::endl;
	try
	{
		Bureaucrat	k("Bureaucrat(3)", 3);
		std::cout << k;
		PresidentialPardonForm	berryk("bird");
		berryk.beSinged(k);
		k.executeForm(berryk);
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	return 0;
}*/
