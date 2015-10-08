//
//  Branch.h
//  Branches
//
//  Created by Xiaoyin Sun on 9/25/15.
//
//

#ifndef __Branches__Branch__
#define __Branches__Branch__

#include "ofMain.h"
#include "Leaf.h"

class Branch : public ofBaseApp{
    
public:
    void setup(float _xPos, float _yPos, float _width,
               float _length,
               float _splitPercentage,
               float _maxSplitAngle,
               int _maxSubdivisions,
               int _maxSegments,
               int _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color,
               int _season,
               int numberOfBobs);
    void update();
    void draw();
    
    
private:
    
    float xPos, yPos;
    float width, length;
    float splitPercentage;
    float maxSplitAngle;
    int maxSubdivsions;
    int maxSegments;
    int segmentsSinceStart;
    float angle;
    float curvature;
    bool hasLeaves;
    ofColor color;
    
//    Leaf myLeaf;r
    int numLeaves;
    vector<Leaf> leaves;
    bool split;
    int season;
    
};

#endif /* defined(__Branches__Branch__) */
