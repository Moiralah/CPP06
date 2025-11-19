/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:21:03 by huidris           #+#    #+#             */
/*   Updated: 2025/11/19 19:03:57 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);
		~Serializer();

};

#endif
