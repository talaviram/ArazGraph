# ArazGraph
### Author: Ara Bedrossian
### Date: April 2016

This is a simple data plotter graph class for JUCE.

I used VisualStudio 2015 to compile the code. But since JUCE is a cross-platform library, you should be able to compile it in any supported environment.

You need only the 'ArazGraph.h' and 'ArazGraph.cpp' files to be able to use the ArazGraph class to plot multiple datasets.

## example
There is an example of usage in 'Source/MainComponent.cpp' file.

```
void MainContentComponent::paint(Graphics& g)
{
	g.fillAll(Colour(0xff001F36));

	ArazGraph* graph = new ArazGraph(getLocalBounds(), "My Measurements", "Freq(Hz)", "db");

	ArazGraphDataset* leftEarData = new ArazGraphDataset("Left", Colours::green);
	leftEarData->append(new ArazGraphPoint(0, 10));
	leftEarData->append(new ArazGraphPoint(500, 20));
	leftEarData->append(new ArazGraphPoint(1000, 30));
	leftEarData->append(new ArazGraphPoint(5000, 10));
	graph->append(leftEarData);

	ArazGraphDataset* rightEarData = new ArazGraphDataset("Right", Colours::red);
	rightEarData->append(new ArazGraphPoint(0, 15));
	rightEarData->append(new ArazGraphPoint(500, 25));
	rightEarData->append(new ArazGraphPoint(1000, 35));
	rightEarData->append(new ArazGraphPoint(5000, 15));
	graph->append(rightEarData);

	graph->paint(g);

	delete graph;
}
```

## screenshots

[https://github.com/arabed/ArazGraph/blob/master/Screenshot/Screenshot_1.png]
