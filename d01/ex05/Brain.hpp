#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>

class Brain
{
public:
	Brain(void);
	~Brain(void);
	std::string		identify(void) const;
private:
	int				_size;
	int				_brainCells;
};

#endif
