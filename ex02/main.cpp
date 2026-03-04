/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:24:57 by jweber            #+#    #+#             */
/*   Updated: 2026/03/02 15:46:25 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base&	p);

int	main(void)
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}

Base * generate(void)
{
	std::srand(std::time(NULL));

	Base		*ptr = NULL;
	unsigned	a = rand() % 3;
	switch (a) {
		case 0: ptr = new A(); std::cout << "A created\n"; break;
		case 1: ptr = new B(); std::cout << "B created\n"; break;
		case 2: ptr = new C(); std::cout << "C created\n"; break;
	}
	return (ptr);
}

void identify(Base* p)
{
	Base *ptr;

	std::cout << "in identify from a Base pointer, ";
	std::cout << "Base real type is: ";
	ptr = dynamic_cast<A*>(p);
	if (ptr != NULL)
	{
		std::cout << "A\n";
		return ;
	}

	ptr = dynamic_cast<B*>(p);
	if (ptr != NULL)
	{
		std::cout << "B\n";
		return ;
	}

	ptr = dynamic_cast<C*>(p);
	if (ptr != NULL)
	{
		std::cout << "C\n";
		return ;
	}
}

void	identify(Base&	p)
{
	std::cout << "in identify from a base reference, ";
	std::cout << "Base real type is: ";
	try
	{
		Base& ref = dynamic_cast<A&>(p);
		std::cout << "A\n";
		(void) ref;
		return ;
	}
	catch (std::exception& e)
	{
	}

	try
	{
		Base& ref = dynamic_cast<B&>(p);
		std::cout << "B\n";
		(void) ref;
		return ;
	}
	catch (std::exception& e)
	{
	}

	try
	{
		Base& ref = dynamic_cast<C&>(p);
		std::cout << "C\n";
		(void) ref;
		return ;
	}
	catch (std::exception& e)
	{
	}
}
