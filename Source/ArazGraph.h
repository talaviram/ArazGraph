#ifndef ARAZGRAPH_H_INCLUDED
#define ARAZGRAPH_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class ArazGraphPoint
{
public:
    ArazGraphPoint(float xValue, float yValue);

public:
    float xValue;
    float yValue;
    LinkedListPointer<ArazGraphPoint> nextListItem;
};


class ArazGraphDataset
{
public:
    ArazGraphDataset(String label = "Dataset", Colour colour = Colours::black);
    ~ArazGraphDataset();
    void append(ArazGraphPoint* point);

public:
    String label;
    Colour colour;
    LinkedListPointer<ArazGraphPoint>* points;
    LinkedListPointer<ArazGraphDataset> nextListItem;
};

class ArazGraph
{
public:
    ArazGraph(Rectangle<int> region, String title = "Araz Graph", String xLabel = "X-Axis", String yLabel = "Y-Axis", Colour fgColour = Colours::white, Colour bgColour = Colours::navy);
    ~ArazGraph();
    void append(ArazGraphDataset* dataset);
    void paint(Graphics& g);

private:
    Rectangle<int> region;
    Rectangle<int> regionGraph;
    String title;
    String xLabel;
    String yLabel;
    Colour fgColour;
    Colour bgColour;
	int xMargin;
	int yMargin;
	LinkedListPointer<ArazGraphDataset>* datasets;
};

#endif  // ARAZGRAPH_H_INCLUDED
