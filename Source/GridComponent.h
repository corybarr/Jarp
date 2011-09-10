#ifndef __GRIDCOMPONENT_H_7FE1B233__
#define __GRIDCOMPONENT_H_7FE1B233__

#include "../JuceLibraryCode/JuceHeader.h"
class FirstVstAudioProcessor; //forward declaration

class GridComponent : public Component{
public:
	GridComponent(FirstVstAudioProcessor* firstVstAudioProcessor_); //forward reference
	~GridComponent();
	virtual void paint (Graphics& g);
	virtual void resized();
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GridComponent);
	FirstVstAudioProcessor* firstVstAudioProcessor;
};

#endif