#pragma once

/*
	������� ��� ���������� ������ ����
*/

void Logic(Player& player, Window& window, Map& map) {
	if (player.get_health() == 0) {
		window.close();
	}
}
