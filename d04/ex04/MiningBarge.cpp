#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
	for (int i = 0; i < 4; i++)
		this->_arr[i] = NULL;
}

MiningBarge::~MiningBarge(void) { }
MiningBarge::MiningBarge(MiningBarge const & src)
{
	// *this = src;
	for (int i = 0; i < 4; i++)
		if (src._arr[i])
			this->_arr[i] = src._arr[i];
}
MiningBarge &		MiningBarge::operator=(MiningBarge const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
			if (src._arr[i])
				this->_arr[i] = src._arr[i];
	}
	return *this;
}

void				MiningBarge::equip(IMiningLaser * laser)
{
	for (int i = 0; i < 4; i++)
		if (this->_arr[i] == laser)
			return ;
	for (int i = 0; i < 4; i++)
		if (this->_arr[i] == NULL)
		{
			this->_arr[i] = laser;
			break ;
		}
}

void				MiningBarge::mine(IAsteroid * asteroid) const
{
	for (int i = 0; i < 4; i++)
		if (this->_arr[i])
			this->_arr[i]->mine(asteroid);
}
