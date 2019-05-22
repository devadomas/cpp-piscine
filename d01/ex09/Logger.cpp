#include "Logger.hpp"

std::string const			Logger::_file = "data.log";

Logger::Logger(void) {}
Logger::~Logger(void) {}

void			Logger::logToConsole(std::string const & str) const
{
	std::cout << str << std::endl;
}

void			Logger::logToFile(std::string const & str) const
{
	std::ofstream		out;

	out.open(this->_file, std::ofstream::out | std::ofstream::app); // new or append

	if (out.is_open())
	{
		out << str << std::endl;
		out.close();
	}
	else
		std::cerr << this->_file << ": " << std::strerror(errno) << std::endl;
}

std::string		Logger::makeLogEntry(std::string const & str) const
{
	char strtime[19];

	std::time_t time = std::time(nullptr);
	std::strftime(strtime, sizeof(strtime), "[%Y%m%d_%H%M%S] ", std::localtime(&time));
	return (strtime + str);
}

void			Logger::log(std::string const & dst, std::string const & str)
{
	std::string		options[] = {
		"logToConsole",
		"logToFile"
	};
	typedef void	(Logger::*Log)(std::string const & str) const;
	Log				select[2] = {&Logger::logToConsole, &Logger::logToFile};

	for (int i = 0; i < 2; i++)
	{
		if (options[i] == dst)
		{
			(this->*(select[i]))(this->makeLogEntry(str));
			return ;
		}
	}
}
