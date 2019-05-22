#include <iostream>
#include <fstream>
#include <sstream>

static bool     isDirectory(std::string const filename)
{
	int				len;
	std::ifstream	ifs;

	ifs.open(filename);
	if (!ifs.is_open())
		return false;
	ifs.seekg(0, ifs.end);
	len = ifs.tellg();
	ifs.seekg(0, ifs.beg);
	char	buff[len];
	ifs.read(buff, len);
	if (!ifs) {
		ifs.close();
		return true;
	}
	ifs.close();
	return false;
}

static void		readFromFile(std::string const & filename)
{
	std::ifstream		in;
	std::stringstream	sStream;

	if (isDirectory(filename))
	{
		std::cerr << "cato9tails: " << filename << ": Is a directory" << std::endl;
		return ;
	}

	in.open(filename);
	if (in.is_open())
	{
	    sStream << in.rdbuf();
		std::cout << sStream.str();
		in.close();
	}
	else
		std::cerr << "cato9tails: " << filename << ": " << std::strerror(errno) << std::endl;
}

static void		readFromStdin(void)
{
	std::string line;

	while (std::getline(std::cin, line))
		std::cout << line << std::endl;
}

int				main(int argc, char const **argv) {
	if (argc == 1)
		readFromStdin();
	else
	{
		for (int i = 1 ; i < argc ; i++)
			readFromFile(argv[i]);
	}
}
