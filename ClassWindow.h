#pragma once
#include "Constants.h"
/*
    Класс, который представляет главное окно
*/

class Window {
private:
    sf::RenderWindow _window;
protected:
public:
    Window(const char*);
    ~Window();

    sf::RenderWindow& get_window();

    /*
        Функция-обертка для clear() из sfml
    */
    void clear();
    /*
        Функция-обертка для draw() из sfml
    */
    void draw(const sf::Sprite&);
    /*
        Функция-обертка для display() из sfml
    */
    void display();
    /*
        Функция-обертка для close() из sfml
    */
    void close();
};

Window::Window(const char *name_window) {
    _window.create
    (
        sf::VideoMode(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT),
        name_window
     );
}

Window::~Window() {

}

sf::RenderWindow& Window::get_window() {
    return _window;
}

void Window::clear() {
    _window.clear(sf::Color::White);
}

void Window::draw(const sf::Sprite& obj) {
    _window.draw(obj);
}

void Window::display() {
    _window.display();
}

void Window::close() {
    _window.close();
}

// ---------------------------------------------------
// ---------------------------------------------------
