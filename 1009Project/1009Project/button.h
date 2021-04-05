#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
	bool pressed;
	bool hover;
};
