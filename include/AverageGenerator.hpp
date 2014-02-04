#ifndef INCLUDED_AVERAGEGENERATOR_H
#define INCLUDED_AVERAGEGENERATOR_H

#include <chrono>
#include <random>
#include <vector>

#define HEIGHT_OFFSET 10

struct AverageGenerator
{
	static std::vector<unsigned char> Generate (unsigned width, unsigned height)
	{
		unsigned seed(std::chrono::system_clock::now().time_since_epoch().count());
    unsigned total_size(width*height);
    std::minstd_rand0 generator(seed);
    int base(generator() % 255);
    std::vector<unsigned char> v;

    v.reserve(total_size);

    for (unsigned i(0); i < total_size; ++i) 
      {
				if (i > width && i % width != 0)
					{ 
						base = (v[i-width] + v[i-1]) / 2;
					}

				base = (base + (((generator() % 10) < 5) ? -1 : 1) * (generator() % HEIGHT_OFFSET));

				if (base > 255) { base = 255; }
				else if (base < 0) { base = 0; }
				v.push_back(static_cast<char>(base));
      }

    return v;
	}
};

#endif /* INCLUDED_AVERAGEGENERATOR_H */
