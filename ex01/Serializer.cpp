/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:20:45 by huidris           #+#    #+#             */
/*   Updated: 2025/11/19 01:44:03 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &){}

Serializer &Serializer::operator=(const Serializer &)
{
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{



	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{


	

	return reinterpret_cast<Data*>(raw);
}
