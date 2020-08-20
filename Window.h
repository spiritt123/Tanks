#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H


#include "Constants.h"
#include "View.h"
/*
    �����, ������� ������������ ������� ����
*/

class Window {
private:
    sf::RenderWindow _window;
protected:
public:
    Window();
    ~Window();

    void createWindow(const char* const);
    sf::RenderWindow& get_window();

    void setView(view&);
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

#endif
