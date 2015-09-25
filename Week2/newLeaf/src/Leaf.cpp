//
//  Leaf.cpp
//  newLeaf
//
//  Created by Xiaoyin Sun on 9/23/15.
//
//

#include "Leaf.h"



void Leaf::setup(){
    
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;

    
    leafLength = 300;
    leafWidth = 190;
    
    stemLength = 100;
    stemWidth = 4;
    
    leafColor = ofColor(ofRandom(220,250),ofRandom(50,90),ofRandom(30,50), ofRandom(210,225));
    stemColor = ofColor(128,70,50);
    
    scaleFactor = ofRandom(.3,1);
    rotation = ofRandom(0,360);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    //Small leaf variables
    
    leafL=200;
    leafW=150;
    
    
}

void Leaf::update(){
    
}

void Leaf::draw(){
    

    //CENTER LEAF
    
    ofPushMatrix();
    ofSetLineWidth(1);
    ofRotateZ(rotation);
    ofRotate(rotation,xPos,yPos,0);

    
    ofTranslate(xPos, yPos);
    ofRotate(rotation);
    ofScale(scaleFactor,scaleFactor);
    ofSetColor(leafColor);
    
    
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
    
    //stem rectangle
    
    ofBeginShape();
    ofSetColor(stemColor);
    ofRect(x0,y0 - (stemLength/2), stemWidth, stemLength);
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
