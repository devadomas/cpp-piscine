#ifndef LIST_CLASS_HPP
# define LIST_CLASS_HPP

# include <string>

class List
{
public:
	List(void);
	List(List const & src);
	~List(void);
	List &			operator=(List const & src);

	// get's&set's
	int				getSize(void) const;
	std::string	 *	getArr(void) const;
	// list functions
	void			pushBack(std::string const & value);
	std::string		popLast(void);
	std::string		last(void) const;

private:
	int				_size;
	std::string	*	_arr;
};

#endif
