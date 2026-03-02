/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:46:54 by jweber            #+#    #+#             */
/*   Updated: 2026/03/02 15:17:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data():
	a()
{
}

Data::Data(int a, int b):
	a(a),
	b(b)
{
}

Data::~Data()
{
}

const int&	Data::getA() const
{
	return (this->a);
}

const int&	Data::getB() const
{
	return (this->b);
}

std::ostream&	operator<<(std::ostream& os, const Data& other)
{
	const int&	a = other.getA();
	const int&	b = other.getB();
	std::cout << "&other: " << &other << ", &a = " << &a << ", a = " << a << ", &b = " << &b << ", b = " << b << "\n";
	return (os);
}
