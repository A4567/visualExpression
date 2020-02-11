#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
    ofVec3f startPoint;
    int shapeRes, shapeSize,shapesDrawn,totalSides,minShapes;
    bool end;
    ofImage img;
    int r,g,b,a;
    int randR1, randR2;
};
