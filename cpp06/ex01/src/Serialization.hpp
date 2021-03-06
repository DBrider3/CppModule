#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

typedef struct Data
{
	int i;
} Data;

class Serialization
{
	public:
		Serialization();
		~Serialization();
		Serialization(Serialization& copy);
		Serialization& operator = (const Serialization& serialization);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
	private:
};

#endif
