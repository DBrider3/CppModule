#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base
{
	public:
		B();
		~B();
		B(B& copy);
		B& operator = (const B& b);
};

#endif
