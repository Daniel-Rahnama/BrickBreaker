# Brick Breaker

## Dependencies for Building Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/).
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros.
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/).
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm).
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation).
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros.
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/).
  * Windows: recommend using [MinGW](http://www.mingw.org/).
  
## Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`.
3. Compile: `cmake .. && make`.
4. Run it: `./BrickBreaker`.

## Project Details
I have built a BrickBreaker game. The idea of the game is that a surface is used to allow a bullet to bounce on it, in order to change the direction of the bullet to get it to collide with the bricks.

## Rubric Points
1. Functions are used throughout the code.
2. The Function accepts user input and processes output in 'Controller.cpp'.
3. OOP is used throughout the code.
4. Public, Protected or Private member variables are used in 'Game.hpp'.
5. Class constructors use member initialisation lists in 'Game.hpp'.
6. Inheritance is used with classes Player, Bullet and Brick all inheriting from Entity.
7. References are used throughout the code, such as in 'Game.hpp' line 19.
8. Smart Pointers are used in 'Game.cpp' lines 21-23.
9. Multithreading is used via std::async in 'Renderer.cpp' line 37.
10. A mutex is used in the project in 'Renderer.cpp' line 57.
