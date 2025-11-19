/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:42:04 by huidris           #+#    #+#             */
/*   Updated: 2025/11/19 19:02:41 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data Student1("Yaya", 42);

	std::cout << "Original pointer: " << &Student1 << std::endl;

	uintptr_t raw = Serializer::serialize(&Student1);

	std::cout << "Serialize pointer (uintptr_t): " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Deserialized pointer: " << ptr << std::endl;

	return 0;
}
