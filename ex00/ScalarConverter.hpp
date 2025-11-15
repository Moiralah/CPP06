/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:45:31 by huidris           #+#    #+#             */
/*   Updated: 2025/11/15 05:30:13 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <sstream>
#include <string>

class ScalarConverter
{
	public:
		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();

		static std::string charConvert(std::string input, int type);
		static std::string intConvert(std::string input, int type);
		static std::string floatConvert(std::string input, int type);
		static std::string doubleConvert(std::string input, int type);

		static bool isInt(std::string input);
		static int getType(std::string input);

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
