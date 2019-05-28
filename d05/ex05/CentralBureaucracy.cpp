#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void): _officeBlocksSize(0), _targetSize(0) { }
CentralBureaucracy::~CentralBureaucracy(void) { this->cleanOffices(); }

// private
CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src) { *this = src; }
CentralBureaucracy &	CentralBureaucracy::operator=(CentralBureaucracy const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < src._officeBlocksSize; i++)
			this->_officeBlocks[i] = src._officeBlocks[i];
		this->_officeBlocksSize = src._officeBlocksSize;
		this->_targetSize = src._targetSize;
		for (int i = 0; i < src._targetSize; i++)
			this->_targetQueue[i] = src._targetQueue[i];
	}
	return *this;
}
// /private

void					CentralBureaucracy::feed(Bureaucrat * beur)
{
	if (this->_officeBlocksSize == 20)
		throw CentralBureaucracy::OfficesFullException();

	Intern		intern;
	OfficeBlock	office(&intern, beur, beur);
	this->_officeBlocks[this->_officeBlocksSize] = office;
	this->_officeBlocksSize++;
}

void					CentralBureaucracy::queueUp(std::string const & str)
{
	if (this->_targetSize == TARGET_MAX_SIZE)
		throw CentralBureaucracy::QueueIsFullException();
	this->_targetQueue[this->_targetSize] = str;
	this->_targetSize++;
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
		{
			std::string		form = formType[rand() % 3];
			std::cout << "office is about to do " << form << " type!" << std::endl;
			this->_officeBlocks[i].doBureaucracy(form, this->_targetQueue[j]);
		}
	}
}

void					CentralBureaucracy::cleanOffices(void)
{
	std::cout << "CentralBureaucracy: cleaning offices. Everyone is fired now." << std::endl;
	for (int i = 0; i < this->_officeBlocksSize; i++)
	{
		delete this->_officeBlocks[i].getExecutor();
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
