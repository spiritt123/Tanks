#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Window.h"
#include "Constants.h"
#include "Bullet.h"
#include "Coordinate.h"

/*
    �����, ������� ������������ ����� ����
    (���� ����� �����������)
*/

class Tank {
private:
    int _size_Stor;
    std::list<Bullet> _Storage_Bullet;
    coordinate::Coordinate _C;
    double _speed;
    /*
        Current deviation from the y-axis
        (������� ���������� �� ��� y,
        ��� y ����������� � 0��� �� ���������)
        ���� �������� � �������� + 
        ����������� ������� ��������
    */
    double _curr_dev_y;
    /*
        ������� ����������� ������
        (��� ������� ��������) - 
        �� ����� ���� ������ 2pi
    */
    double _direction;
    sf::Image _I;
    sf::Texture _T;
    sf::Sprite _S;
protected:
    /*
        � ������������ ��������� ��������, ����� ��������
        ��������� � ��������, � �������� ��������� � ������
    */
    double _dx;
    double _dy;
    int health;
    Tank(const char*, int, double);
    ~Tank();
public:
    /*
        ������� �� ����
        (���� �������� � ��������)
    */
    void rotation(double, sf::Clock&);
    /*
        �������� �� ������ � ������� ���������
        (�������� ����� ���� ������������� - 
        �������� � �������� �����������)
    */
    void motion(bool, sf::Clock&);
    /*
        ������������ ����������� ��������
    */
    void shoot();
    void drawBullets(Window&) const;
    std::list<Bullet>& getStorageBullet();

    const sf::Sprite& getSprite() const;
    coordinate::Coordinate& getCoordinate();
    void setCoordinate(coordinate::Coordinate&);
    double getDirection() const;

    bool searchInField(const coordinate::Coordinate&);

    void BulletFlightHandler(sf::Clock& clock);

    virtual int get_health() const = 0;
    virtual void reduce_health(int) = 0;
    virtual void increase_health(int) = 0;
    /*
        ���������� ��� ������� �� 
        ��������� �������� �����
        �����
    */
    void commitChanges();
    /*
        ���������� ������������� ���������
    */
    void discardChanges();
};

#endif