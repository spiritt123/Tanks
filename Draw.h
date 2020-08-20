#pragma once
#include "Coordinate.h"

/*
	Функция формирования карты
*/

void map_formation_map_draw(Window& window, Map& map) 
{
	coordinate::Coordinate Coor;
	for (int Y = 0; Y < constants::MAP_HEIGHT - 1; ++Y) 
	{
		Coor.y = Y;
		for (int X = 0; X < constants::MAP_WIDTH - 1; ++X) 
		{
			Coor.x = X;
			if ( map.check_point_on_the_map(Coor) ) 
			{
				window.draw(map.get_curr_Sprite());
			}
		}

	}
}

/*
	Главная функция отрисовки
*/

void Draw(Player& player, Window& window, Map& map) {
	// очистить окно
	window.clear();
	// сформировать карту
	map_formation_map_draw(window, map);
	// добавить персонажа на карту
	window.draw(player.getSprite());
	// вывести карту на экран
	window.display();
}
