/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:48:40 by huidris           #+#    #+#             */
/*   Updated: 2025/11/17 21:24:20 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string input)
{
	int type = getType(input);
	if (type == INVALIDINPUT)
	{
		std::cerr << "Invalid input" << std::endl;
		return;
	}
	convertType(input, type);
}

void ScalarConverter::convertType(std::string input, int type)
{
	switch (type)
	{
		case CHAR:
			charConvert(input);
			return;

		case INT:
			intConvert(input);
			return;

		case FLOAT:
			floatConvert(input);
			return;

		case DOUBLE:
			doubleConvert(input);
			return;

		case PSEUDOLITERAL:
			pseudoConvert(input);
			return;

		default:
			std::cerr << "Conversion Failed" << std::endl;
			return;
	}
}

void ScalarConverter::charConvert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	c = input[1];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	std::cout << "char~	: '" << c << "'" << std::endl;
	std::cout << "int	: " << i << std::endl;
	std::cout << "float	: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double	: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::intConvert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (isOverflow(input, INT))
		return;
	std::istringstream iss(input);
	iss >> i;

	if(i < 0 || i > 255)
		std::cout << "char	: impossible " << std::endl;
	else if(!isprint((unsigned char)i))
		std::cout << "char	: Non displayable " << std::endl;
	else
	{
		c = static_cast<char>(i);
		std::cout << "char	: '" << c << "'" << std::endl;
	}
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	std::cout << "int~	: " << i << std::endl;
	std::cout << "float	: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double	: " << std::fixed << std::setprecision(1) << d << std::endl;
}
void ScalarConverter::floatConvert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	input = input.erase(input.size() - 1);
	std::istringstream iss(input);
	iss >> f;
	if (iss.fail())
	{
		isOverflow(input, FLOAT);
		return;
	}

	if(f < 0 || f > 255)
		std::cout << "char	: impossible " << std::endl;
	else if(!isprint((unsigned char)f))
		std::cout << "char	: Non displayable " << std::endl;
	else
	{
		c = static_cast<char>(f);
		std::cout << "char	: '" << c << "'" << std::endl;
	}

	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
		std::cout << "int	: impossible" << std::endl;
	else
	{
		i = static_cast<int>(f);
		std::cout << "int	: " << i << std::endl;
	}
	d = static_cast<double>(f);

	std::cout << "float~	: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double	: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::doubleConvert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	std::istringstream iss(input);
	iss >> d;
	if (iss.fail())
	{
		isOverflow(input, DOUBLE);
		return;
	}

	if(d < 0 || d > 255)
		std::cout << "char	: impossible " << std::endl;
	else if(!isprint((unsigned char)d))
		std::cout << "char	: Non displayable " << std::endl;
	else
	{
		c = static_cast<char>(d);
		std::cout << "char	: '" << c << "'" << std::endl;
	}

	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		std::cout << "int	: impossible" << std::endl;
	else
	{
		i = static_cast<int>(d);
		std::cout << "int	: " << i << std::endl;
	}
	f = static_cast<float>(d);

	std::cout << "float	: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double~	: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::pseudoConvert(std::string input)
{
	if (input == "nanf" || input == "-nanf" || input == "+nanf"
		|| input == "inff" || input == "-inff" || input == "+inff")
	{
		std::cout << "char	: impossible" << std::endl;
		std::cout << "int	: impossible" << std::endl;
		std::cout << "float	: " << input << std::endl;
		input.erase(input.size() -1);
		std::cout << "double	: " << input<< std::endl;
	}

	if (input == "nan" || input == "-nan" || input == "+nan"
		|| input == "inf" || input == "-inf" || input == "+inf")
	{
		std::cout << "char	: impossible" << std::endl;
		std::cout << "int	: impossible" << std::endl;
		std::cout << "float	: " << input << "f" << std::endl;
		std::cout << "double	: " << input << std::endl;
	}
}

bool ScalarConverter::isInt(std::string input)
{
	int i = 0;

	if (input[0] == '+' || input[0] == '-')
		i++;
	int len = input.size();
	while(i < len)
	{
		if(!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isOverflow(std::string input, int type)
{
	char* end_ptr;
	errno = 0;

	if (type == INT)
	{
		long val = std::strtol(input.c_str(), &end_ptr, 10);
		if (errno == ERANGE)
		{
			std::cout << "Invalid input" << std::endl;
		}
		else if (val > INT_MAX || val < INT_MIN)
		{
			std::cout << "Overflow" << std::endl;
		}
		else
			return false;
	}
	std::cout << "char	: impossible" << std::endl;
	std::cout << "int	: impossible" << std::endl;
	std::cout << "float	: impossible" << std::endl;
	std::cout << "double	: impossible" << std::endl;
	return true;
}

int ScalarConverter::getType(std::string input)
{
	int len = input.size();
	if (len == 3 && input[0] == '\'' && input[2] == '\'')
		return CHAR;
	if (input == "nan" || input == "-nan" || input == "+nan"
		|| input == "inf" || input == "-inf" || input == "+inf"
		|| input == "nanf" || input == "-nanf" || input == "+nanf"
		|| input == "inff" || input == "-inff" || input == "+inff")
		return PSEUDOLITERAL;
	if (isInt(input) == true)
		return INT;
	if (input.find('.') != std::string::npos && input[len - 1] == 'f')
		return FLOAT;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	return INVALIDINPUT;
}
