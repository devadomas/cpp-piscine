#include "Solver.class.hpp"

Solver::~Solver(void) { }
Solver::Solver(void) { } // protected construstor
Solver::Solver(std::string const & input): _numberSize(0), _input(input) { }
Solver::Solver(Solver const & src) { *this = src; }

Solver &		Solver::operator=(Solver const & src)
{
	if (this != &src)
	{
		this->_numberSize = src._numberSize;
		this->_input = src._input;
		this->_stack = src._stack;
		this->_rpnV = src._rpnV;
		this->_stackV = src._stackV;
		this->_tokensV = src._tokensV;
		this->_commander = src._commander;
	}
	return *this;
}

std::string						Solver::getInput(void) const { return this->_input; }
std::vector<std::string>		Solver::getTokens(void) const { return this->_tokensV; }
std::vector<std::string>		Solver::getStack(void) const { return this->_stackV; }
std::vector<std::string>		Solver::getRPN(void) const { return this->_rpnV; }
int								Solver::result(void) const { return this->_stack[0]; }


void			Solver::tokenize(void)
{

	std::string			delim(" ");
	std::stringstream 	stringStream(Solver::applyPadding(this->_input));

	// std::cout << "Formed string: " << stringStream.str() << std::endl;
	while(std::getline(stringStream, delim))
	{
		std::size_t prev = 0, pos;
		while ((pos = delim.find_first_of(" ", prev)) != std::string::npos)
		{
			if (pos > prev)
				this->_tokensV.push_back(delim.substr(prev, pos - prev));
			prev = pos + 1;
		}
		if (prev < delim.length())
			this->_tokensV.push_back(delim.substr(prev, std::string::npos));
	}
}

void			Solver::verify(void)
{
	int		numberOfParentheses(0);
	bool	lastIsOpeningParenthese(false);
	bool	lastIsClosingParenthese(false);
	bool	lastIsOperator(false);
	bool	lastIsNumeric(false);

	for (unsigned long i = 0; i < this->_tokensV.size(); i++)
	{
		std::string	value(this->_tokensV[i]);
		if (i == 0)
		{
			if (this->isNumber(value))
				lastIsNumeric = true;
			else if (value == "(")
			{
				lastIsOpeningParenthese = true;
				numberOfParentheses++;
			}
			else
				throw InvalidInputException();
		}
		else if (this->isNumber(value))
		{
			if (lastIsOpeningParenthese || lastIsOperator)
			{
				lastIsOpeningParenthese = false;
				lastIsClosingParenthese = false;
				lastIsOperator = false;
				lastIsNumeric = true;
			}
			else
				throw InvalidInputException();
		}
		else if (value == "(")
		{
			if (lastIsOpeningParenthese || lastIsOperator)
			{
				numberOfParentheses++;
				lastIsOpeningParenthese = true;
				lastIsClosingParenthese = false;
				lastIsOperator = false;
				lastIsNumeric = false;
			}
			else
				throw InvalidInputException();
		}
		else if (value == ")")
		{
			if (lastIsClosingParenthese || lastIsNumeric)
			{
				numberOfParentheses--;
				lastIsOpeningParenthese = false;
				lastIsClosingParenthese = true;
				lastIsOperator = false;
				lastIsNumeric = false;
			}
			else
				throw InvalidInputException();
		}
		else if (value == "+" || value == "-" || value == "*" || value == "/")
		{
			if (lastIsClosingParenthese || lastIsNumeric)
			{
				lastIsOpeningParenthese = false;
				lastIsClosingParenthese = false;
				lastIsOperator = true;
				lastIsNumeric = false;
			}
			else
				throw InvalidInputException();
		}
		else
			throw InvalidInputException();
	}

	if (numberOfParentheses != 0 || lastIsOperator || lastIsOpeningParenthese)
		throw InvalidInputException();
}
void			Solver::format(void)
{
	for (unsigned int i = 0; i < this->_tokensV.size() ; i++)
	{
		if (isNumber(this->_tokensV[i]))
			this->_rpnV.push_back(this->_tokensV[i]);
		else if (this->_tokensV[i] == "(")
			this->_stackV.push_back(this->_tokensV[i]);
		else if (this->_tokensV[i] == ")")
		{
			while (this->_stackV.back() != "(")
			{
				this->_rpnV.push_back(this->_stackV.back());
				this->_stackV.pop_back();
			}
			this->_stackV.pop_back();
		}
		else if (this->_stackV.empty())
			this->_stackV.push_back(this->_tokensV[i]);
		else if ((this->_tokensV[i] == "*" || this->_tokensV[i] == "/") && (this->_stackV.back() == "+" || this->_stackV.back() == "-"))
			this->_stackV.push_back(this->_tokensV[i]);
		else
		{
			while (!this->_stackV.empty() && this->_stackV.back() != "(")
			{
				this->_rpnV.push_back(this->_stackV.back());
				this->_stackV.pop_back();
			}
			this->_stackV.push_back(this->_tokensV[i]);
		}
	}
	while (!this->_stackV.empty())
	{
		this->_rpnV.push_back(this->_stackV.back());
		this->_stackV.pop_back();
	}
}

void			Solver::printCommands(void) const
{
	for (unsigned int i = 0; i < this->_commander.size(); i++)
		std::cout << this->_commander[i] << std::endl;
}

void			Solver::solve(void)
{
	for (unsigned int i = 0; i < this->_rpnV.size(); ++i)
	{
		std::stringstream		ss;

		ss << "I " << std::left << std::setw(DEFINE_FIRST_COLLUM) << Solver::formatToken(this->_rpnV[i]) << " | OP ";
		if (Solver::isNumber(this->_rpnV[i]))
		{
			ss << std::left << std::setw(DEFINE_SECOND_COLLUM) << "Push" << " |";
			this->_stack.insert(this->_stack.begin(), std::stoi(this->_rpnV[i], NULL));
			ss << Solver::addStack(this->_stack);
		}
		else if (this->_rpnV[i] == "+")
		{
			ss << std::left << std::setw(DEFINE_SECOND_COLLUM) << "Add" << " |";
			this->_stack[1] += this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			ss << Solver::addStack(this->_stack);
		}
		else if (this->_rpnV[i] == "-")
		{
			ss << std::left << std::setw(DEFINE_SECOND_COLLUM) << "Substract" << " |";
			this->_stack[1] -= this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			ss << Solver::addStack(this->_stack);
		}
		else if (this->_rpnV[i] == "*")
		{
			ss << std::left << std::setw(DEFINE_SECOND_COLLUM) << "Multiply" << " |";
			this->_stack[1] = this->_stack[1] * this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			ss << Solver::addStack(this->_stack);
		}
		else if (this->_rpnV[i] == "/")
		{
			ss << std::left << std::setw(DEFINE_SECOND_COLLUM) << "Division" << " |";
			if (this->_stack[0] == 0)
				throw std::runtime_error("division by 0");
			this->_stack[1] = this->_stack[1] / this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			ss << Solver::addStack(this->_stack);
		}
		this->_commander.push_back(ss.str());
	}
}

// Utils
bool			Solver::isNumber(const std::string & str)
{
	float f;
	std::istringstream iss(str);

    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

// For output formatting of Token vector
std::string		Solver::formatToken(const std::string & str)
{
	if (Solver::isNumber(str))
		return std::string("Num(" + str + ")");
	else if (!str.compare("("))
		return std::string("ParOpen");
	else if (!str.compare(")"))
		return std::string("ParClose");
	return std::string("Op(" + str + ")");
}

void			Solver::printTokens(void) const
{
	std::vector<std::string>		tokens(this->getTokens());

	std::cout << "Tokens: ";
	for(unsigned long i = 0; i < tokens.size(); i++)
		std::cout << Solver::formatToken(tokens[i]) << " ";
	std::cout << std::endl;
}

void			Solver::printRPN(void) const
{
	std::vector<std::string>		tokens(this->getRPN());

	std::cout << "Postfix: ";
	for(unsigned long i = 0; i < tokens.size(); i++)
		std::cout << Solver::formatToken(tokens[i]) << " ";
	std::cout << std::endl;
}

std::string		Solver::addStack(std::vector<int> v) const
{
	std::stringstream		ss;
	std::vector<int>		tokens(v);

	ss << " ST";
	for(unsigned long i = 0; i < tokens.size(); i++)
		ss << " " << tokens[i];
	ss << "]";
	return ss.str();
}

std::string		Solver::applyPadding(const std::string & str)
{
	std::stringstream ss;

	for (unsigned long i = 0; i < str.length(); i++)
	{
		ss << str[i];
		if ((str[i] == '(' && isdigit(str[i + 1])) ||
			(isdigit(str[i]) && !isdigit(str[i + 1])) ||
			(!isdigit(str[i]) && !isdigit(str[i + 1])))
			ss << " ";
	}
	return ss.str();
}

Solver::InvalidInputException::InvalidInputException(void) { }
Solver::InvalidInputException::~InvalidInputException(void) throw() { }
Solver::InvalidInputException::InvalidInputException(InvalidInputException const &src) { *this = src; }
Solver::InvalidInputException & Solver::InvalidInputException::operator=(Solver::InvalidInputException const &) { return *this; }
const char * Solver::InvalidInputException::what(void) const throw() { return ("Invalid input."); }
