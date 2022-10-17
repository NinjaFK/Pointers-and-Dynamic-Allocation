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

/*	Reads a team from a given file. The file will always be formatted
	such that the first line contains the team name. The next nine lines
	will contain the nine players, with the number first.
	Followed by their name. The order of players in files is always:
	Catcher, Pitcher, First, Second, Shortstop, Third,
	Right Field, Center Field, Left Field*/
Team::Team(ifstream &file)
{
	string name;
	int number;
	// Read team name first (Remember, the name can have spaces. Try to avoid using >>)
	getline(file, teamName);
	//
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		file >> number;
		getline(file, name);
		roster[i] = new Player(name, number, Position(i));
	}
	// Finally increment the count of teams
	teamCount++;
}

/*Goes through the roster and deletes each player*/
Team::~Team()
{
	for (int i = 0; i < TEAM_SIZE; i++)
		delete roster[i];
}