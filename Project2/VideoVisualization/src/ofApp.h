#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //!!!!!========sound grabber=======!!!!!!//
    
        void audioIn(float * input, int bufferSize, int nChannels);
    
        ofSoundStream soundStream;
        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
        
        int bufferCounter;
        int drawCounter;
        
        float smoothedVol;
        float scaledVol;
    

        //===========video & sound ============//

		ofVideoPlayer 		myMovie;
        ofSoundPlayer       sound;
		bool                frameByframe;


    
    //=========visuals//=========
    
    vector<ofPoint> vertices;
    vector<ofColor> colors;
        
    int nDot; 
    int nVert;
};

