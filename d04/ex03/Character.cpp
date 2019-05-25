#include "Character.hpp"

Character::Character(void) { }

Character::Character(std::string const & name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_arr[i] = NULL;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_arr[i])
		{
			delete this->_arr[i];
			this->_arr[i] = NULL;
		}
	}
}

Character::Character(Character const & src)
{
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
		if (this->_arr[i])
			this->_arr[i] = src._arr[i]->clone();
}

Character &			Character::operator=(Character const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_arr[i])
			{
				delete this->_arr[i];
				this->_arr[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
			if (this->_arr[i])
				this->_arr[i] = src._arr[i]->clone();
	}
	return *this;
}

//

void				Character::equip(AMateria * m)
{
	for (int i = 0; i < 4; i++)
		if (this->_arr[i] == m)
			return ;
	for (int i = 0; i < 4; i++)
		if (this->_arr[i] == NULL)
		{
			this->_arr[i] = m;
			break ;
		}
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	this->_arr[idx] = NULL;
}

void				Character::use(int idx, ICharacter & target)
{
	if (idx >= 0 && idx < 4 && this->_arr[idx])
		this->_arr[idx]->use(target);
}

std::string const &		Character::getName(void) const
{
	return this->_name;
}
