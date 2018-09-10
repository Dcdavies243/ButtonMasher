// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// entry point for the program
int main()
{
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "ButtonMasher", sf::Style::Titlebar | sf::Style::Close);

	//--------------------------------------------
	// Game Setup
	//--------------------------------------------


	//Create Sprites
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/knight1.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	//Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainfont.ttf");
	
	//Create Title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(75);
	titleText.setFillColor(sf::Color::Red);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	// Create Author Text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Donald Davies");
	authorText.setCharacterSize(75);
	authorText.setFillColor(sf::Color::Red);
	authorText.setStyle(sf::Text::Bold | sf::Text::Italic);
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 120);


	//Create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();


	//--------------------------------------------
	// Game Loop
	//--------------------------------------------
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
		//Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//Draw Everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);

		gameWindow.display();
	}

	//exit point for the program
	return 0;
}