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

    
    leafLength = ofRandom(280,300);
    leafWidth = ofRandom(180,190);
    
    stemLength = ofRandom(150,160);
    stemWidth = ofRandom(8,10);
    
    leafColor = ofColor(ofRandom(220,250),ofRandom(50,90),ofRandom(30,50), ofRandom(210,225));
    stemColor = ofColor(128,70,50);
    
    scaleFactor = ofRandom(.1,.5);
    rotation = ofRandom(0,360);
    

    //Small leaf variables
    
    leafL=ofRandom(200,210);
    leafW=ofRandom(140,150);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
}

void Leaf::update(){
    
}

void Leaf::draw(){
    
    ofPushMatrix();
    
    
    ofTranslate(xPos, yPos-stemLength);
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
    
//    //stem
//    ofBeginShape();
//    ofSetColor(stemColor);
//    ofRotate(45, x0, y0, 30);
//    ofRect(0,0-stemLength/2, stemWidth, stemLength);
    
//    float x11 = 0 - stemWidth/2;
//    float x22 = 0 + stemWidth/2;
    
    
    ofEndShape();
    
    ofPopMatrix();
    
}
