#ifndef GAME_H
#define GAME_H

#include "Enemy.h"          // ����� �����
#include "Player.h"			// ����� �������� ������
#include "Map.h"			// ����� �����
#include "View.h"           // ����� ������
#include "Bullet.h"         // ����� ����
#include "Window.h"
#include "Constants.h"
#include <list>
#include <iostream>


class Game {
private:
	view _view;
	Map _map;
	Window _window;
	Player _player;
	std::list<Enemy> _enemyList;
	bool _endGame;
	sf::Clock _clock;
	sf::Event _event;
protected:
public:
	Game();
	~Game();
	/*
		������������� ���� �����
		������������ ����������
		����������
	*/
	void Setup();
	/*
		������ Input(),
		Logic() � Draw() - �����
		�������������� ������
		� ������ Run()
	*/
	/*
		Input() - ���������
		��������� ����� ������������
	*/
	void Input();
	/*
		Logic() - ��������� ������
		����
	*/
	void Logic();
	/*
		Draw() - ��������� ���������
		� ����� �� ����� � ������� 
		������ _window.display()
	*/
	void Draw();
	/*
		Run() - ��������� ������ 
		�������� �����
	*/
	void Run();
	/*
		���������� �������� ������
		��������� �������� �����������
	*/
	void enemyMovementHandler();
	/*
		���������� ������������
		��������� ������������ ��������
	*/
	void collisionHandler();
};

#endif