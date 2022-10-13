#include "team.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Static intializers for counts (done outside class bodies)
int Player::playerCount = 0;
int Team::teamCount = 0;

/*----------------- Player function implementations -----------------*/

/* Returns all of the Player's variable members in a formatted string for displaying */
string Player::toString()
{
	return getPositionString(position) +
		   (position == Position::PITCHER || position == Position::CATCHER ? "  " : " ") +
		   to_string(number) + (number < 10 ? " " : "") + " : " + name;
}

/* Returns the string corresponding to the given postion */
string Player::getPositionString(Position pos)
{
	return positionNames[(int)pos];
}

/*Set the Player's member variables to the corresponding parameters.
  Recall how to resolve ambiguity between the same names.*/
Player::Player(string name, int number, Position pos)
	: position(pos)
{
	this->name = name;
	this->number = number;
}

/*----------------- Team function implementations -----------------*/
/* Prints the team's name and then all of the Players */
void Team::printTeam()
{
	// First print the team's name and then all of the players
	cout << "---------- " << teamName << " ----------" << endl;
	// Print all of the players on the team's roster to cout by getting each Player as a string
	for (int i = 0; i < TEAM_SIZE; i++)
		cout << roster[i]->toString() << endl;
	cout << endl;
}

/**/
Team::Team(ifstream &file)
{
	// Reads a team from a given file. The file will always be formatted such that
	// the first line contains the team name. The next nine lines will contain the nine players, with the number first
	// Followed by their name. The order of players in files is always:
	// Catcher, Pitcher, First, Second, Shortstop, Third, Right Field, Center Field, Left Field

	// HINT: When reading and creating the players, you can either make nine Player objects in order with the
	// positions listed above, or use a for loop and cast the enumeration type.

	// Start by reading the name, then read each player by using the given variables and then constructing a new
	// Player object to be added to the roster array. The first Player is given for you as an example

	// Finally increment the count of teams

	string name;
	int number;
	// Read team name first (Remember, the name can have spaces. Try to avoid using >>)

	// TODO

	// Get the catcher (You can replace this if you know how to do the for loop method)
	// You can also change this to a separate function if you prefer to encourage code re-use

	// TODO
	file >> number;		 // Read the catcher's number
	getline(file, name); // Read the catcher's name
	// Set the first person on the roster to be the catcher with the info we read
	roster[0] = new Player(name, number, Position::CATCHER);
}

/**/
Team::~Team()
{
	// Go through and deallocate all of the Players on the Team
	// Since the roster array itself is static, there is no need to delete the array, just the stuff in it
	// This should be about 2 lines of code
}