#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <iomanip>
# include "Contact.class.hpp"

# define DISPLAY_CONTACT_SIZE	17
# define DISPLAY_CONTACTS_SIZE	10

class Phonebook
{
public:
	Phonebook(void);
	~Phonebook(void);
	bool	addContact(Contact contact);
	int		getSize(void) const;
	Contact	getContactById(int id) const;
	void	displayContact(int index) const;

private:
	int		_size;
	Contact	_clist[8];
};

/*
	utils.cpp
*/
std::string 		prepString(std::string str);
bool				isNumber(const std::string& s);
void				welcomeMsg(void);

/*
	display.cpp
*/
void				phonebookShowContact(Phonebook *book);
void				phonebookShowContacts(Phonebook *book);

/*
	read.cpp
*/
bool				enterContactInfo(Contact *contact,
						bool (Contact::*f)(std::string), std::string text);
void				phonebookAddLoop(Phonebook *book);
void				phonebookLoop(void);

#endif
