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
	Team **tmp;
	// If the array is unallocated, allocate it
	if (teams == nullptr)
	{
		delete[] teams;
		teams = new Team *[RESIZE_AMOUNT];
		size = 4;
	}

	// If the array is out of space, make a bigger array and deep copy over all of the old Team*s
	if (count >= size)
	{
		tmp = new Team *[size + RESIZE_AMOUNT];
		for (int i = 0; i < count; i++)
		{
			tmp[i] = teams[i];
		}
		delete[] teams;
		teams = new Team *[size + RESIZE_AMOUNT];
		teams = tmp;
		tmp = nullptr;
		size += 4;
	}

	// Regardless of if a resize was needed, add the new_team to the next open space and update the count
	teams[count] = new_team;
	count++;
}

/**/
League::~League()
{
	// TODO

	// Start by deleting all of the teams in the array (similar to how the Team destructor deleted all its Players)
	for (int i = 0; i < count; i++)
	{
		delete teams[i];
	}
	delete[] teams;

	// After the contents of the array are done being deallocated, delete the array that was storing all the Teams
	// Delete the teams array the standard way you deallocate arrays (HINT: How does delete work on arrays?)

	// This should be about 3 lines of code
}
