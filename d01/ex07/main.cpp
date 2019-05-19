#include <string>
#include <iostream>
#include <fstream>

#define RETURN_FAIL	1

static bool		readFromFile(std::string **str, std::string const &filename)
{
	std::ifstream		in(filename);
	int					len;
	char				*buff;

	if (!in.is_open())
	{
		std::cout << "replace: error while opening file" << std::endl;
		return (false);
	}
	in.seekg(0, in.end);
	len = in.tellg();
	in.seekg(0, in.beg);
	buff = new char [len];
	in.read(buff, len);
	if (!in)
	{
		std::cout << "replace: error occured while reading file..." << std::endl;
		delete[] buff;
		return (false);
	}
	in.close();
	*str = new std::string(buff);
	delete[] buff;
	return (true);
}

static std::string searchReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
	std::string				ret;
	std::string::size_type	pos = 0u;

	while((pos = str.find(oldStr, pos)) != std::string::npos)
	{
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
	ret = str.c_str();
	return (ret);
}

static bool		writeToFile(std::string const &str, std::string &filename)
{
	std::ofstream out(filename.append(".replace"));

	if (!out.is_open())
	{
		std::cout << "replace: error occured while trying to write" << std::endl;
		return (false);
	}
	out << str;
	out.close();
	return (true);
}

int				main(int argc, char const **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (RETURN_FAIL);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string	*text = NULL;
	std::string output;

	if (!readFromFile(&text, filename))
		return (RETURN_FAIL);
	output = searchReplace(*text, s1, s2);
	delete text;
	if (!writeToFile(output, filename))
		return (RETURN_FAIL);
}
