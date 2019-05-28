#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <string>
#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
public:
	OfficeBlock(void);
	OfficeBlock(Intern *, Bureaucrat *, Bureaucrat *);
	~OfficeBlock(void);

	void			setIntern(Intern *);
	void			setSigner(Bureaucrat *);
	void			setExecutor(Bureaucrat *);

	void			doBureaucracy(std::string, std::string const);

	class OfficeNotFilledException : public std::exception
	{
		public:
			OfficeNotFilledException(void);
			OfficeNotFilledException(OfficeNotFilledException const &);
			virtual ~OfficeNotFilledException(void) throw();
			OfficeNotFilledException &		operator=(OfficeNotFilledException const &);
			virtual const char *		what(void) const throw();
	};

private:
	Intern *		_intern;
	Bureaucrat *	_signer;
	Bureaucrat *	_executor;

	OfficeBlock(OfficeBlock const &);
	OfficeBlock &	operator=(OfficeBlock const &);

};

#endif
