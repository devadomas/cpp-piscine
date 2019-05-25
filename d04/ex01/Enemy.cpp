#include "Enemy.hpp"

Enemy::Enemy(void) {}
Enemy::~Enemy(void) { }

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type) { }
Enemy::Enemy(Enemy const & src) { *this = src; }

Enemy &			Enemy::operator=(Enemy const & src)
{
	if (this != &src)
	{
		this->_hp = src.getHp();
		this->_type = src.getType();
	}
	return *this;
}

std::string		Enemy::getType(void) const { return this->_type; }
void			Enemy::setHp(int hp) { this->_hp = hp; }
int				Enemy::getHp(void) const { return this->_hp; }

void			Enemy::takeDamage(int damage)
{
	if (damage < 0 || this->_hp == 0)
		return ;
	this->_hp -= damage;
	if (this->_hp < 0)
		this->_hp = 0;
}
