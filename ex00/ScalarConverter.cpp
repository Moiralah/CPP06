/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:48:40 by huidris           #+#    #+#             */
/*   Updated: 2025/11/15 05:50:03 by huidris          ###   ########.fr       */
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
	std::cout << "char: " << charConvert(input, type)<< std::endl;
	std::cout << "int: " << intConvert(input, type)<< std::endl;
	std::cout << "float: " << floatConvert(input, type)<< std::endl;
	std::cout << "double: " << doubleConvert(input, type)<< std::endl;
}

std::string ScalarConverter::charConvert(std::string input, int type)
{
	switch (type)
	{
		case CHAR:
			{
				if (input[1] >= 0 && input[1] <= 31)
					return ("Non displayable");
				else
					return input;
			}
		case INT:
			return ("Non displayable");
		case FLOAT:
			return ("'*'");
		case DOUBLE:
			return ("'*'");
		case PSEUDOLITERAL:
			return ("impossible");
		default:
			return ("Converision failed");
	}
}

std::string ScalarConverter::intConvert(std::string input, int type)
{
	switch (type)
	{
		case CHAR:
			return ("Non displayable");
		case INT:
			return input;
		case FLOAT:
		{
			int len = input.size();
			int i = input.find('.') != std::string::npos;
			return (input.erase(len - i));
		}
		case DOUBLE:
			return (input + ".0");
		case PSEUDOLITERAL:
			return ("impossible");
		default:
			return ("Converision failed");
	}
}
std::string ScalarConverter::floatConvert(std::string input, int type)
{
	switch (type)
	{
		case CHAR:
			return ("Non displayable");
		case INT:
			return (input + ".0f");
		case FLOAT:
			return (input);
		case DOUBLE:
		{
			int len = input.size();
			int i = input.find('f') != std::string::npos;
			return (input.erase(len - i));
		}
		case PSEUDOLITERAL:
			return (input + "f");
		default:
			return ("Converision failed");
	}
}

std::string ScalarConverter::doubleConvert(std::string input, int type)
{
	switch (type)
	{
		case CHAR:
			return ("Non displayable");
		case INT:
		{
			int len = input.size();
			int i = input.find('.') != std::string::npos;
			return (input.erase(len - i));
		}
		case FLOAT:
		{
			int len = input.size();
			int i = input.find('f') != std::string::npos;
			return (input.erase(len - i));
		}
		case DOUBLE:
			return (input);
		case PSEUDOLITERAL:
			return (input);
		default:
			return ("Converision failed");
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

int ScalarConverter::getType(std::string input)
{
	int len = input.size();
	if (len == 3 && input[0] == '\'' && input[2] == '\'')
		return CHAR;
	if (isInt(input) == true)
		return INT;
	if (input.find('.') != std::string::npos && input[len - 1] == 'f')
		return FLOAT;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	if (input == "nan" || input == "-nan" || input == "+nan"
		|| input == "inf" || input == "-inf" || input == "+inf")
		return PSEUDOLITERAL;
	return INVALIDINPUT;
}
