#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

#include <string>
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"

#define TARGET_MAX_SIZE		25

class CentralBureaucracy
{
public:
	CentralBureaucracy(void);
	~CentralBureaucracy(void);

	void		feed(Bureaucrat *);
	void		queueUp(std::string const &);
	void		doBureaucracy(void) const;

	//
	class OfficesFullException : public std::exception
	{
		public:
			OfficesFullException(void);
			OfficesFullException(OfficesFullException const &);
			virtual ~OfficesFullException(void) throw();
			OfficesFullException &		operator=(OfficesFullException const &);
			virtual const char *		what(void) const throw();
	};
	class QueueIsFullException : public std::exception
	{
		public:
			QueueIsFullException(void);
			QueueIsFullException(QueueIsFullException const &);
			virtual ~QueueIsFullException(void) throw();
			QueueIsFullException &		operator=(QueueIsFullException const &);
			virtual const char *		what(void) const throw();
	};

private:
	int			_officeBlocksSize;
	OfficeBlock	_officeBlocks[20];

	int			_targetSize;
	std::string	_targetQueue[TARGET_MAX_SIZE];

	CentralBureaucracy(CentralBureaucracy const &);
	CentralBureaucracy &		operator=(CentralBureaucracy const &);

};

#endif
