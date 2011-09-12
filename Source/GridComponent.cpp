#include "GridComponent.h"
#include "PluginProcessor.h"
#include "Cell.h"

GridComponent::GridComponent(FirstVstAudioProcessor* firstVstAudioProcessor_) :
firstVstAudioProcessor(firstVstAudioProcessor_)
{
}
GridComponent::~GridComponent(){
}
void GridComponent::paint (Graphics& g){
	g.setColour(Colour::fromRGB(30, 30, 30));
	g.fillRect(0, 0, getWidth(), getHeight());

	vector<vector<Cell> > grid = firstVstAudioProcessor->getGrid();

	for (int x=0; x < grid.size(); x++) {
		for (int y=0; y < grid[x].size(); y++) {
			Cell cell = grid[x][y];
			int numCols = grid.size();
			int numRows = grid[x].size();
			float cellWidth = getWidth() / numCols;
			float cellHeight = getHeight() / numRows;
			if (firstVstAudioProcessor->getLastPlayheadCol() == x) {
                // Col is playing
                if (cell.getNoteNum() != -1) {
                    // Cell has a note
                    g.setColour(Colour::fromRGB(120, 80, 190)); 
                } else {
                    // Cell has no note
                    g.setColour(Colour::fromRGB(100, 80, 90));                     
                }
			} else {
                // Col is not playing
                if (cell.getNoteNum() != -1) {
                    // Cell has a note
                    g.setColour(Colour::fromRGB(40, 40, 150));
                } else {
                    // Cell has no note
                    g.setColour(Colour::fromRGB(40, 40, 90));
                }
			}
            float left = x * cellWidth;
            float top = y * cellHeight;
            float border = 5;
            left += border;
            top += border;
            cellWidth -= border*2;
            cellHeight -= border*2;
			g.fillRoundedRectangle(left, top, cellWidth, cellHeight, 8.0f);
			g.setColour(Colour::fromRGB(100, 100, 100));
			g.drawRoundedRectangle(left, top, cellWidth, cellHeight, 8.0f, 1.0f);

            if (cell.getNoteNum() != -1) {
                // Draw note number
                g.setColour(Colours::white);
                g.drawText(String(cell.getNoteNum()), left, top, cellWidth, cellHeight, 
                           Justification::centred, false);
            }
		}
	}
}
void GridComponent::resized(){
}