#include "AscendingPattern.h"


AscendingPattern::AscendingPattern()
{
}


AscendingPattern::~AscendingPattern()
{
}

void AscendingPattern::buildCells(const bool noteOns[], vector<vector<Cell>> &grid) {
	int numNotesOn = 0;
	for (int midiNote=0; midiNote < 127; midiNote++) {
		if (noteOns[midiNote])
			numNotesOn++;
	}

	grid.resize(numNotesOn);
	for (int x = 0; x < numNotesOn; x++) {	
		grid[x].resize(numNotesOn);
	}

	int gridSpotCounter = 0;
	for (int midiNoteNum=0; midiNoteNum < 127; midiNoteNum++) {
		if (noteOns[midiNoteNum]) {
			grid[gridSpotCounter][gridSpotCounter].setNoteNum(midiNoteNum);
			gridSpotCounter++;
		}
	}
}