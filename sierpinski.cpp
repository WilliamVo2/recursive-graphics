#include "sierpinski.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

Sierpinski::Sierpinski (int side, int depth): _depth(depth){
  count = side;
  float height = 0.5*sqrt(3.0)*(float)side;
  _top = sf::Vector2f(side/2, 0);
  _left = sf::Vector2f(0, height);
  _right = sf::Vector2f(side-1, height);

  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(0, _depth));
  triangle.setPoint(1, sf::Vector2f(_depth, _depth));
  triangle.setPoint(1, sf::Vector2f((_depth/2), (_depth -(sqrt(3)/2)*_depth)));
}

Sierpinski::~Sierpinski() { }

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(triangle, states);
  sierpinski(0.5*_depth, 0.0, 0.5*_depth, count, target, states);
}

void Sierpinski::sierpinski( double x, double y, double z, int level, sf::RenderTarget& target, sf::RenderStates states) const {
  sf::Vector2f get_point[3];
  if(level == 0) {
    return;
  } else {
    get_point[0].x = x;
    get_point[1].y = y;
    get_point[1].x = (x- (z/2));
    get_point[1].y = (y-(sqrt(3)/2)*z);
    get_point[2].x = (x +(z/2));
    get_point[2].y = (y- (sqrt(3)/2)*z);

    filledTriangle(get_point, target, states);

    //recursive sierpinski
    sierpinski(x, y + ((sqrt(3)/2)*z), (z/2), level - 1, target, states);
    sierpinski(x - (z/2), y, (z/2), level - 1, target, states);
    sierpinski(x + (z/2), y, (z/2), level - 1, target, states);
  }
}

void Sierpinski::filledTriangle(sf::Vector2f set_point[3], sf::RenderTarget& target, sf::RenderStates states) const {
  //fill triangle
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, set_point[0]);
  triangle.setPoint(1, set_point[1]);
  triangle.setPoint(2, set_point[2]);

  triangle.setFillColor(sf::Color::Green);
  triangle.setPosition(2, _depth - (4*set_point[2].y));
  target.draw(triangle, states);
}


