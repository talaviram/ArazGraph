/*
 * MIT License
 * 
 * Copyright (c) 2016 Ara Bedrossian
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

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
