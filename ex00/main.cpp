/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:42:04 by huidris           #+#    #+#             */
/*   Updated: 2025/11/17 20:32:57 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "Input 1 argument please." << std::endl;
// 		return 1;
// 	}
// 	ScalarConverter::convert(av[1]);
// 	return 0;
// }

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ScalarConverter::convert("'c'");
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("0");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("42");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("4.2f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("5741640684686346");
	ScalarConverter::convert("538260274094907.887f");
	ScalarConverter::convert("5724467279209.87");

	return 0;
}
