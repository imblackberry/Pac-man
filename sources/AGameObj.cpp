#include "AGameObj.hpp"

AGameObj::AGameObj() : _x(0), _y(0), _shape(0), _direction(0){
}
AGameObj::AGameObj(size_t const & x, size_t const & y, wchar_t const & shape) :
	_x(x), _y(y), _shape(shape), _direction(0){
}

AGameObj::AGameObj(AGameObj const & other){
	*this = other;
}
AGameObj & AGameObj::operator = (AGameObj const & other){
	if (this != &other){
		_x = other._x;
		_y = other._y;
		_shape = other._shape;
		_direction = other._direction;
	}
	return *this;
}
AGameObj::~AGameObj(){}
void	AGameObj::move(vector<vPair> & map){
	size_t y = _y;
	size_t x = _x;

	switch(_direction){
		case 'w':
			y--;
		break ;
		case 's':
			y++;
		break ;
		case 'a':
			x--;
		break ;
		case 'd':
			x++;
		break ;
	}
	// moveByDirection();
	if (coordOnTheBorder(map, x, y))
		return ;
	_x = x;
	_y = y;

}

bool	AGameObj::coordOnTheBorder(vector <vPair> & map, size_t x, size_t y) const{
	if (map[y][x].second == COLOR_BORDER || map[y][x + 1].second == COLOR_BORDER)
		return true;
	return false;
}
size_t &AGameObj::getX(){
	return _x;
}
size_t &AGameObj::getY(){
	return _y;
}
int	&AGameObj::getDirection(){
	return _direction;
}
void	AGameObj::setX(size_t const & x){
	_x = x;
}
void	AGameObj::setY(size_t const & y){
	_y = y;
}
void	AGameObj::setDirection(int const & direction){
	_direction = direction;
}
void	AGameObj::showShape(WINDOW *wMap) const{
	mvwprintw(wMap, _y, _x, "%C", _shape);
}
