#include "Cell.h"


Cell::Cell():
noteNum(-1) {
}

Cell::Cell(int noteNum_): 
noteNum(noteNum_) {
}

Cell::~Cell() {
}

Cell::Cell(const Cell& c) {
	noteNum = c.getNoteNum();
}

int Cell::getNoteNum() const {
	return noteNum;
}
	
void Cell::setNoteNum(int noteNum_) {
	noteNum = noteNum_;
}
