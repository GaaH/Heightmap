#include <iostream>

#include "Heightmap.hpp"

struct Generator
{
	static std::vector<unsigned char> Generate (unsigned w, unsigned h)
	{
		std::vector<unsigned char> v;
		v.reserve(w*h);
		for (unsigned i(0); i < w*h; ++i) 
			{
				v.push_back(static_cast<char>(i % 255));
			}

		return v;
	}
};

int main()
{
	Heightmap<Generator> hm(50, 50);


	return 0;
}

