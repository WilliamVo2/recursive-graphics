#include "triangle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using  namespace std;

int main(int argc, char*argv[]) {
  if(argc<3) {
    cout<<"sierpinski [recursion-depth] [side-length]" <<endl;
    return -1;
  }
  int depth = atoi(argv[1]);
  int side = atoi(argv[2]);
  Sierpinski s(side, depth);

  sf::RenderWindow
    window(sf::VideoMode(side, (int)(0.5*sqrt(3.0)*(float)side)), "Original Sierpinski triangle");
  window.setFramerateLimit(1);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed){
        window.close();
        break;
      }
    }
    window.clear();
    window.draw(s);
    window.display();
  }

  return 0;
}