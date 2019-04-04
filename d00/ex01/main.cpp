/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:15:42 by azaliaus          #+#    #+#             */
/*   Updated: 2019/04/04 23:13:01 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <iostream>

int		main(void)
{
	welcomeMsg();
	phonebookLoop();
	std::cout << "Sorry to see you go! Your data has been wiped..." << std::endl;
	std::cout << "See you next time!" << std::endl;
}
