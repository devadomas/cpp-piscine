/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:10:43 by azaliaus          #+#    #+#             */
/*   Updated: 2019/04/04 23:11:09 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

void	phonebookShowContact(Phonebook *book)
{
	int			index;
	std::string	input;

	std::cout << "Enter index to see more information: ";
	std::getline(std::cin, input);
	if (!isNumber(input))
	{
		std::cout << "You must enter index number!" << std::endl;
		return ;
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index > 8 || index >= book->getSize())
	{
		std::cout << "Index that you are trying to access is invalid!" << std::endl;
		return ;
	}
	book->displayContact(index);
}

void	phonebookShowContacts(Phonebook *book)
{
	std::cout << std::right << std::setw(DISPLAY_CONTACTS_SIZE) << "index" << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << "first name" << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << "last name" << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << "nickname" << std::endl;
	for (int i = 0; i < book->getSize(); i++)
	{
		std::cout << std::right << std::setw(10) << i << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << prepString(book->getContactById(i).getFirstname()) << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << prepString(book->getContactById(i).getLastname()) << "|" <<
			std::setw(DISPLAY_CONTACTS_SIZE) << prepString(book->getContactById(i).getNickname()) << std::endl;
	}
	if (book->getSize() > 0)
		phonebookShowContact(book);
}
