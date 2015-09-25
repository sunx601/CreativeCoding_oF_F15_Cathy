//
//  Leaf.h
//  newLeaf
//
//  Created by Xiaoyin Sun on 9/23/15.
//
//

#ifndef __newLeaf__Leaf__
#define __newLeaf__Leaf__

#include <stdio.h>
#include "ofMain.h"


class Leaf {

public:
    
    void setup();
    void update();
    void draw();
    
private:

    float xPos, yPos;
    
    float leafLength, leafWidth;
    float stemLength, stemWidth;
    
    float rotation;
    float leafCurvature;
    
    ofColor stemColor;
    ofColor leafColor;
    float scaleFactor;
    
    float leafL, leafW;
        
};


#endif /* defined(__newLeaf__Leaf__) */
