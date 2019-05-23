#include "Solver.class.hpp"

bool			isNumber(std::string const & str)
{
	float number;
	std::istringstream iss(str);

    iss >> std::noskipws >> number;
    return iss.eof() && !iss.fail();
}

float			toFloat(std::string const & str)
{
	float res;
	std::istringstream iss(str);

    iss >> std::noskipws >> res;
	return res;
}
