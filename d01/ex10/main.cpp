#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

static bool		isDirectory(std::string const & filename)
{
    struct stat buf;
	char f[filename.length() + 1];

	strcpy(f, filename.c_str());
    stat(f, &buf);
    return S_ISDIR(buf.st_mode);
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
