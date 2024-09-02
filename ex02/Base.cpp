#include "Base.hpp"


Base::~Base(void){}

Base	*generate(void)
{
	int	rng;

    srand(time(NULL));
    rng = rand() % 3 + 1;
    std::cout<<rng<<std::endl;
	if (rng == 1)
	{
		std::cout << "Generated class A\n";
		return new A;
	}
	if (rng == 2)
	{
		std::cout << "Generated class B\n";
		return new B;
	}
	std::cout << "Generated class C\n";
	return new C;
}

void	identify(Base *p)
{
    std::cout << "Indentified by pointer....." << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "Base object is : A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Base object is : B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Base object is : C\n";
	else
		std::cout << "Incorrect object\n";
}

void	identify(Base &p)
{
	Base	tmp; 
    try 
    {
        tmp = dynamic_cast<A &>(p);
        std::cout << "Base object is : A\n";
        return ;
    }
    catch (std::exception const &e)
    {
        try 
        {
            tmp = dynamic_cast<B &>(p);
            std::cout << "Base object is : B\n";
            return ;
        }
        catch (std::exception const &e1)
        {
            try 
            {
                tmp = dynamic_cast<C &>(p);
                std::cout << "Base object is : C\n";
                return ;
            }
            catch (std::exception const &e2)
            {
                std::cerr << "Error: " << e2.what() << '\n';
            }
        }
    }
    std::cout << "Incorrect object\n";
 }