/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:12:49 by azaliaus          #+#    #+#             */
/*   Updated: 2019/04/04 23:13:22 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Contact.class.hpp"
#include <string>
#include <iostream>

bool	enterContactInfo(Contact *contact, bool (Contact::*f)(std::string), std::string text)
{
	std::string		input;
	bool			status;

	std::cout << text << ": ";
	while (1)
	{
		std::getline(std::cin, input);
		if (input.compare("CANCEL") == 0)
		{
			std::cout << "Are you sure? [Y/n]: ";
			std::getline(std::cin, input);
			if (input.length() == 0 || input.compare("Y") == 0)
				return (false);
			else
				std::cout << text << ": ";
		}
		else
		{
			status = (contact->*f)(input);
			if (!status)
			{
				std::cout << "This field cannot be empty!" << std::endl;
				std::cout << text << ": ";
			}
			else
				return (true);
		}
	}
}

void	phonebookAddLoop(Phonebook *book)
{
	std::string		input;
	Contact			contact;

	if (book->getSize() >= 8)
	{
		std::cout << "Sorry, but contact list is full. You cannot add more contacts." << std::endl;
		return ;
	}
	std::cout << "You are adding new user!" << std::endl;
	std::cout << "To cancel type CANCEL" << std::endl;
	if (!enterContactInfo(&contact, &Contact::setFirstname, "Enter your first name") ||
		!enterContactInfo(&contact, &Contact::setLastname, "Enter your last name") ||
		!enterContactInfo(&contact, &Contact::setNickname, "Enter your nickname") ||
		!enterContactInfo(&contact, &Contact::setLogin, "Enter your login") ||
		!enterContactInfo(&contact, &Contact::setPostal, "Enter your postal code") ||
		!enterContactInfo(&contact, &Contact::setEmail, "Enter your email address") ||
		!enterContactInfo(&contact, &Contact::setPhone, "Enter your phone number") ||
		!enterContactInfo(&contact, &Contact::setBirthday, "Enter your birthday date") ||
		!enterContactInfo(&contact, &Contact::setFavmeal, "Enter your favorite meal") ||
		!enterContactInfo(&contact, &Contact::setUnderwear, "Enter your underwear color") ||
		!enterContactInfo(&contact, &Contact::setSecret, "Enter your darkest secret"))
		return ;
	book->addContact(contact);
	std::cout << "New contact \"" << contact.getFirstname() << " " << contact.getLastname() << "\" successfuly added!" << std::endl;
}

void	phonebookLoop(void)
{
	Phonebook		book;
	std::string		cmd;

	while (1)
	{
		std::cout << "Type command: ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			return ;
		else if (cmd.compare("ADD") == 0)
			phonebookAddLoop(&book);
		else if (cmd.compare("SEARCH") == 0)
			phonebookShowContacts(&book);
		else
			std::cout << "Sorry I didn't quite get that." << std::endl;
	}
}
