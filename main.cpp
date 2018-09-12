// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

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


	//Create prompt
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click to start the game!");
	promptText.setCharacterSize(75);
	promptText.setFillColor(sf::Color::Red);
	promptText.setStyle(sf::Text::Bold | sf::Text::Italic);
	promptText.setPosition(gameWindow.getSize().x / 2 - promptText.getLocalBounds().width / 2, 200);

	// Create Author Text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Donald Davies");
	authorText.setCharacterSize(75);
	authorText.setFillColor(sf::Color::Red);
	authorText.setStyle(sf::Text::Bold | sf::Text::Italic);
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 120);

	//Set score as integer
	int score = 0;

	// Create Score Text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(sf::Color::Red);
	scoreText.setStyle(sf::Text::Bold | sf::Text::Italic);
	scoreText.setPosition(75, 40);

	// Create Timer Text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setCharacterSize(55);
	timerText.setFillColor(sf::Color::Red);
	timerText.setStyle(sf::Text::Bold | sf::Text::Italic);
	timerText.setPosition(1500, 40);

	// Timer Functionality
	sf::Time timeLimit = sf::seconds(20.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;


	//Click sound effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//Gameover sound effect
	sf::SoundBuffer gameoverBuffer;
	gameoverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameoverSound;
	gameoverSound.setBuffer(gameoverBuffer);

	//startgame sound effect
	sf::SoundBuffer startgameBuffer;
	startgameBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound startgameSound;
	startgameSound.setBuffer(startgameBuffer);

	bool playing = false;

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

			//Check if the event is the Mouse button pressed event
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					if (playing == true)
					{
						//Button was clicks
						score = score + 1;
					}
					else
					{
						playing = true;

						// reset the game data
						score = 0;
						timeRemaining = timeLimit;
						startgameSound.play();
					}



					//Button was clicks
					score = score + 1;

					
					clickSound.play();
				}

				
			}

			//Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}


		}

		//TODO: Update game state
		sf::Time frameTime = gameClock.restart();
		if (playing)
		{
			timeRemaining = timeRemaining - frameTime;

			if (timeRemaining.asSeconds() <= 0.0f)
			{
				timeRemaining = sf::seconds(0.0f);
				playing = false;
				promptText.setString("Your final score was " + std::to_string(score) + "!\n Click the button to start a new game");
				
				gameoverSound.play();
			}
		}


		//update our text displays based on data
		timerText.setString("Timer: " + std::to_string((int)timeRemaining.asSeconds()));
		scoreText.setString("Score: " + std::to_string(score));


		//TODO: Draw graphics
		//Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//Draw Everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);
		gameWindow.draw(promptText);

		gameWindow.display();
	}

	//exit point for the program
	return 0;
}