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
	g.setColour(Colours::red);
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
				g.setColour(Colours::yellow); 
			} else {
				g.setColour(Colours::darkblue);
			}
			g.fillRect(x * cellWidth, y * cellHeight, cellWidth, cellHeight);
			g.setColour(Colours::aliceblue);
			g.drawRoundedRectangle(x * cellWidth, y * cellHeight, cellWidth, cellHeight, 3.0f, 1.0f);

			g.setColour(Colours::white);
			g.drawText(String(cell.getNoteNum()), x * cellWidth, y * cellHeight, cellWidth, cellHeight, Justification::centred, false);

			
		}
	}
}
void GridComponent::resized(){
}