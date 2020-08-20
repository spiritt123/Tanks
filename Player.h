#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Bullet.h"
#include "Constants.h"
#include "Tank.h"

/*
    �����, ������� ������������ ���� �������� ������
*/

class Player : public Tank {
private:
    bool _shoot;
protected:
public:
    Player(const char*, int, double);
    ~Player();

    void setShoot(bool);
    bool getShoot() const;
    /*
    �������, ��������� � ������ ������ health, ����������
    � Player ��-�� reduce_health() - � ������� ���������
    ��� ������������ ��������
    */
    int get_health() const;
    void reduce_health(int);        
    void increase_health(int);  
    /*
        ��������� �������� ���������
        �� ������������ ��������
    */
    bool checkCoordinates();
};

#endif