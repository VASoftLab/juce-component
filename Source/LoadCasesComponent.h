/*
  ==============================================================================

    LoadCasesComponent.h
    Created: 23 Jan 2022 10:04:13pm
    Author:  VA

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LoadCasesComponent  : public juce::Component,
    public juce::Button::Listener
{
public:
    LoadCasesComponent();
    ~LoadCasesComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setupLoadCaseButtons(int loadcasescount);
    void buttonClicked(juce::Button* b) override;

private:
    void drawComboboxes();
    juce::OwnedArray<juce::ToggleButton> loadCaseButtons;
    int loadCasesCount;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadCasesComponent)
};
