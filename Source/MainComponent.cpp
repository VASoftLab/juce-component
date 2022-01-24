#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    loadCasesComponent.reset(new LoadCasesComponent());
    loadCasesComponent->setupLoadCaseButtons(24);

    viewPort.reset(new juce::Viewport());
    viewPort->setScrollBarsShown(true, false, true, false);
    viewPort->setViewedComponent(loadCasesComponent.get(), false);    
    addAndMakeVisible(viewPort.get());

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    const auto bouds = getLocalBounds();
    g.setColour(juce::Colours::cornflowerblue);    
    g.drawRoundedRectangle(10, bouds.getHeight() - 200, bouds.getWidth() - 20, 160 + 20, 30.000f, 3.000f);
    
    // g.setFont (juce::Font (16.0f));
    // g.setColour (juce::Colours::white);
    // g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    const auto bouds = getLocalBounds();
    viewPort->setBounds(20, bouds.getHeight() - 200 + 25, bouds.getWidth() - 40, 160 - 25);
    
    loadCasesComponent->resized();
}
