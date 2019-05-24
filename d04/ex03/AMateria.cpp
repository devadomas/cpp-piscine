#include "AMateria.hpp"

AMateria::AMateria(void): xp_(0) { }
AMateria::AMateria(AMateria const & src) { *this = src; }
AMateria::~AMateria(void) { }

AMateria &					AMateria::operator=(AMateria const & src)
{
	if (this != &src)
	{
		this->xp_ = src.xp_;
		this->_type = src._type;
	}
	return *this;
}

//

std::std::string const &	AMateria::getType(void) const { return this->_type; }
unsigned int				AMateria::getXP(void) const { return this->xp_; }

AMateria *					AMateria::clone(void) const
{
	return new AMateria(*this);
}

void						AMateria::use(ICharacter &) { this->xp_+= 10; }
void						AMateria::setType(std::string const & type) { this->_type = type; }
void						AMateria::setXP(int xp) { this->xp_ = xp; }
