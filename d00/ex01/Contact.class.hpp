#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{
public:
	std::string	getFirstname(void) const;
	bool		setFirstname(std::string name);
	std::string	getLastname(void) const;
	bool		setLastname(std::string name);
	std::string	getNickname(void) const;
	bool		setNickname(std::string name);
	std::string	getLogin(void) const;
	bool		setLogin(std::string login);
	std::string	getPostal(void) const;
	bool		setPostal(std::string code);
	std::string	getEmail(void) const;
	bool		setEmail(std::string email);
	std::string	getPhone(void) const;
	bool		setPhone(std::string phone);
	std::string	getBirthday(void) const;
	bool		setBirthday(std::string date);
	std::string	getFavmeal(void) const;
	bool		setFavmeal(std::string meal);
	std::string	getUnderwear(void) const;
	bool		setUnderwear(std::string underwear);
	std::string	getSecret(void) const;
	bool		setSecret(std::string secret);

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _login;
	std::string _postal;
	std::string _email;
	std::string _phone;
	std::string _birthday;
	std::string _favmeal;
	std::string _underwearclr;
	std::string _secret;
};

#endif
