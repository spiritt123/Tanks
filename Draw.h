#pragma once
#include "Coordinate.h"

/*
	������� ������������ �����
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
	������� ������� ���������
*/

void Draw(Player& player, Window& window, Map& map) {
	// �������� ����
	window.clear();
	// ������������ �����
	map_formation_map_draw(window, map);
	// �������� ��������� �� �����
	window.draw(player.getSprite());
	// ������� ����� �� �����
	window.display();
}
