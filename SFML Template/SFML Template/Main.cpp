#include <iostream>
#include <SFML/Graphics.hpp>

/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

int main()
{
	/** Prepare the window */
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Test");
	window.setFramerateLimit(60);

	sf::Texture texture;

	if (!texture.loadFromFile("res/img/Brick.jpg"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}

	texture.setRepeated(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 640, 480));
	sprite.setColor(sf::Color(0, 0, 255));

	sf::Font font;

	if (!font.loadFromFile("res/fonts/FontFile.ttf"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}

	sf::Text  text;
	text.setFont(font);
	text.setString("Hello World !!!");
	text.setCharacterSize(256);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	text.setOutlineColor(sf::Color::Yellow);
	text.setOutlineThickness(-2);


	/*
	POSITION CODE
	*/
	//sprite.setPosition( sf::Vector2f( 320, 240 ) );

	//sprite.move( sf::Vector2f( 50, 0 ) );

	sf::Vector2f position = sprite.getPosition();
	//position.x;
	//position.y;


	/*
	ROTATION CODE
	*/
	//sprite.setRotation( 45 );

	//sprite.rotate( 10 );

	float rotation = sprite.getRotation();


	/*
	SCALING CODE
	*/
	//sprite.setScale( sf::Vector2f( 1.0f, 2.0f ) );

	//sprite.scale( sf::Vector2f( 0.5f, 0.5f ) );

	sf::Vector2f scale = sprite.getScale();
	//scale.x;
	//scale.y;


	/*
	ORIGIN CODE
	*/
	sf::Rect<float> size = sprite.getGlobalBounds();

	//sprite.setOrigin( sf::Vector2f( size.width / 2, size.height / 2  ) );

	//sprite.setRotation( 45 );

	//sprite.setScale( 2.0f, 1.25f );



	//window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;

		bool isKeyPressed = false;
		bool isMouseMoving = false;

		// handle all events
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			case sf::Event::EventType::Resized:
				std::cout << event.size.width << " : " << event.size.height << std::endl;

				break;

			case sf::Event::EventType::LostFocus:
				std::cout << "Lost focus" << std::endl;

				break;

			case sf::Event::EventType::GainedFocus:
				std::cout << "Gained focus" << std::endl;

				break;

			case sf::Event::EventType::TextEntered:
				if (event.text.unicode < 128)
				{
					//std::cout << static_cast<char>(event.text.unicode) << std::endl;
				}

				break;

			case sf::Event::EventType::KeyPressed:
				std::cout << "Key has been pressed" << std::endl;

				if (sf::Keyboard::Left == event.key.code)
				{
					std::cout << "Left key has been pressed" << std::endl;
				}

				std::cout << "Control: " << event.key.control << std::endl;
				std::cout << "Alt: " << event.key.alt << std::endl;
				std::cout << "Shift: " << event.key.shift << std::endl;
				std::cout << "System: " << event.key.system << std::endl;

				isKeyPressed = true;

				break;

			case sf::Event::EventType::KeyReleased:
				std::cout << "Key has been released" << std::endl;

				if (sf::Keyboard::Left == event.key.code)
				{
					std::cout << "Left key has been released" << std::endl;
				}

				isKeyPressed = false;

				break;

			case sf::Event::EventType::MouseButtonPressed:
				std::cout << "Mouse button pressed" << std::endl;

				if (sf::Mouse::Button::Left == event.mouseButton.button)
				{
					std::cout << "Left Mouse Button Pressed" << std::endl;
				}

				break;

			case sf::Event::EventType::MouseButtonReleased:
				std::cout << "Mouse button released" << std::endl;

				if (sf::Mouse::Button::Left == event.mouseButton.button)
				{
					std::cout << "Left Mouse Button Released" << std::endl;
				}

				break;

			case sf::Event::EventType::MouseWheelScrolled:
				std::cout << "Mouse Wheel Is Being Scrolled" << std::endl;

				std::cout << event.mouseWheelScroll.delta << std::endl;

				break;

			case sf::Event::EventType::MouseMoved:
				//std::cout << event.mouseMove.x << " : " << event.mouseMove.y << std::endl;

				isMouseMoving = true;

				break;

			case sf::Event::EventType::MouseLeft:
				std::cout << "Mouse has left the window" << std::endl;

				break;

			case sf::Event::EventType::MouseEntered:
				std::cout << "Mouse has entered the window" << std::endl;

				break;

			case sf::Event::EventType::JoystickButtonPressed:
				std::cout << "Joystick button pressed" << std::endl;

				break;

			case sf::Event::EventType::JoystickButtonReleased:
				std::cout << "Joystick button released" << std::endl;

				std::cout << "Joystick ID : " << event.joystickButton.joystickId << std::endl;

				std::cout << "Joystick Button : " << event.joystickButton.button << std::endl;

				break;

			case sf::Event::EventType::JoystickMoved:
				//std::cout << "Joystick has been moved" << std::endl;

				if (sf::Joystick::Axis::X == event.joystickMove.axis)
				{
					std::cout << event.joystickMove.position << std::endl;
				}

				break;

			case sf::Event::EventType::JoystickConnected:
				std::cout << "Joystick connected" << std::endl;

				break;

			case sf::Event::EventType::JoystickDisconnected:
				std::cout << "Joystick disconnected" << std::endl;

				break;

			}

			if (sf::Event::EventType::JoystickDisconnected == event.type)
			{
				// do something the same way
			}

			if (isKeyPressed && isMouseMoving)
			{
				std::cout << "Multiple Events" << std::endl;
			}
		}

		// update the game

		window.clear();
		window.draw(sprite);
		window.draw(text);
		window.display();
	}

	return EXIT_SUCCESS;
}
