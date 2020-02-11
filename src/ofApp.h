#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"

class shapes{
    
public:
    shapes(int size, int rez, ofVec3f point);
    ~shapes();
    
    void draw();
    int rad, res;
    ofVec3f Point;
    
};

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
    vector<shapes> these;
    int r,g,b,a;
    int randR1, randR2;
};
