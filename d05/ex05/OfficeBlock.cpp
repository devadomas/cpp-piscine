#include <string>
#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(OfficeBlock const & src) { *this = src; } // private
OfficeBlock &		OfficeBlock::operator=(OfficeBlock const &) { return *this; } // private

OfficeBlock::OfficeBlock(void)
{
	this->_intern = NULL;
	this->_signer = NULL;
	this->_executor = NULL;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor):
	_intern(intern), _signer(signer), _executor(executor) { }

OfficeBlock::~OfficeBlock(void) { }

// fun stuff

void				OfficeBlock::setIntern(Intern * intern) { this->_intern = intern; }
void				OfficeBlock::setSigner(Bureaucrat * signer) { this->_signer = signer; }
void				OfficeBlock::setExecutor(Bureaucrat * executor) { this->_executor = executor; }

void				OfficeBlock::doBureaucracy(std::string formName, std::string const target)
{
	Form		*form;

	if (!this->_intern || !this->_signer || !this->_executor)
		throw OfficeBlock::OfficeNotFilledException();
	if (!(form = this->_intern->makeForm(formName, target)))
	{
		std::cerr << "Error while allocating form" << std::endl;
		return ;
	}
	this->_signer->signForm(*form);
	this->_executor ->executeForm(*form);
	delete form;
}

// exceptions

OfficeBlock::OfficeNotFilledException::OfficeNotFilledException(void) { }
OfficeBlock::OfficeNotFilledException::~OfficeNotFilledException(void) throw() { }
OfficeBlock::OfficeNotFilledException::OfficeNotFilledException(OfficeNotFilledException const &src) { *this = src; }
OfficeBlock::OfficeNotFilledException & OfficeBlock::OfficeNotFilledException::operator=(OfficeBlock::OfficeNotFilledException const &) { return *this; }
const char * OfficeBlock::OfficeNotFilledException::what(void) const throw() { return ("office block is not filled"); }
