#ifndef INCLUDED_HEIGHTMAP_H
#define INCLUDED_HEIGHTMAP_H

#include <chrono>
#include <string>
#include <vector>

#include <SFML/Graphics/Image.hpp>

template <class Generator>
class Heightmap
{
public:
	Heightmap (unsigned width, unsigned height, const std::string &save_directory = "maps", const std::string &format = ".png") :
		width(width),
		height(height),
		area(width*height),
		save_directory(save_directory),
		format((format[0] != '.') ? "." + format : format),
		values(Generator::Generate(width, height)),
		is_img_loaded(false)
	{}

	~Heightmap ()
	{}

	const std::vector<unsigned char> getValues () const
	{ return values; }

	unsigned getWidth () const
	{
		return width;
	}

	unsigned getHeight () const
	{
		return height;
	}

	unsigned getArea () const
	{
		return area;
	}

	void loadImage ()
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
	}

	const sf::Image& toImage () 
	{
		if (!is_img_loaded)
			{
				loadImage();
			}

		return img;
	}

	bool saveToDisk () const
	{
		if (is_img_loaded)
			{
				unsigned timestamps(std::chrono::system_clock::now().time_since_epoch().count());
				img.saveToFile("maps/map_" + std::to_string(timestamps) + format);
				return true;
			}

		return false;
	}

private:
	unsigned width, height, area;
	std::string save_directory, format;
	std::vector<unsigned char> values;

	sf::Image img;
	bool is_img_loaded;
};


#endif /* INCLUDED_HEIGHTMAP_H */
