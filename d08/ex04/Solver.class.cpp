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
		this->_tokens = src._tokens;
		this->_stack = src._stack;
		this->_rpn = src._rpn;
	}
	return *this;
}

std::string		Solver::getInput(void) const { return this->_input; }
Vector			Solver::getTokens(void) const { return this->_tokens; }
Vector			Solver::getStack(void) const { return this->_stack; }
Vector			Solver::getRPN(void) const { return this->_rpn; }


void			Solver::tokenize(void)
{
	std::string			delim(" ");
	std::stringstream 	stringStream(this->_input);

	while(std::getline(stringStream, delim))
	{
		std::size_t prev = 0, pos;
		while ((pos = delim.find_first_of(" ", prev)) != std::string::npos)
		{
			if (pos > prev)
				this->_tokens.push(delim.substr(prev, pos - prev));
			prev = pos + 1;
		}
		if (prev < delim.length())
			this->_tokens.push(delim.substr(prev, std::string::npos));
	}
}

bool			Solver::verify(void)
{
	int		numberOfParentheses(0);
	bool	lastIsOpeningParenthese(false);
	bool	lastIsClosingParenthese(false);
	bool	lastIsOperator(false);
	bool	lastIsNumeric(false);

	for (int i = 0; i < this->_tokens.size(); i++)
	{
		std::string	value(this->_tokens[i]);
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
	for (int i = 0; i < this->_tokens.size() ; i++)
	{
		if (isNumber(this->_tokens[i]))
			this->_rpn.push(this->_tokens[i]);
		else if (this->_tokens[i] == "(")
			this->_stack.push(this->_tokens[i]);
		else if (this->_tokens[i] == ")")
		{
			while (this->_stack.back() != "(")
				this->_rpn.push(this->_stack.pop());
			this->_stack.pop();
		}
		else if (this->_stack.empty())
			this->_stack.push(this->_tokens[i]);
		else if ((this->_tokens[i] == "*" || this->_tokens[i] == "/") && (this->_stack.back() == "+" || this->_stack.back() == "-"))
			this->_stack.push(this->_tokens[i]);
		else
		{
			while (!this->_stack.empty() && this->_stack.back() != "(")
				this->_rpn.push(this->_stack.pop());
			this->_stack.push(this->_tokens[i]);
		}
	}
	while (!this->_stack.empty())
		this->_rpn.push(this->_stack.pop());
}
Fixed			Solver::solve(void)
{
	this->_rpn.reverse();
	int	index = this->_rpn.size() - 1;
	while (this->_rpn.size() != 1)
	{
		if (this->isNumber(this->_rpn[index])
			&& this->isNumber(this->_rpn[index - 1])
			&& !this->isNumber(this->_rpn[index - 2]))
		{
			std::stringstream ss;
			if (this->_rpn[index - 2] == "+")
				ss << Fixed(this->toFloat(this->_rpn[index])) + Fixed(this->toFloat(this->_rpn[index - 1]));
			else if (this->_rpn[index - 2] == "-")
				ss << Fixed(this->toFloat(this->_rpn[index])) - Fixed(this->toFloat(this->_rpn[index - 1]));
			else if (this->_rpn[index - 2] == "*")
				ss << Fixed(this->toFloat(this->_rpn[index])) * Fixed(this->toFloat(this->_rpn[index - 1]));
			else if (this->_rpn[index - 2] == "/" && Fixed(this->toFloat(this->_rpn[index - 1])) == 0)
			{
				std::cout << "Divsion by 0. Output will not be accurate." << std::endl;
				ss << Fixed(this->toFloat(this->_rpn[index])) / Fixed(this->toFloat(this->_rpn[index - 1]));
			}
			else if (this->_rpn[index - 2] == "/")
				ss << Fixed(this->toFloat(this->_rpn[index])) / Fixed(this->toFloat(this->_rpn[index - 1]));
			this->_rpn.removeAt(index);
			this->_rpn.removeAt(index - 1);
			this->_rpn.removeAt(index - 2);
			this->_rpn.insertAt(index - 2, ss.str());
			index = this->_rpn.size() - 1;
		}
		else
			index--;
	}
	return Fixed(this->toFloat(this->_rpn[0]));
}

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

std::ostream &		operator<<(std::ostream & o, Solver const & src) {
	o << "Input : " << src.getInput() << std::endl;
	o << "Tokens : " << std::endl;
	o << src.getTokens() << std::endl;
	o << "Stack : " << std::endl;
	o << src.getStack() << std::endl;
	o << "RPN : " << std::endl;
	o << src.getRPN() << std::endl;
	return o;
}
