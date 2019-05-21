#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type) { }

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::Enemy(void) {}
Enemy::~Enemy(void) { }

Enemy &			Enemy::operator=(Enemy const & src)
{
	if (this != &src)
	{
		this->_hp = src._hp;
		this->_type = src._type;
	}
	return *this;
}

std::string		Enemy::getType(void) const
{
	return this->_type;
}

int				Enemy::getHp(void) const
{
	return this->_hp;
}

void			Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	if (this->_hp - damage < 0) // dies; not sure what to do
		;
	this->_hp -= damage;
	if (this->_hp < 0)
		this->_hp = 0;
}

void			Enemy::setHp(int hp)
{
	this->_hp = hp;
}
