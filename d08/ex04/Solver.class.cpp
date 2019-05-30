#include "Solver.class.hpp"

Solver::~Solver(void) { }
Solver::Solver(void) { } // protected contrustor
Solver::Solver(std::string const & input): _input(input) { }
Solver::Solver(Solver const & src) { *this = src; }

Solver &		Solver::operator=(Solver const & src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_tokensV = src._tokensV;
		this->_stackV = src._stackV;
		this->_rpnV = src._rpnV;
		this->_stack = src._stack;
	}
	return *this;
}

std::string		Solver::getInput(void) const { return this->_input; }
std::vector<std::string>		Solver::getTokens(void) const { return this->_tokensV; }
std::vector<std::string>		Solver::getStack(void) const { return this->_stackV; }
std::vector<std::string>		Solver::getRPN(void) const { return this->_rpnV; }


void			Solver::tokenize(void)
{

	std::string			delim(" ");
	std::stringstream 	stringStream(Solver::applyPadding(this->_input));

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

bool			Solver::verify(void)
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
				return false;
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
				return false;
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
				return false;
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
				return false;
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
				return false;
		}
		else
			return false;
	}

	if (numberOfParentheses != 0 || lastIsOperator || lastIsOpeningParenthese)
		return false;
	return true;
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

int				Solver::result(void) const { return this->_stack[0]; }

int				Solver::solve(void)
{
	for (unsigned int i = 0; i < this->_rpnV.size(); ++i)
	{
		std::cout << "I " << Solver::formatToken(this->_rpnV[i]) << " | OP ";
		if (Solver::isNumber(this->_rpnV[i]))
		{
			std::cout << "Push |";
			int nbr = std::stoi(this->_rpnV[i], NULL);
			this->_stack.insert(this->_stack.begin(), nbr);
			Solver::printVector(this->_stack);
		}
		else if (this->_rpnV[i] == "+")
		{
			std::cout << "Add |";
			this->_stack[1] += this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			Solver::printVector(this->_stack);
		}
		else if (this->_rpnV[i] == "-")
		{
			std::cout << "Substract |";
			this->_stack[1] -= this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			Solver::printVector(this->_stack);
		}
		else if (this->_rpnV[i] == "*")
		{
			std::cout << "Multiply |";
			this->_stack[1] = this->_stack[1] * this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			Solver::printVector(this->_stack);
		}
		else if (this->_rpnV[i] == "/")
		{
			std::cout << "Division |";
			this->_stack[1] = this->_stack[1] / this->_stack[0];
			this->_stack.erase(this->_stack.begin());
			Solver::printVector(this->_stack);
		}
	}

	return this->_stack[0];
}

/*Fixed			Solver::solve(void)
{
	std::reverse(this->_rpnV.begin(), this->_rpnV.end());
	int	index = this->_rpnV.size() - 1;
	while (this->_rpnV.size() != 1)
	{
		if (this->isNumber(this->_rpnV[index])
			&& this->isNumber(this->_rpnV[index - 1])
			&& !this->isNumber(this->_rpnV[index - 2]))
		{
			std::stringstream ss;
			if (this->_rpnV[index - 2] == "+")
				ss << Fixed(this->toFloat(this->_rpnV[index])) + Fixed(this->toFloat(this->_rpnV[index - 1]));
			else if (this->_rpnV[index - 2] == "-")
				ss << Fixed(this->toFloat(this->_rpnV[index])) - Fixed(this->toFloat(this->_rpnV[index - 1]));
			else if (this->_rpnV[index - 2] == "*")
				ss << Fixed(this->toFloat(this->_rpnV[index])) * Fixed(this->toFloat(this->_rpnV[index - 1]));
			else if (this->_rpnV[index - 2] == "/" && Fixed(this->toFloat(this->_rpnV[index - 1])) == 0)
			{
				std::cout << "Divsion by 0. Output will not be accurate." << std::endl;
				ss << Fixed(this->toFloat(this->_rpnV[index])) / Fixed(this->toFloat(this->_rpnV[index - 1]));
			}
			else if (this->_rpnV[index - 2] == "/")
				ss << Fixed(this->toFloat(this->_rpnV[index])) / Fixed(this->toFloat(this->_rpnV[index - 1]));
			this->_rpnV.erase(this->_rpnV.begin() + index);
			this->_rpnV.erase(this->_rpnV.begin() + index - 1);
			this->_rpnV.erase(this->_rpnV.begin() + index - 2);
			this->_rpnV.insert(this->_rpnV.begin() + index - 2, ss.str());
			index = this->_rpnV.size() - 1;
		}
		else
			index--;
	}
	return Fixed(this->toFloat(this->_rpnV[0]));
}*/

// Utils
bool			Solver::isNumber(const std::string & str)
{
	float f;
	std::istringstream iss(str);

    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

float			Solver::toFloat(const std::string & str)
{
	float f;
	std::istringstream iss(str);

    iss >> std::noskipws >> f;
	return f;
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

void			Solver::printVector(std::vector<int> v) const
{
	std::vector<int>		tokens(v);

	std::cout << " ST";
	for(unsigned long i = 0; i < tokens.size(); i++)
		std::cout << " " << tokens[i];
	std::cout << "]" << std::endl;
}

std::string		Solver::applyPadding(const std::string & str)
{
	std::stringstream ss;

	for (unsigned long i = 0; i < str.length(); i++)
	{
		ss << str[i];
		if (str[i] != ' ')
			ss << " ";
	}
	return ss.str();
}
