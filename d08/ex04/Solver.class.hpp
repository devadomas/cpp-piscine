#ifndef SOLVER_CLASS_HPP
#define SOLVER_CLASS_HPP

#include <sstream>
#include <string>
#include "Vector.class.hpp"
#include "Fixed.class.hpp"

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
	Fixed			solve(void);

	std::string		getInput(void) const;
	Vector			getTokens(void) const;
	Vector			getStack(void) const;
	Vector			getRPN(void) const;

private:
	std::string		_input;
	Vector			_tokens;
	Vector			_stack;
	Vector			_rpn;

	static bool		isNumber(const std::string & str);
	static float	toFloat(const std::string & str);

protected:
	Solver(void);
};

std::ostream &		operator<<(std::ostream &, Solver const & src);

#endif
