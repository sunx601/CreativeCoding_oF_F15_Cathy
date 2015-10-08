//
//  Leaf.cpp
//  Leaves
//
//  Created by Xiaoyin Sun on 9/10/15.
//
//

#include "Leaf.h"

void Leaf::setup(float _branchAngle, int _season){
    xPos = ofGetWidth()/2; 
    yPos = ofGetHeight()/2;
    leafL=200;
    leafW=150;

    //255,133
    season = _season;
    
    if(season == 0 || season == 3){
        leafColor = ofColor(ofRandom(110,250),ofRandom(30,40),ofRandom(30,50), ofRandom(210,225));

    } else if(season == 1){
        randomNumber = ofRandom(0, 3);
        
        if(randomNumber >= 0 && randomNumber <1){
            leafColor = ofColor(ofRandom(220,250),55,40,ofRandom(210,225));
        }
        if(randomNumber >= 1 && randomNumber < 2) {
            leafColor = ofColor(ofRandom(230,250),67,37, ofRandom(210,225));
        }
        if(randomNumber >= 2 && randomNumber < 3) {
            leafColor = ofColor(ofRandom(200,240),ofRandom(60,80),46,ofRandom(210,225));
        }
    }
    
    scaleFactor = ofRandom(.1,.3);
    ofSetRectMode(OF_RECTMODE_CENTER);
    stemLength = ofRandom(280,300);
    stemWidth = ofRandom(8,10);
    leafLength = 10;
    leafWidth = 2;
    leafCurvature = ofRandom(1, 5);
//    rotation = _branchAngle + PI/2; //bring in angle of branch
    rotation = _branchAngle + PI/2 + ofRandom(-(PI/2), PI/2); //bring in angle of branch

    rotation = rotation * (180/PI); //convert to degrees (from radians) to use for ofRotateZ() below, which expects degrees...
    
}

void Leaf::update(){
    
}

void Leaf::draw(float _xPos, float _yPos){
    
    ofPushMatrix();
    
    
    ofTranslate(_xPos, _yPos);
    ofRotateZ(rotation);
    
    //    ofSetLineWidth(1);
    
    
    ofScale(scaleFactor,scaleFactor);
    ofSetColor(leafColor);
    
    
    
    
    //CENTER LEAF
    
    ofBeginShape();
    
    float x0 = 0;
    float x1 = x0 - leafWidth/3;
    float x2 = x0 - (leafWidth)/3;
    float x3 = x0;
    
    
    
    float y0 = 0;
    float y1 = y0 + leafLength/3;
    float y2 = y0 + 2*(leafLength/3);
    float y3 = y0 + leafLength;
    
    ofRotate(0, x0, y0, 0);
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();

    
    //right leaf
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafWidth/3;
    x2 = x0 + (leafWidth)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafLength/3;
    y2 = y0 + 2*(leafLength/3);
    y3 = y0 + leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    //SECOND LEFT LEAF
    
    ofBeginShape();
    ofSetColor(leafColor);
    ofRotate(45, x0, y0, 30);
    
    
    x0 = 0;
    x1 = x0 - leafWidth/3;
    x2 = x0 - (leafWidth)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafLength/3;
    y2 = y0 + 2*(leafLength/3);
    y3 = y0 + leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafWidth/3;
    x2 = x0 + (leafWidth)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafLength/3;
    y2 = y0 + 2*(leafLength/3);
    y3 = y0 + leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    //Third LEFT LEAF - small
    
    ofBeginShape();
    ofSetColor(leafColor);
    ofRotate(60, x0, y0, 30);
    
    x0 = 0;
    x1 = x0 - leafW/3;
    x2 = x0 - (leafW)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafL/3;
    y2 = y0 + 2*(leafL/3);
    y3 = y0 + leafL;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafW/3;
    x2 = x0 + (leafW)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafL/3;
    y2 = y0 + 2*(leafL/3);
    y3 = y0 + leafL;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //Right Third Leaf -small
    ofBeginShape();
    ofSetColor(leafColor);
    ofRotate(150, x0, y0, 90);
    
    x0 = 0;
    x1 = x0 - leafW/3;
    x2 = x0 - (leafW)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafL/3;
    y2 = y0 + 2*(leafL/3);
    y3 = y0 + leafL;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafW/3;
    x2 = x0 + (leafW)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafL/3;
    y2 = y0 + 2*(leafL/3);
    y3 = y0 + leafL;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    //Right Second Leaf
    ofBeginShape();
    ofSetColor(leafColor);
    ofRotate(60, x0, y0, 300);
    
    x0 = 0;
    x1 = x0 - leafWidth/3;
    x2 = x0 - (leafWidth)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafLength/3;
    y2 = y0 + 2*(leafLength/3);
    y3 = y0 + leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    //right leaf
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafWidth/3;
    x2 = x0 + (leafWidth)/3;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + leafLength/3;
    y2 = y0 + 2*(leafLength/3);
    y3 = y0 + leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    ofPopMatrix();
    
    
}










