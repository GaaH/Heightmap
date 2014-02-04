#ifndef INCLUDED_HEIGHTMAP_H
#define INCLUDED_HEIGHTMAP_H

#include <vector>

template <class Generator>
class Heightmap
{
public:
	Heightmap (unsigned width, unsigned height) :
		width(width),
		height(height),
		values(Generator::Generate(width, height))
	{}

	~Heightmap ()
	{}

	const std::vector<unsigned char> getValues () const
	{ return values; }

private:
	unsigned width, height;
	std::vector<unsigned char> values;
};


#endif /* INCLUDED_HEIGHTMAP_H */
