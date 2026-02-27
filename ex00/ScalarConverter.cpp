/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:10:59 by jweber            #+#    #+#             */
/*   Updated: 2026/02/27 11:11:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <string>
#include <iostream>
#include <sstream>

ScalarConverter::~ScalarConverter()
{
}

static void	print_one_char(char c);

void ScalarConverter::convert(const std::string& str)
{

	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if (str.size() == 1)
	{
		print_one_char(str[0]);
	}
	else
	{
		double d = std::strtod(str.c_str(), NULL);

		if (32 <= d && d < 127)
			std::cout << "char = " << static_cast<char>(d) << "\n";
		else
			std::cout << "char = impossible\n";

		if (static_cast<double>(std::numeric_limits<int>().min()) - 1 < d
			&& d < static_cast<double>(std::numeric_limits<int>().max()) + 1)
			std::cout << "int = " << static_cast<int>(d) << "\n";
		else
			std::cout << "int = impossible\n";
		std::cout << "float = " << static_cast<float>(d) << "f\n";
		std::cout << "double = " << d << "\n";
	}
}

static void	print_from_char(char c);

static void	print_one_char(char c)
{
	if ((32 <= c && c < '0')
		|| ('9' < c && c <= 126))
	{
		std::cout << "char = " << c << "\n";
		print_from_char(c);
	}
	else if ('0' <= c && c <= '9')
	{
		std::cout << "char = impossible\n";
		print_from_char(c - '0');
	}
}

static void	print_from_char(char c)
{
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	std::cout << "int  = " << i << "\n";
	std::cout << "float = " << f << "f\n";
	std::cout << "double = " << d << "\n";
}
