#pragma once
#include <array>

class Ghosts
{

public:
	void Chase();
	void Scatter();
	void Frightened();
};

Ghosts Pinky;
Ghosts Inky;
Ghosts Blinky;
Ghosts Clyde;

//use later
std::array<Ghosts, 4> ghosts = { Ghosts(), Ghosts(), Ghosts(), Ghosts() }; //Ghost() is the constructor call to create a new instance/object of Ghost 
