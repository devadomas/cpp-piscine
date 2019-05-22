#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Logger {

public:
	Logger(void);
	~Logger(void);

	void		log(std::string const & dst, std::string const & str);

private:
	std::string	makeLogEntry(std::string const & str) const;
	void		logToConsole(std::string const & str) const;
	void		logToFile(std::string const & str) const;

	static std::string const		_file;
};

#endif
