#ifndef INCLUDED_HEIGHTMAP_H
#define INCLUDED_HEIGHTMAP_H

#include <string>
#include <vector>

#include <SFML/Graphics/Image.hpp>

template <class Generator>
class Heightmap
{
public:
	Heightmap (unsigned width, unsigned height, const std::string &save_directory) :
		width(width),
		height(height),
		save_directory(save_directory),
		values(Generator::Generate(width, height)),
		is_img_loaded(false)
	{}

	~Heightmap ()
	{}

	const std::vector<unsigned char> getValues () const
	{ return values; }

	const sf::Image& toImage () 
	{
		if (!is_img_loaded)
			{
				auto it(values.cbegin());
				img.create(width, height);
				for (unsigned i(0); i < height; ++i)
					{
						for (unsigned j(0); j < width; ++j)
							{
								img.setPixel(j, i, sf::Color(*it, *it, *it));
								++it;
							}
					}
				is_img_loaded = true;
			}

		return img;
	}

private:
	unsigned width, height;
	std::string save_directory;
	std::vector<unsigned char> values;

	sf::Image img;
	bool is_img_loaded;
};


#endif /* INCLUDED_HEIGHTMAP_H */
