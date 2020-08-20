#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include "Constants.h"

class view {
private:
	sf::View _view;
protected:
public:
	view();
	~view();
	/*
		set the coordinates of the center of the camera
		(���������� ���������� ������ ������)
	*/
	void setCenterCam(coordinate::Coordinate&);

	sf::View& getView();
};

#endif 

