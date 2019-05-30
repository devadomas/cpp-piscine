#ifndef SOLVER_CLASS_HPP
#define SOLVER_CLASS_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iostream>


class Solver
{
public:

	Solver(std::string const & input);
	Solver(Solver const & src);
	~Solver(void);
	Solver&	operator=(Solver const & src);

	void			tokenize(void);
	bool			verify(void);
	void			format(void);
	int				result(void) const;
	void			printCommands(void) const;

	void			solve(void);

	void			printTokens(void) const;
	void			printRPN(void) const;
	std::string		addStack(std::vector<int>) const;

	std::string		getInput(void) const;
	std::vector<std::string>	getTokens(void) const;
	std::vector<std::string>	getStack(void) const;
	std::vector<std::string>	getRPN(void) const;

private:
	std::string		_input;

	std::vector<std::string>		_rpnV;
	std::vector<int> 				_stack;
	std::vector<std::string>		_stackV;
	std::vector<std::string>		_tokensV;
	std::vector<std::string>		_commander;

	static bool		isNumber(const std::string & str);
	static float	toFloat(const std::string & str);
	static std::string	formatToken(const std::string & str);
	static std::string	applyPadding(const std::string & str);

protected:
	Solver(void);
};

#endif
