#include <iostream>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
	ImGui::SFML::Init(window);

	sf::Time deltaTime = sf::Time::Zero;
	sf::Clock frameCounter;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			ImGui::SFML::ProcessEvent(window, evnt);
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaTime);
		ImGui::Begin("Test");
		ImGui::End();

		window.clear(sf::Color::Black);
		ImGui::SFML::Render(window);

		window.display();

		deltaTime = frameCounter.getElapsedTime();
		frameCounter.restart();
	}

	ImGui::SFML::Shutdown();
}
