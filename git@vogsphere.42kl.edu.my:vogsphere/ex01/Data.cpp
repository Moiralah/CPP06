/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:12:59 by huidris           #+#    #+#             */
/*   Updated: 2025/11/19 01:30:26 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(){}

Data::Data(std::string name, int age) : _name(name), _age(age) {}

Data::Data(const Data &other) : _name(other._name), _age(other._age) {}

Data &Data::operator=(const Data &other)
{
	if(this != &other)
		*this = other;
	return *this;
}

Data::~Data(){}



