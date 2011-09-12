#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
class FirstVstAudioProcessor; //forward declaration

class ControlsComponent : public Component, public ButtonListener {
public:
	ControlsComponent(FirstVstAudioProcessor* firstVstAudioProcessor_); //forward reference
	~ControlsComponent();
	virtual void paint (Graphics& g);
	virtual void resized();
	void buttonClicked (Button* button);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControlsComponent);
	FirstVstAudioProcessor* firstVstAudioProcessor;
	ToggleButton* toggleButton;
};
