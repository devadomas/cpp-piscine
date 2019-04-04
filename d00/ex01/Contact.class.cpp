/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:00:29 by azaliaus          #+#    #+#             */
/*   Updated: 2019/04/04 23:15:11 by azaliaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

std::string		Contact::getFirstname(void) const
{
	return this->_firstname;
}

bool			Contact::setFirstname(std::string name)
{
	if (name.length() == 0)
		return (false);
	this->_firstname = name;
	return (true);
}

std::string		Contact::getLastname(void) const
{
	return this->_lastname;
}

bool			Contact::setLastname(std::string name)
{
	if (name.length() == 0)
		return (false);
	this->_lastname = name;
	return (true);
}

std::string		Contact::getNickname(void) const
{
	return this->_nickname;
}

bool			Contact::setNickname(std::string name)
{
	if (name.length() == 0)
		return (false);
	this->_nickname = name;
	return (true);
}

std::string		Contact::getLogin(void) const
{
	return this->_login;
}

bool			Contact::setLogin(std::string login)
{
	if (login.length() == 0)
		return (false);
	this->_login = login;
	return (true);
}

std::string		Contact::getPostal(void) const
{
	return this->_postal;
}

bool			Contact::setPostal(std::string code)
{
	if (code.length() == 0)
		return (false);
	this->_postal = code;
	return (true);
}

std::string		Contact::getEmail(void) const
{
	return this->_email;
}


/*
**	TODO: Maybe add verification
*/
bool			Contact::setEmail(std::string email)
{
	if (email.length() == 0)
		return (false);
	this->_email = email;
	return (true);
}

std::string		Contact::getPhone(void) const
{
	return this->_phone;
}

bool			Contact::setPhone(std::string phone)
{
	if (phone.length() == 0)
		return (false);
	this->_phone = phone;
	return (true);
}

std::string		Contact::getBirthday(void) const
{
	return this->_birthday;
}

bool			Contact::setBirthday(std::string date)
{
	if (date.length() == 0)
		return (false);
	this->_birthday = date;
	return (true);
}

std::string		Contact::getFavmeal(void) const
{
	return this->_favmeal;
}

bool			Contact::setFavmeal(std::string meal)
{
	if (meal.length() == 0)
		return (false);
	this->_favmeal = meal;
	return (true);
}

std::string		Contact::getUnderwear(void) const
{
	return this->_underwearclr;
}

bool			Contact::setUnderwear(std::string underwear)
{
	if (underwear.length() == 0)
		return (false);
	this->_underwearclr = underwear;
	return (true);
}

std::string		Contact::getSecret(void) const
{
	return this->_secret;
}

bool			Contact::setSecret(std::string secret)
{
	if (secret.length() == 0)
		return (false);
	this->_secret = secret;
	return (true);
}
