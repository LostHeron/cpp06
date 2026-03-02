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
#include <cctype>
#include <cstdlib>
#include <cwctype>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>

static void	one_byte_string(char c);
static void	print_int(double d);
static void	print_char(double d);
static void	long_string(const std::string& str);
static void	float_conversion(const std::string& str);
static void	double_conversion(const std::string& str);
static void	print_from_char(char c);

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static void	print_all_impossible(void)
{
	std::cout << "char = impossible\n";
	std::cout << "int = impossible\n";
	std::cout << "float = impossible\n";
	std::cout << "double = impossible\n";
}

void ScalarConverter::convert(const std::string& str)
{

	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if (str.size() == 1)
	{
		one_byte_string(str[0]);
	}
	else
	{
		long_string(str);
	}
}

static std::string	remove_leading_ws(const std::string& str);

static void	long_string(const std::string& str)
{
	std::string	str_no_leading_ws = remove_leading_ws(str);
	for (size_t	i = 0; i < str_no_leading_ws.size(); i++)
	{
		str_no_leading_ws[i] = std::tolower(str_no_leading_ws[i]);
	}
	if (str_no_leading_ws == "inff" || str_no_leading_ws == "+inff" || str_no_leading_ws == "-inff"
		|| str_no_leading_ws == "nanf" || str_no_leading_ws == "-nanf" || str_no_leading_ws == "+nanf"
		|| (str_no_leading_ws[str_no_leading_ws.size() - 1] == 'f'
			&& (str_no_leading_ws.find(".") != str_no_leading_ws.npos || str_no_leading_ws.find("e") != str_no_leading_ws.npos)))
	{
		// for float conversion
		// check of 'inff', '+inff', ... is necessary, because 
		// conversion of a too large float using str_no_leading_wstod will
		// result in an overflow and so 'inf' or '-inf',
		// and might accecpt something like
		// 1241513415....12341f which should not be accepted because
		// a long str_no_leading_wsing of digits without '.' or 'e' should not accept 'f' at
		// the end !
		float_conversion(str_no_leading_ws);
	}
	else
	{
		double_conversion(str_no_leading_ws);
	}
}

static std::string	remove_leading_ws(const std::string& str)
{
	std::string new_string;
	size_t	i;
	for (i = 0; (i < str.size()) && std::iswspace(str[i]); i++)
		;
	for (; i < str.size(); i++)
		new_string.push_back(str[i]);
	return (new_string);
}

static void	float_conversion(const std::string& str)
{
		const char *start = str.c_str();
		char *end;
		float f = std::strtod(start, &end);
		if (start == end)
			return (print_all_impossible());
		std::string remaining = end;
		//if (str.size() > 1 || (str.size() == 1 && str[0] != 'f'))
		if (remaining.size() != 1 || remaining[0] != 'f')
			return (print_all_impossible());
		print_char(f);
		print_int(f);
		std::cout << "float = " << f << "f\n";
		std::cout << "double = " << static_cast<double>(f) << "\n";
}

static void	double_conversion(const std::string& str)
{
	const char *start = str.c_str();
	char *end;
	double d = std::strtod(start, &end);
	if (start == end)
		return (print_all_impossible());
	std::string remaining = end;
	if (remaining.size() > 0)
		return (print_all_impossible());
	print_char(d);
	print_int(d);
	std::cout << "float = " << static_cast<float>(d) << "f\n";
	std::cout << "double = " << d << "\n";
}

static void	print_char(double d)
{
	if (32 <= d && d < 127)
		std::cout << "char = '" << static_cast<char>(d) << "'\n";
	else
		std::cout << "char = impossible\n";
}

static void	print_int(double d)
{
	if (static_cast<double>(std::numeric_limits<int>().min()) - 1 < d
		&& d < static_cast<double>(std::numeric_limits<int>().max()) + 1)
		std::cout << "int = " << static_cast<int>(d) << "\n";
	else
		std::cout << "int = impossible\n";
}

static void	one_byte_string(char c)
{
	if ((32 <= c && c < '0')
		|| ('9' < c && c <= 126))
	{
		std::cout << "char = '" << c << "'\n";
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
	std::cout << "int = " << i << "\n";
	std::cout << "float = " << f << "f\n";
	std::cout << "double = " << d << "\n";
}
