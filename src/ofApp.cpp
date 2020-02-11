#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    r = 0;
    g = 0;
    b = 0;
    a = 10;
    ofSetColor(r, g, b, 10);
    ofSetBackgroundAuto(false);
    startPoint.x = ofRandom(ofGetWidth()/3,ofGetWidth()/1.5);
    startPoint.y = ofRandom(ofGetHeight()/3,ofGetHeight()/1.5);
    shapeRes = ofRandom(3,10);
    shapeSize = 50;//ofRandom(5,35);
    shapesDrawn = 1;
    totalSides = shapeRes;
    minShapes = 6;
   // ofSetFrameRate(1);
    end = false;
    randR1 =ofRandom(7,29);
    randR2 = ofRandom(7,29);
   
    
//    for(int i = 0; i < shapesDrawn; i++){
//        shapes newShape(shapeSize,shapeRes,startPoint);
//        these.push_back(newShape);
//    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    if(shapesDrawn % 20 == 0){
//        r -= 35;
//
//    }else if (shapesDrawn % 35 == 0){
//        b -= 40;
//    }
    
//    ofSetColor(r, g, b, 10);
//    if(startPoint.y < ofGetHeight()/2){
//        ofSetColor(r, 190, 255,a);
//    }else if (startPoint.y > ofGetHeight()/2){
//        ofSetColor(r, 200, 0,a);
//    }else if(startPoint.x == startPoint.y){
//        ofSetColor(220, 100, 0, a);
//    }
//    if(shapesDrawn % randR1 == 0){
//        //a -= 1;
//        r = 255;
//    }else if(shapesDrawn % randR2 == 0){
//        r = 0;
//        //a += 1;
//    }
  //  ofSetColor(o(fRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255),210);
    
//    ofVec3f centre(ofGetWidth()/2,ofGetHeight()/2);
//    float dist = ofDist(startPoint.x,startPoint.y, centre.x,centre.y);
//    cout << dist << endl;
//    ofSetColor(255, dist/2.0, b,10);
//    if(dist > 255){
//        b+=5;
//    }else{
//        b-=5;
//    }
    
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

    int r = ofMap(startPoint.y, 0, ofGetHeight(), 0, 255);
    int g = ofMap(startPoint.y, ofGetHeight()/3, ofGetHeight(), 0, 255);
    int b = ofMap(startPoint.y,ofGetHeight()/1.5, ofGetHeight(), 0, 255);
   
    ofSetColor(r,g,b);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(startPoint.x <= 0){
        startPoint.x += shapeSize;
    }else if (startPoint.x >= ofGetWidth()){
        startPoint.x -= shapeSize;
    }else if (startPoint.y <= 0){
        startPoint.y += shapeSize;
    }else if(startPoint.y >= ofGetHeight()){
        startPoint.y -= shapeSize;
    }
//    for (int i = 0; i < these.size(); i++) {
//        these[i].draw();
//    }
    ofSetCircleResolution(shapeRes);
    ofDrawCircle(startPoint, shapeSize);
    shapesDrawn++;
    
    
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
      
      if((shapesDrawn < minShapes)||(totalSides % shapesDrawn != 0)){
          //shapeSize += 10;
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
          
          totalSides += shapeRes;
          //this is next point to give attention to make sure it walks around so to speak
          startPoint.x += ofRandom(-20,20);
          //startPoint.y += ofRandom(-20,20);
          
          
          
          startPoint.y += ofRandom(-newY,newY);
          startPoint.x += ofRandom(-newX,newX);
          
         // shapes newShape(shapeSize,shapeRes,startPoint);
        //  these.push_back(newShape);
         
          
      }else if((shapesDrawn == minShapes)&&(totalSides % shapesDrawn != 0)){
          minShapes++;
      }else if((totalSides % shapesDrawn == 0)&&(shapesDrawn > 6)){
          img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
          img.save("myPic.png");
      }/*else if(shapesDrawn > 150){
          img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
          img.save("myPic.jpg");
          ofExit();
      }*/
     // cout << shapesDrawn << " drawn. " << totalSides << " sides." << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        img.save("myPic.png");
    }
}

//--------------------------------------------------------------
shapes::shapes(int size, int rez, ofVec3f point){
    res = rez;
    rad = size;
    Point = point;
}
shapes::~shapes(){
    
}
void shapes::draw(){
    ofSetCircleResolution(res);
    ofDrawCircle(Point,rad);
}
