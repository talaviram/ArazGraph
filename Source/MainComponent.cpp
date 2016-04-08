/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "ArazGraph.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    ArazGraph* graph = new ArazGraph(getLocalBounds(), "My Measurements", "Freq(Hz)", "db");
	ArazGraphDataset* leftEarData = new ArazGraphDataset("Left", Colours::green);
    for (int i = 0; i < 5000; i += 10)
    {
        leftEarData->append(new ArazGraphPoint(i, 50 * sin(i / 200.0)));
    }
	graph->append(leftEarData);
	
	ArazGraphDataset* rightEarData = new ArazGraphDataset("Right", Colours::red);
	rightEarData->append(new ArazGraphPoint(0, 0));
	rightEarData->append(new ArazGraphPoint(100, 10));
	rightEarData->append(new ArazGraphPoint(500, 35));
	rightEarData->append(new ArazGraphPoint(1000, 25));
	rightEarData->append(new ArazGraphPoint(2000, 20));
	rightEarData->append(new ArazGraphPoint(5000, 10));
	graph->append(rightEarData);

	graph->paint(g);

    delete graph;
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
