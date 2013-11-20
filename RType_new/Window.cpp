#include "Window.h"

Window::Window()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
}

Window::~Window()
{

}

Window::Window(const Window&)
{

}

void Window::Sleep(float duration)
{
	
}

void 

void Window::Update()
{
	_window.display();
}