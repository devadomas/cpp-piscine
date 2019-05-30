#ifndef SOLVER_CLASS_HPP
#define SOLVER_CLASS_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

#define DEFINE_FIRST_COLLUM 10
#define DEFINE_SECOND_COLLUM 8

class Solver
{
public:

	Solver(std::string const &);
	Solver(Solver const &);
	~Solver(void);
	Solver&	operator=(Solver const &);

	void			tokenize(void);
	void			verify(void);
	void			format(void);
	int				result(void) const;

	void			solve(void);

	void			printTokens(void) const;
	void			printRPN(void) const;
	void			printCommands(void) const;
	std::string		addStack(std::vector<int>) const;

	std::string					getInput(void) const;
	std::vector<std::string>	getTokens(void) const;
	std::vector<std::string>	getStack(void) const;
	std::vector<std::string>	getRPN(void) const;

	class InvalidInputException : public std::exception
	{
		public:
			InvalidInputException(void);
			InvalidInputException(InvalidInputException const &);
			virtual ~InvalidInputException(void) throw();
			InvalidInputException &		operator=(InvalidInputException const &);
			virtual const char *		what(void) const throw();
	};
private:
	int								_numberSize;
	std::string						_input;
	std::vector<int> 				_stack;
	std::vector<std::string>		_rpnV;
	std::vector<std::string>		_stackV;
	std::vector<std::string>		_tokensV;
	std::vector<std::string>		_commander;

	static bool						isNumber(const std::string &);
	static std::string				formatToken(const std::string &);
	static std::string				applyPadding(const std::string &);

protected:
	Solver(void);
};

#endif
