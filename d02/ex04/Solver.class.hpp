#ifndef SOLVER_CLASS_HPP
# define SOLVER_CLASS_HPP

# include <sstream>
# include <string>
# include "Fixed.class.hpp"
# include "List.class.hpp"

/*
	Implamentation of RPN
*/
class Solver
{
public:
	Solver(std::string const & str);
	~Solver(void);
	Solver(Solver const & src);
	Solver &		operator=(Solver const & src);

	// funs
	void			tokenize(void);
	void			build(void);
	Fixed			solve(void);

	// helpers
	List			getTokens(void) const;
	List			getSolverList(void) const; //for DEBUG

private:
	std::string		_input;
	List			_tokens;
	List			_solver;
	List			_tmp;

protected:
	Solver(void);
};

// helper function
bool			isNumber(std::string const & str);
float			toFloat(std::string const & str);

#endif
