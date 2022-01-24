/*
  ==============================================================================

    LoadCasesComponent.cpp
    Created: 23 Jan 2022 10:04:13pm
    Author:  VA

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoadCasesComponent.h"

//==============================================================================
LoadCasesComponent::LoadCasesComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(600, 400);
}

LoadCasesComponent::~LoadCasesComponent()
{
}

void LoadCasesComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
    const auto bounds = getLocalBounds();
    g.setColour(juce::Colours::whitesmoke);
    g.drawRect(0, 0, bounds.getWidth(), bounds.getHeight());
}

void LoadCasesComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    const auto H = (int)(loadCasesCount / 2) * 22 + 50;
    
    const auto bounds = getLocalBounds();
    setBounds(0, 0, getParentWidth(), H);

    drawComboboxes();
}

void LoadCasesComponent::drawComboboxes()
{
    const auto size = loadCaseButtons.size();
    const auto bounds = getLocalBounds();

    int row = 0;
    int column = 0;

    int x1center = (int)(bounds.getWidth() / 4);
    int x2center = (int)(bounds.getWidth() * 3 / 4);
    
    int ycenter = 0;
    int xcenter = 0;

    int halfofcases = (int)size / 2;
    
    for (auto button : loadCaseButtons)
    {
        button->setSize(100, 20);

        ycenter = 20 + row * 22;
        xcenter = (column == 0) ? x1center : x2center;
        
        button->setCentrePosition(xcenter, ycenter);
        
        if (row < halfofcases)
            row++;  
        else
        {
            row = 0;
            column++;
        }
            
    }
}

void LoadCasesComponent::setupLoadCaseButtons(int loadcasescount)
{
    loadCaseButtons.clear(true);

    loadCasesCount = loadcasescount;

    if (loadcasescount == 0)
        return;
    
    // First (default button)
    auto button = loadCaseButtons.add(new juce::ToggleButton("All load cases"));
    addAndMakeVisible(button);
    button->addListener(this);

    // All other buttons for each load case
    for (int i = 0; i < loadcasescount; i++)
    {
        auto button = loadCaseButtons.add(new juce::ToggleButton("Item " + juce::String(i + 1)));
        addAndMakeVisible(button);
        button->addListener(this);
    }
}

void LoadCasesComponent::buttonClicked(juce::Button* b)
{
    if (b == loadCaseButtons.getFirst())
    {
        auto state = b->getToggleState();
        for (int i = 1; i < loadCaseButtons.size(); i++)
        {
            auto button = loadCaseButtons[i];
            button->setToggleState(state, juce::dontSendNotification);
        }
        return;
    }
}