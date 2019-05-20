#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
	this->_size = 0;
}

Phonebook::~Phonebook(void) {}

bool		Phonebook::addContact(Contact contact)
{
	if (this->_size >= 8)
		return false;
	this->_clist[this->_size++] = contact;
	return true;
}

int			Phonebook::getSize(void) const
{
	return this->_size;
}

Contact		Phonebook::getContactById(int id) const
{
	return this->_clist[id];
}

void		Phonebook::displayContact(int index) const
{
	Contact		cont;

	cont = this->_clist[index];
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "First name:" << cont.getFirstname() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Last name:" << cont.getLastname() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Nick name:" << cont.getNickname() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Login:" << cont.getLogin() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Postal code:" << cont.getPostal() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Email:" << cont.getEmail() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Phone number:" << cont.getPhone() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Birthday date:" << cont.getBirthday() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Favorite meal:" << cont.getFavmeal() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Underwear color:" << cont.getUnderwear() << std::endl;
	std::cout << std::left << std::setw(DISPLAY_CONTACT_SIZE) << "Darkest secret:" << cont.getSecret() << std::endl;
}
