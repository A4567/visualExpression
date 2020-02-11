#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0); // black background
    //setting inital colour values
    r = 0;
    g = 0;
    b = 0;
    a = 10;
    ofSetColor(r, g, b, 10);
    // disabling canvas refresh so each image drawn stays
    ofSetBackgroundAuto(false);
    // assign a random starting point within centre 3rd of the window
    startPoint.x = ofRandom(ofGetWidth()/3,ofGetWidth()/1.5);
    startPoint.y = ofRandom(ofGetHeight()/3,ofGetHeight()/1.5);
    // assign a random starting resultion to the shape determining the number of sides it has
    shapeRes = ofRandom(3,10);
    // assing an initial size to increas from
    shapeSize = ofRandom(5,35);
    //starting the count of drawn shapes
    shapesDrawn = 1;
    // starting the count of the amount of sides
    totalSides = shapeRes;
//    setting the minimum amout of shapes before drawing can stop
    minShapes = 6;
    // setitng the framerate to 1 allows each shaoe to be observed as it is drawn
    ofSetFrameRate(1);
    //setting the end boolean to false
    end = false;
    // values used in the colour assignment
    randR1 =ofRandom(7,29);
    randR2 = ofRandom(7,29);
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // change color based on amount of shapes drawn
//    if(shapesDrawn % 20 == 0){
//        r -= 35;
//
//    }else if (shapesDrawn % 35 == 0){
//        b -= 40;
//    }
//    ofSetColor(r, g, b, 10);
    
    // chnage colour depending on position of shape draw above/below centre line
//    if(startPoint.y < ofGetHeight()/2){
//        ofSetColor(r, 190, 255,a);
//    }else if (startPoint.y > ofGetHeight()/2){
//        ofSetColor(r, 200, 0,a);
//    }else if(startPoint.x == startPoint.y){
//        ofSetColor(220, 100, 0, a);
//    }
    
    // assign red value to shape colour depending on if a random number assigned in setup is a factor of the shapes drawn
//    if(shapesDrawn % randR1 == 0){
//        //a -= 1;
//        r = 255;
//    }else if(shapesDrawn % randR2 == 0){
//        r = 0;
//        //a += 1;
//    }
    
//    set a the colour to a random value every time update() runs
    ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255),10);
    
    
    // edit the blue value of the colour depending on the distance of the shape being drawn from the centre point
//    ofVec3f centre(ofGetWidth()/2,ofGetHeight()/2);
//    float dist = ofDist(startPoint.x,startPoint.y, centre.x,centre.y);
//
//    ofSetColor(255, dist/2.0, b,10);
//    if(dist > 255){
//        b+=5;
//    }else{
//        b-=5;
//    }
    // set the colour to produce a gradient determining the rgb values based on their distance from the centre, creating a radial pattern
//    if(dist <= 100){
//        ofSetColor(255, 0, 0,10);
//    }else if((dist > 100)&&(dist <= 200)){
//        ofSetColor(255, 153, 51,10);
//    }else if((dist > 200)&&(dist <= 300)){
//        ofSetColor(255, 255, 0,10);
//    }else if((dist > 300)&&(dist <= 400)){
//        ofSetColor(0, 153, 0,10);
//    }else if((dist > 400)&&(dist <= 500)){
//        ofSetColor(0, 102, 153,10);
//    }else if((dist > 500)&&(dist <= 600)){
//        ofSetColor(102, 0, 255,10);
//    }else if((dist > 600)&&(dist <= 700)){
//        ofSetColor(255, 0, 255,10);
//    }

    //map the rgb values across the width of the screen providing a linear gradient of colours
//    int r = ofMap(startPoint.y, 0, ofGetHeight(), 0, 255);
//    int g = ofMap(startPoint.y, ofGetHeight()/3, ofGetHeight(), 0, 255);
//    int b = ofMap(startPoint.y,ofGetHeight()/1.5, ofGetHeight(), 0, 255);
//
//    ofSetColor(r,g,b);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ensuring the shapes centre point remains within the window
    if(startPoint.x <= 0){
        startPoint.x += shapeSize;
    }else if (startPoint.x >= ofGetWidth()){
        startPoint.x -= shapeSize;
    }else if (startPoint.y <= 0){
        startPoint.y += shapeSize;
    }else if(startPoint.y >= ofGetHeight()){
        startPoint.y -= shapeSize;
    }
//setting the resolution for each shape
    ofSetCircleResolution(shapeRes);
//    drawing each shape
    ofDrawCircle(startPoint, shapeSize);
    shapesDrawn++;
    
    
//    creating variable which will modify the centre point of each shape to be drawn so that the next one is different
    
      int newY = 0;
      int newX = 0;
      
      for (int i = startPoint.y - shapeSize; i < startPoint.y + shapeSize; i++) {
          newY++;
      }
      for (int i = startPoint.x - shapeSize; i < startPoint.x + shapeSize; i++) {
          newX++;
      }
      
      newY = newY - shapeSize;
      newX = newX - shapeSize;
    
    // increaing the shape size with each shape drawn, and validating the end conditions
    // if the number of shapes is less than the minimum or it is not a factor of the number of sides
      if((shapesDrawn < minShapes)||(totalSides % shapesDrawn != 0)){
          //increas the size
          shapeSize += 10;
          //create a random variable which can allow parameters for the shape resolution to be set making sure there is at least 3 sides and no more than 17(i think)
          int neg = ofRandom(2);
          if(neg){
              if(shapeRes >= 18){
                  shapeRes -= ofRandom(5,15);
              }else{
                  shapeRes += ofRandom(1,8);
              }
              
          }else if(!neg){
              if(shapeRes <= 3){
                  shapeRes += ofRandom(2,14);
              }else{
                  shapeRes -= ofRandom(1,7);
              }
          }
          if(shapeRes >= 18){
              shapeRes -= ofRandom(5,15);
          }else if(shapeRes <= 3){
              shapeRes += ofRandom(5,15);
          }
          //increase count of total sides
          totalSides += shapeRes;
          
          //modify the start point for the next shape to be a point randomly chosen inside the bounds of the last shape
          
          
          startPoint.y += ofRandom(-newY,newY);
          startPoint.x += ofRandom(-newX,newX);
          
          // if the minimum shapes drawn is met but the number of shapes is not a factor of the sides increase the minumum requirement
      }else if((shapesDrawn == minShapes)&&(totalSides % shapesDrawn != 0)){
          minShapes++;
          // if the total shapes is a factor of the sides and there is more than 6 shapes take a picture
      }else if((totalSides % shapesDrawn == 0)&&(shapesDrawn > 6)){
          img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
          img.save("myPic.png");
      }/*
        if more than 150 shapes are drawn take a picture and exit the program
        else if(shapesDrawn > 150){
          img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
          img.save("myPic.jpg");
          ofExit();
      }*/
     // cout << shapesDrawn << " drawn. " << totalSides << " sides." << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // press s to take a picture
    if(key == 's'){
        img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        img.save("myPic.png");
    }
}
