/*
	Name: Brian, 5008139573, 1005, 4
	Description: Pointers and Dynamic Allocation
	Input: Files of players and a team anme
	Output: array of teams of an array of players
*/
#include "league.h"

/*	Go through all of the Teams in the teams array
	and print each one using their print function*/
void League::printTeams()
{
	for (int i = 0; i < count; i++)
	{
		teams[i]->printTeam();
	}
}
/*	This should add the passed new_team to the end of the list of Teams
	Remember to set the size if you make the array bigger and to update the count
	variable for each Team added.*/
void League::addTeam(Team *new_team)
{
	// If the array is unallocated, allocate it
	if (teams == nullptr)
	{
		teams = new Team *[RESIZE_AMOUNT];
		size = 4;
	}
	// If the array is out of space, make a bigger array and deep copy over all of the old Team*s
	if (count >= size)
	{
		Team **tmp;
		tmp = new Team *[size + RESIZE_AMOUNT];
		for (int i = 0; i < count; i++)
		{
			tmp[i] = teams[i];
		}
		delete[] teams;
		teams = tmp;
		tmp = nullptr;
		size += 4;
	}
	// Regardless of if a resize was needed, add the new_team to the next open space and update the count
	teams[count] = new_team;
	count++;
}
/*Start by deleting all of the teams in the array*/
League::~League()
{
	//  (similar to how the Team destructor deleted all its Players)
	for (int i = 0; i < count; i++)
	{
		delete teams[i];
	}
	// After the contents of the array are done being deallocated, delete the array that was storing all the Teams
	delete[] teams;
}
