#include "ofApp.h"


//====== Audio Connection========//

const int N = 256; // number of bands in spectrum
float spectrum[N];
float Rad2 = 500; //cloud Radius parameter
float Vel = 0.1; //cloud points velocity parameter

int bandRad = 2; //band index in spectrum, affecting Rad Value
int bandVel = 100; //band index in spectrum, affecting Vel value

const int n =300; //number of cloud points
//const int = "set a variable that can't be changed"


float x[n], y[n];
ofPoint p[n]; //cloud's points positions
float time0 = 0;





void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    

    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}





//--------------------------------------------------------------
void ofApp::setup(){
    
    //=======audio grabber=======//
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofBackground(0,0,0);
    
    soundStream.listDevices();
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize,0.0);
    volHistory.assign(400,0.0);
    
    bufferCounter = 0;
    drawCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    
    
    //==========Audio========================//
    sound.loadSound("music/Beyond.mp3");
    sound.setLoop(true);
    sound.play();
    
    


    //====audio connection setup=====//
    
    //set spectrum value to 0
    for (int i = 0; i < N; i++){
        spectrum[i]=0.0f;
        //initialize points offsets by random numbers
        for (int j = 0; j < n; j++){
            x[j] = ofRandom(0,1000);
            y[j] = ofRandom(0,1000);
        }
    }
    
    
    //====================== VISUALS =======================//
    
    nDot = 7000; //the number of dots/triangles
    nVert = nDot * 3; //the number of the vertices
    
    float Rad = 3500; //the sphere's radius
    float rad = 50; //maximal triangle's "radius"
    //formally, it is the maximal coordinates' deviation from the trangle's center
    
    //fill the vertices array
    vertices.resize(nVert* .3); // set the array size
    for (int i = 0; i < nDot; i++) { //scan all the triangles
        //generate the center of the triangle
        //as a random point on the sphere
        
        //take the random poin from cube [-1,1] x [-1,1] x [-1,1]
        
        ofPoint center(ofRandom(-1,1),
                       ofRandom(-1,1),
                       ofRandom(-1,1));
        
        center.normalize(); //normalize vector's length to 1
        center *= Rad; //now the center vector has length Rad
        
        //Generate the triangle's vertices as the center plus random point from [-rad, rad] x [-rad, rad] x [-rad, rad]
        for (int j=0; j< 4; j++) {
            vertices[ i * 3 + j ] = center + ofPoint(ofRandom(-rad, rad), ofRandom(-rad,rad),ofRandom(-rad,rad));
            
        }
    }
    
    //fill the array of triangles' colors
    colors.resize(nDot);
    for (int i = 0; i < nDot; i++){
        //take a random color from yellow to white
        colors[i] = ofColor(200,200,200,70);
    }

    //==============Video====================//
    
    ofEnableAlphaBlending();
    
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    
    myMovie.loadMovie("movies/dance.mov");
    myMovie.play();
    

    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//==========SOUND GRABBER==============//
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

   
    

    
//==========visuals===========================//
    ofSoundUpdate();
    
    //get current spectrum with N bands
    float *val = ofSoundGetSpectrum(N);
    for (int i =0; i < N; i++) {
        spectrum[i] *=0.97;
        spectrum[i] = max(spectrum[i],val[i]);
    }
    
    //update particles using spectrum values
    //computing dt as a time between the last and the current calling of update()
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp(dt, 0.0, 0.1);
    time0 = time; //store the current time
    
    //update rad and vel from spectrum
    //note the parameters in ofMap's were tuned for best result
//    //just for current music track
//    Rad2 = ofMap(spectrum[bandRad], 1, 3, 400, 800, true);
//    
//    Vel = ofMap(spectrum[bandVel], 0 , 0.1, 0.05, 0.5);
//    //update particles positions
//    for (int j=0; j < n; j++) {
//        x[j] += Vel * dt; // move offset
//        y[j] += Vel *dt; //move offset
//        //calculate Perlin's noise in [-1,1] and
//        //multiply on Rad
//        p[j].x = ofSignedNoise( x[j]) * Rad2;
//        p[j].y = ofSignedNoise( y[j]) * Rad2;
//        

    Rad2 = ofMap(spectrum[bandRad], 1, 3, 400, 800, true);
    
    Vel = ofMap(spectrum[bandVel], 0 , 0.1, 0.05, 0.5);
    //update particles positions
    for (int j=0; j < n; j++) {
        x[j] += dt * scaledVol; // move offset
        y[j] += dt * scaledVol; //move offset
        //calculate Perlin's noise in [-1,1] and
        //multiply on Rad
        p[j].x = ofSignedNoise( x[j]) * Rad2;
        p[j].y = ofSignedNoise( y[j]) * Rad2;

}
    
    //==============VIDEO=================//
    
    myMovie.update();



}

//--------------------------------------------------------------
void ofApp::draw(){
   


//==============VISUALS==================//


 
    ofEnableDepthTest(); //Enable z-buffering!!!!
    
    ofPushMatrix(); //store the coordinate system
    
    //move the coordinate center to screen's center
    ofTranslate(ofGetWidth()/2, ofGetWidth()/2, 0);
    

    float time = ofGetElapsedTimef(); // Get time in

    
    float angle = time * 10; // compute angle. it rotate at speed 10 degrees per second !!!!!
    ofRotate(angle, 1, 1, 1);
    
    
    //draw the triangle
    
    
//    for (int i = 0; i < nDot; i++){
//        ofSetColor(colors[i]);
//        ofTriangle(vertices [i * 0.03],
//                   vertices [i * 0.03+ 1],
//                   vertices [i * 0.03 + 2]
//                   ); //draw triangle scaledVol * 190.0f
//    }
    
    
    //==========WORKS!!!!!==============//

        for (int i = 0; i < nDot; i++){
        ofSetColor(colors[i]);
        ofTriangle(vertices [i * scaledVol * 190.0f * 0.003],
                   vertices [i * scaledVol * 190.0f * 0.003+ 1],
                   vertices [i * scaledVol * 190.0f * 0.003 + 2]
                   ); //draw triangle scaledVol * 190.0f
    }
    

    
    
    ofPopMatrix();
    
    //===========Movie=========//

   myMovie.draw(0,0,ofGetWidth(),ofGetHeight());


    }

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
        myMovie.setPaused(true);
	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
        myMovie.setPaused(false);
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
