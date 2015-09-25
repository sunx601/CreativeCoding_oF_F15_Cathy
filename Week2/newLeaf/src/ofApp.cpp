#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numLeaves = (int)ofRandom(5,15);
    
    for(int i = 0; i < numLeaves; i++){
        Leaf tempLeaf;
        tempLeaf.setup();
        myMaple.push_back(tempLeaf);
    }
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < numLeaves; i++){
        myMaple[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < numLeaves; i++){
        myMaple[i].draw();
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    myMaple.clear();
    setup();
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
