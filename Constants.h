#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
	�������� ����� pi -
	��� ���������� ��� ������
	� ��������
*/

#define _USE_MATH_DEFINES
#include <math.h>

namespace constants {

	const int WINDOW_WIDTH = 1920;			  //������ �������� ����
	const int WINDOW_HEIGHT = 1080;			  //������ �������� ����
	const int NUMBER_OF_ENEMIES = 1;		  //���������� ������
	const int PLAYERS_HEALTH = 100;			  //�������� �������� ������
	const int ENEMY_HEALTH = 40;              //�������� �����
	const int HEALTH_OF_THE_ENEMY = 20;		  //�������� �����
	const int MAP_WIDTH = 40;				  //������ �����
	const int MAP_HEIGHT = 25;				  //������ �����
	const int CARD_BLOCK_SIDE_SIZE = 64;      //���� - ���������� (px)
	const double SPEED = 1.;     			  //������ ������� ��������
	const double ENEMY_SPEED = 1.;            //������ �������� �����
	const double pi = M_PI;					  //����� ��
	const double PI_HALF = M_PI / 2.0;		  //Pi in half
	const double DOUBLE_PI = M_PI * 2.0;      //��� ��
	const double SPEED_BULLET = 1.;           //������ �������� ����
	const int MAXIMUM_BULLETS = 50; 		  //������������ ���������� ����
	const double ROTATION_SPEED = 0.003; 	  //������� ��������(���)
	const double TANK_WIDTH = 72.;		      //������ �����
	const double TANK_HEIGHT = 146.;          //������ �����
	const char* const MAP_IMAGE = "Images/Ground.jpg";
	const char* const MAP_FILE = "map.txt";
	const char* const PLAYER_FILE = "Images/Green.bmp";
	const char* const ENEMY_FILE = "Images/Red.bmp";
	const char* const NAME_WINDOW = "Tank";
	const char* const BULLET_FILE = "Images/Bullet.bmp";

}

#endif