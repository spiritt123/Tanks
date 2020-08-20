#include <iostream>
#include <SFML/Graphics.hpp>
#include <string> 
#include <fstream>
#include "Tanks.h"


int main()
{
    Map map;
    map.load_map_image("Images/Ground.jpg");
    map.load_map_from_file("map.txt");

    Window window("Tank");
    Player player("Images/Tanks.png", constants::PLAYERS_HEALTH);

    
    while (window.get_window().isOpen()) {
        Draw(player, window, map);
        Input(player, window, map);
        Logic(player, window, map);
    }
}
