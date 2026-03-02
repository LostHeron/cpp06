/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:42:44 by jweber            #+#    #+#             */
/*   Updated: 2026/03/02 15:18:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <ostream>

struct Data
{
	public:
		Data();
		Data(int a, int b);
		~Data();

		const int&	getA() const;
		const int&	getB() const;
	
	private:
		Data(const Data& other);
		Data&	operator=(const Data& other);
		int	a;
		int	b;
};


std::ostream&	operator<<(std::ostream& os, const Data& other);

#endif
