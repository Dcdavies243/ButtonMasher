// Included Libraries
#include <SFML/Graphics.hpp>


// entry point for the program
int main()
{
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "ButtonMasher", sf::Style::Titlebar | sf::Style::Close);

	// Game Loop
	while (gameWindow.isOpen())
	{
		//TODO: Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//TODO: Process events

			//Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}

		}

		//TODO: Update game state

		//TODO: Draw graphics

	}

	//esit point for the program
	return 0;
}