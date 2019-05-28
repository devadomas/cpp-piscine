#include <iostream>

class Base { public: virtual ~Base(void) {}; };
class A : public Base { };
class B : public Base { };
class C : public Base { };

static Base	*		generate(void)
{
	int			random;
	Base *		base;

	random = rand() % 3;
	if (random == 0)
	{
		base = new A;
		std::cout << "Generated A" << std::endl;
	}
	else if (random == 1)
	{
		base = new B;
		std::cout << "Generated B" << std::endl;
	}
	else
	{
		base = new C;
		std::cout << "Generated C" << std::endl;
	}
	return base;
}

static void			identify_from_pointer(Base * p)
{
	A *		a;
	B *		b;
	C *		c;

	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
	else
		std::cout << "NONE of types" << std::endl;
}

static void			identify_from_referance(Base & p)
{

	try
	{
		A & a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		static_cast<void>(a);
	}
	catch (std::bad_cast& e)
	{
		try
		{
			B & b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			static_cast<void>(b);
		}
		catch (std::bad_cast& e1)
		{
			try
			{
				C & c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				static_cast<void>(c);
			}
			catch (std::bad_cast& e2)
			{
				std::cout << "NONE of types" << std::endl;
			}
		}
	}
}

int					main(void)
{
	Base *		base;

	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 10; i++)
	{
		base = generate();
		identify_from_pointer(base);
		identify_from_referance(*base);

		delete base;
		base = NULL;
	}

}
