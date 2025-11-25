/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:42:04 by huidris           #+#    #+#             */
/*   Updated: 2025/11/25 23:12:15 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(NULL));

	Base *p = generate();

	std::cout << "identify(&p): ";
	identify(*p);

	delete p;

	p = generate();

	std::cout << "identify(p): ";
	identify(p);

	delete p;

	return 0;
}
