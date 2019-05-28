#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void): _officeBlocksSize(0), _targetSize(0) { }
CentralBureaucracy::~CentralBureaucracy(void) { }

// private
CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src) { *this = src; }
CentralBureaucracy &	CentralBureaucracy::operator=(CentralBureaucracy const & src)
{
	if (this != src)
	{
		this->_officeBlocks = src._officeBlocks;
		this->_officeBlocksSize = src._officeBlocksSize;
		this->_targetSize = src._targetSize;
		this->_targetQueue =src._targetQueue;
	}
	return *this;
}
// /private

void					CentralBureaucracy::feed(Bureaucrat * beur)
{
	if (this->_officeBlocksSize == 20)
		throw CentralBureaucracy::OfficesFullException();

	Intern	intern;
	this->_officeBlocks[this->_officeBlocksSize] = OfficeBlock(&intern, &beur, &beur);
	this->_officeBlocksSize++;
}

void					CentralBureaucracy::queueUp(std::string const & str)
{
	if (this->_targetSize == TARGET_MAX_SIZE)
		throw CentralBureaucracy::QueueIsFullException();
	this->_targetQueue[this->_officeBlocksSize] = str;
	this->_officeBlocksSize++;
}

void					CentralBureaucracy::doBureaucracy(void) const
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < this->_officeBlocksSize; i++)
	{
		std::string		formType[] = {
			"robotomy request",
			"presidential pardon",
			"shrubbery creation"
		};
		for (int j = 0; j < this->_targetSize; j++)
			this->_officeBlocks[i].doBureaucracy(formType[rand() % 3], this->_targetQueue[j]);
	}
}

CentralBureaucracy::OfficesFullException::OfficesFullException(void) { }
CentralBureaucracy::OfficesFullException::~OfficesFullException(void) throw() { }
CentralBureaucracy::OfficesFullException::OfficesFullException(OfficesFullException const &src) { *this = src; }
CentralBureaucracy::OfficesFullException & CentralBureaucracy::OfficesFullException::operator=(CentralBureaucracy::OfficesFullException const &) { return *this; }
const char * CentralBureaucracy::OfficesFullException::what(void) const throw() { return ("all offices are full"); }

CentralBureaucracy::QueueIsFullException::QueueIsFullException(void) { }
CentralBureaucracy::QueueIsFullException::~QueueIsFullException(void) throw() { }
CentralBureaucracy::QueueIsFullException::QueueIsFullException(QueueIsFullException const &src) { *this = src; }
CentralBureaucracy::QueueIsFullException & CentralBureaucracy::QueueIsFullException::operator=(CentralBureaucracy::QueueIsFullException const &) { return *this; }
const char * CentralBureaucracy::QueueIsFullException::what(void) const throw() { return ("queue is full"); }
