#ifndef LOGGER_CLASS_HPP
# define LOGGER_CLASS_HPP

# include <string>

class Logger {

public:
	std::string	makeLogEntry(std::string const & str);
private:
	void		logToConsole(std::string const & str);
	void		logToFile(std::string const & str);
};

#endif
