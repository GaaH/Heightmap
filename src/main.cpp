#include <iostream>

#include "Heightmap.hpp"
#include "AverageGenerator.hpp"

#include <SFML/Graphics.hpp>

#define WIDTH 500
#define HEIGHT 500
 
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
	Heightmap<AverageGenerator> hm(WIDTH, HEIGHT, "maps");
	hm.loadImage();
	hm.saveToDisk();
	// sf::RenderWindow app(sf::VideoMode(WIDTH, HEIGHT), "Heightmap");

	// sf::RectangleShape r(sf::Vector2f(WIDTH, HEIGHT));
	// sf::Texture tex;
	// tex.loadFromImage(hm.toImage());
	// r.setTexture(&tex);

	// while (app.isOpen())
	// 	{
	// 		app.clear();
	// 		app.draw(r);
	// 		app.display();
	// 	}

	return 0;
}

