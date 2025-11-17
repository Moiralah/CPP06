/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:45:31 by huidris           #+#    #+#             */
/*   Updated: 2025/11/17 20:29:45 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <sstream>
#include <string>
#include <limits>
#include <climits>
#include <cerrno>
#include <stdlib.h>

class ScalarConverter
{
	public:
		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();

		static void charConvert(std::string input);
		static void intConvert(std::string input);
		static void floatConvert(std::string input);
		static void doubleConvert(std::string input);
		static void pseudoConvert(std::string input);

		static bool isInt(std::string input);
		static bool isOverflow(std::string input, int type);
		static int getType(std::string input);
		static void convertType(std::string input, int type);

		enum Type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDOLITERAL,
			INVALIDINPUT
		};

};



#endif
