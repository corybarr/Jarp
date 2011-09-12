#include "ControlsComponent.h"
#include "PluginProcessor.h"
#include "Cell.h"

ControlsComponent::ControlsComponent(FirstVstAudioProcessor* firstVstAudioProcessor_) :
firstVstAudioProcessor(firstVstAudioProcessor_)
{
	toggleButton = new ToggleButton(T("Sustain\nNotes"));
	addAndMakeVisible(toggleButton);
	toggleButton->addButtonListener(this);
}
ControlsComponent::~ControlsComponent(){
	deleteAllChildren ();
}
void ControlsComponent::paint (Graphics& g){
	g.setColour(Colours::green);
	g.fillRect(0, 0, getWidth() , getHeight());
	toggleButton->setBounds(10, 10, 100, 50);
}
void ControlsComponent::resized(){
}

void ControlsComponent::buttonClicked (Button* button){
	if (button == toggleButton) {
		toggleButton->getToggleState() ? firstVstAudioProcessor->sustainNotes = true : firstVstAudioProcessor->sustainNotes = false;
		//if (toggleButton->getToggleState()) {
		//	firstVstAudioProcessor->sustainNotes = true;
		//	//toggleButton->setToggleState(false, false);
		//} else {
		//	firstVstAudioProcessor->sustainNotes = false;
		//	//toggleButton->setToggleState(true, false);
		//}
	}
}