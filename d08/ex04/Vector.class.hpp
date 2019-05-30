#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include <iostream>
#include <string>

class Vector
{
public:
	Vector(void);
	Vector(Vector const & src);
	~Vector(void);
	Vector&				operator=(Vector const & src);
	std::string			operator[](int index) const;

	int					size(void) const;
	std::string*		getArray(void) const;
	bool				empty(void) const;
	void				reverse(void);
	void				push(std::string const & str);
	std::string			pop(void);
	std::string			back(void) const;
	void				removeAt(int idx);
	void				insertAt(int idx, std::string value);

private:
	int				_count;
	std::string*	_array;

};

std::ostream &			operator<<(std::ostream &, Vector const & src);

#endif
