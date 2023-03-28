#ifndef SIERPINSKI_HPP_
#define SIERPINSKI_HPP_
#include <SFML/Graphics.hpp>

class Sierpinski: public sf::Drawable {
  public:
    Sierpinski(sf::Vector2f, sf::Vector2f, sf::Vector2f, int);
    Sierpinski(int, int);

    ~Sierpinski();

      void filledTriangle(sf::Vector2f set_point[3], sf::RenderTarget& target, sf::RenderStates states) const;

      void sierpinski(double x, double y, double z, int count, sf::RenderTarget& target, sf::RenderStates states) const;

  private:

    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::ConvexShape triangle;
      sf::Vector2f _top, -left, _right;
      int _depth;
    int count;
      Sierpinski* _child1;
      Sierpinski* _child2;
      Sierpinski* _child3;
};

#endif  /* end SIERPINSKI_HPP_ */