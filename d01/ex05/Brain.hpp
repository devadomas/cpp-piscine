#ifndef BRAIN_HPP
# define BRAIN_HPP

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
