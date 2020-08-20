#pragma once
#include "Constants.h"
/*
    �����, ������� ������������ ������� ����
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
        �������-������� ��� clear() �� sfml
    */
    void clear();
    /*
        �������-������� ��� draw() �� sfml
    */
    void draw(const sf::Sprite&);
    /*
        �������-������� ��� display() �� sfml
    */
    void display();
    /*
        �������-������� ��� close() �� sfml
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
