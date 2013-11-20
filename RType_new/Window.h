
#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define WIDTH	800
#define	HEIGHT	600

class Window
{
public:
    public :
 
        void Sleep(float duration);
        void Create(int width, int height, std::string title);
        void SetFPS(unsigned int limit);
        void Close();
        bool IsOpen() const;
        void Update();
        bool Clear();
        bool GetEvent(sf::Event& event);
 
    private :
 
        ~Window();
        Window();
        Window(const Window&);
 
        sf::RenderWindow _window;
};

#endif