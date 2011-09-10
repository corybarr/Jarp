#ifndef __CELL_H_7FE1B233__
#define __CELL_H_7FE1B233__

#include "../JuceLibraryCode/JuceHeader.h"

class Cell
{
public:
	Cell();
	Cell(int noteNum_);
	~Cell();
	Cell(const Cell& c);
	int getNoteNum() const;
	void setNoteNum(int noteNum_);

private:
	//JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Cell);
	int noteNum;
};

#endif
