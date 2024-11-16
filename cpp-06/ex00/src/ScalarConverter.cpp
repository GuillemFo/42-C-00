/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:51:01 by gforns-s          #+#    #+#             */
/*   Updated: 2024/11/17 00:55:05 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}


bool	ckCha(const std::string &str)
{
	if (str.length() == 1 && isprint(str[0]))
		return (true);
	return (false);
}
bool	ckInt(const std::string &str)
{
	std::stringstream tmp(str);
	int result;

	tmp >> result;
	if (tmp.fail() || !tmp.eof())
	{
		tmp.clear();
		return (false);
	}
	return (true);
}

bool	ckFlo(const std::string &str)
{
	float result;
	if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
	else if (str[0] != '.' && (str.length() -1) != '.')
	{
		size_t a = str.find_first_of('.');
		if (a != std::string::npos)
		{
			if (!(a > 0 && std::isdigit(str[a - 1])) || !(a < str.size() - 1 && std::isdigit(str[a + 1])))
				return (false);
		}
		if (str.find_first_of('f') == str.find_last_of('f') && str.find_first_of('f') == (str.length() -1))
		{
			std::string hold = str;
			hold.resize(hold.length() -1);
			std::stringstream tmp(hold);
			tmp >> result;
			if (tmp.fail() || !tmp.eof())
			{
				tmp.clear();
				return (false);
			}
			return (true);
		}
	}
	return (false);
}

bool	ckDou(const std::string &str)
{
	double result;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	else if (str[0] != '.' && (str.length() -1) != '.')
	{
		size_t a = str.find_first_of('.');
		if (a != std::string::npos)
		{
			if (!(a > 0 && std::isdigit(str[a - 1])) || !(a < str.size() - 1 && std::isdigit(str[a + 1])))
				return (false);
		}
		std::stringstream tmp(str);
		tmp >> result;
		if (tmp.fail() || !tmp.eof())
		{
			tmp.clear();
			return (false);
		}
		return (true);
	}
	return (false);
}

char    getType(const std::string &str)
{
    if (ckInt(str))
        return ('i');
    else if (ckDou(str))
        return ('d');
    else if (ckFlo(str)) 
        return ('f');
    else if (ckCha(str))
        return ('c');
    return ('n');
}

void ScalarConverter::convert(const std::string& s)
{
    char type = getType(s);

	if (type == 'c')
		std::cout << "is char" << std::endl;
	else if (type == 'i')
		std::cout << "is int" << std::endl;
	else if (type == 'f')
		std::cout << "is float" << std::endl;
	else if (type == 'd')
		std::cout << "is double" << std::endl;
	else if (type == 'n')
		std::cout << "is trash" << std::endl;
}
