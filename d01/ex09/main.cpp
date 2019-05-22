#include "Logger.hpp"

int		main (void)
{
	Logger		logger;

	logger.log("logToConsole", "Logging to console..");
	logger.log("logToFile", "Logging to file");
	logger.log("garbagehaha", "Garbage");
}
