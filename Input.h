#pragma once

/*
    Обработка ввода
*/

void Input(Player& player, Window& window, Map& map) {

    sf::Event event;
    while (window.get_window().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.up();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.left();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.down();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.right();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        window.close();
    }
}
