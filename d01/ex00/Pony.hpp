#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony
{
public:
	Pony(std::string name);
	~Pony(void);
	bool			setAge(int age);
	int				getAge(void) const;
	void			display(void) const;

private:
	std::string 	_name;
	std::string 	_kind;
	std::string	 	_color;
	int			 	_age;
};

#endif
