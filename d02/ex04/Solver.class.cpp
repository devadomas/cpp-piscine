#include "Solver.class.hpp"

Solver::Solver(void) { } // for protected class'es
Solver::~Solver(void) { }
Solver::Solver(std::string const & str): _input(str) { }

Solver::Solver(Solver const & src)
{
	*this = src;
}

Solver &		Solver::operator=(Solver const & src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_tokens = src._tokens;
		this->_solver = src._solver;
		this->_tmp = src._tmp;
	}
	return *this;
}

// funs

void			Solver::tokenize(void)
{
	std::string			splitter(" ");
	std::stringstream	sStream(this->_input);

	while (std::getline(sStream, splitter))
	{
		std::size_t		prev = 0;
		std::size_t		pos;

		while ((pos = splitter.find_first_of(" ", prev)) != std::string::npos)
		{
			if (pos > prev)
				this->_tokens.pushBack(splitter.substr(prev, pos - prev));
			prev = pos + 1;
		}
		if (prev < splitter.length())
			this->_tokens.pushBack(splitter.substr(prev, std::string::npos));
	}
}

List			Solver::getTokens(void) const
{
	return this->_tokens;
}

void			Solver::build(void)
{
	for (int i = 0; i < this->_tokens.getSize(); i++)
	{
		std::string		*arr = this->_tokens.getArr();
		if (isNumber(arr[i]))
			this->_solver.pushBack(arr[i]);
		else if (arr[i] == "(")
			this->_tmp.pushBack(arr[i]);
		else if (arr[i] == ")")
		{
			while (this->_tmp.last() != "(")
				this->_solver.pushBack(this->_tmp.popLast());
			this->_tmp.popLast();
		}
		else if (this->_tmp.getSize() == 0)
			this->_tmp.pushBack(arr[i]);
		else if ((arr[i] == "*" || arr[i] == "/")
					&& (this->_tmp.last() == "+" || this->_tmp.last() == "-"))
			this->_tmp.pushBack(arr[i]);
		else
		{
			while (this->_tmp.getSize() != 0 && this->_tmp.last() != "(")
				this->_solver.pushBack(this->_tmp.popLast());
			this->_tmp.pushBack(arr[i]);
		}
	}
	while (this->_tmp.getSize() != 0)
		this->_solver.pushBack(this->_tmp.popLast());
}

List			Solver::getSolverList(void) const
{
	return this->_solver;
}

Fixed			Solver::solve(void)
{
	std::string 		*arr = this->_solver.getArr();
	Fixed				res(toFloat(arr[0]));
	Fixed				tmp;

	for (int i = 1; i < this->_solver.getSize(); i++)
	{
		if (isNumber(arr[i]))
			tmp = Fixed(toFloat(arr[i]));
		else if (arr[i] == "+")
			res = res + tmp;
		else if (arr[i] == "-")
			res = res - tmp;
		else if (arr[i] == "*")
			res = res * tmp;
		else if (arr[i] == "/" && tmp == 0)
		{
			std::cout << "Result will be corrupted by non mathmatical arithmetics" << std::endl;
			res = res / tmp;
		}
		else if (arr[i] == "/")
			res = res / tmp;
	}
	return res;
}
