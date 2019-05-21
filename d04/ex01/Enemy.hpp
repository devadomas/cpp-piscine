#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include <string>

class Enemy
{
public:
	Enemy(void);
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & src);
	virtual ~Enemy(void);
	Enemy &				operator=(Enemy const & src);
	std::string			getType(void) const;
	int					getHp(void) const;
	void				setHp(int hp);

	virtual void		takeDamage(int damage);

private:
	int			_hp;
	std::string	_type;
};

#endif
