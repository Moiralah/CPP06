/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:31:49 by huidris           #+#    #+#             */
/*   Updated: 2025/11/19 01:49:33 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
#include <iostream>
#include <string>

class Data
{
	private:
		std::string	_name;
		int			_age;

	public:
		Data();
		Data(std::string name, int age);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();

};

#endif
