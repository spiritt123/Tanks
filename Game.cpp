#include "Game.h"

Game::Game() : _player(constants::PLAYER_FILE, constants::PLAYERS_HEALTH, constants::SPEED)
{
	/*
		�������������� ������� ������
	*/
    for (int i = 0; i < constants::NUMBER_OF_ENEMIES;++i) {
        _enemyList.resize(_enemyList.size() + 1);
    }
}

Game::~Game() {

}

void Game::Setup() {
    /*
        ������������� ������ �� ������
    */
    _view.setCenterCam(_player.getCoordinate());
    /*
        ���������� �����
    */
    _map.load_map_image(constants::MAP_IMAGE);
    _map.load_map_from_file(constants::MAP_FILE);
    /*
        ��������� ����
    */
    _window.createWindow(constants::NAME_WINDOW);
    _window.setView(_view);
    /*
        ������� ������
    */
    std::list<Enemy>::iterator iter = _enemyList.begin();
    coordinate::Coordinate C;
    for (int i = 0; i < constants::NUMBER_OF_ENEMIES; ++i) {
        srand(static_cast<unsigned int>(time(0)+i+_clock.getElapsedTime().asMicroseconds()));
        C.x = rand() % (constants::MAP_WIDTH * constants::CARD_BLOCK_SIDE_SIZE);
        C.y = rand() % (constants::MAP_HEIGHT * constants::CARD_BLOCK_SIDE_SIZE);
        iter->setCoordinate(C);
        ++iter;
    }
}

void Game::Input() {
    while (_window.get_window().pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _endGame = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _player.motion(true, _clock);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _player.rotation(-constants::ROTATION_SPEED, _clock);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _player.motion(false, _clock);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _player.rotation(constants::ROTATION_SPEED, _clock);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        _endGame = true;
    }
    static sf::Clock timer;
    double time = timer.getElapsedTime().asMilliseconds();
    _player.setShoot(
        (
            sf::Keyboard::isKeyPressed(sf::Keyboard::K)
            ||
            sf::Mouse::isButtonPressed(sf::Mouse::Left)
        ) 
        && time>500
     );
    if (_player.getShoot()) {
        timer.restart();
    }
    /*
        ������������� ����
    */
    _clock.restart();
}

void Game::Logic() {
    if (!_endGame) {
        if (_player.checkCoordinates())
        {
            /*
                �������� �������,
                �������� �������� �����
                �� ������������� ��������
            */
            _player.commitChanges();
        }
        else {
            /*
                �������� �������������
                ���������
            */
            _player.discardChanges();
        }
        if (_player.getShoot()) {
            _player.shoot();
        }
        _player.BulletFlightHandler(_clock);
        collisionHandler();
        enemyMovementHandler();
    }
    if (_player.get_health() == 0) {
        _endGame = true;
    }
}

void Game::Draw() {
    std::list<Enemy>::const_iterator iter = _enemyList.begin();
    std::list<Enemy>::const_iterator eiter = _enemyList.end();
    _window.clear();
    /*
        ������ �����
    */
    _map.drawMap(_window);
    /*
        ������ ���� ������ � ������
    */
    while (iter != eiter) {
        iter->drawBullets(_window);
        ++iter;
    }
    _player.drawBullets(_window);
    /*
        ������ ������ � ������
    */
    iter = _enemyList.begin();
    eiter = _enemyList.end();
    while (iter != eiter) {
        _window.draw(iter->getSprite());
        ++iter;
    }
    _window.draw(_player.getSprite());
    /*
        ������������� ������ �� ������
    */
    _view.setCenterCam(_player.getCoordinate());
    _window.setView(_view);
    /*
        ������� ��� �� �����
    */
    _window.display();
}

void Game::Run() {
	while (!_endGame) {
        Draw();
        Logic();
		Input();
	}
    _window.close();
}

void Game::enemyMovementHandler() {
    static sf::Clock timer;
    double time = timer.getElapsedTime().asSeconds();
    std::list<Enemy>::iterator iter = _enemyList.begin();
    std::list<Enemy>::iterator eiter = _enemyList.end();
    while (iter != eiter) {
        if (iter->get_health() > 0) {
            iter->rotation(constants::ROTATION_SPEED, _clock);
            iter->motion(true, _clock);
            iter->commitChanges();
            if (time > 3) {
                iter->shoot();
                timer.restart();
            }
            iter->BulletFlightHandler(_clock);
            ++iter;
        }
        else {
            iter = _enemyList.erase(iter);
        }
    }
    
}

void Game::collisionHandler() {
    /*
        ������������ ���� ������
    */
    std::list<Enemy>::iterator enemIter = _enemyList.begin();
    std::list<Enemy>::iterator eenemIter = _enemyList.end();
    std::list<Bullet>::iterator iter = _player.getStorageBullet().begin();
    std::list<Bullet>::iterator eiter = _player.getStorageBullet().end();
    while (enemIter != eenemIter) {
        iter = _player.getStorageBullet().begin();
        while (iter != eiter) {
            if (enemIter->searchInField(iter->getCoordinate())) {
                iter->setFly(false);
                enemIter->reduce_health(20);
            }
            ++iter;
        }
        ++enemIter;
    }
}