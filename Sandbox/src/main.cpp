#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "Window");

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}
