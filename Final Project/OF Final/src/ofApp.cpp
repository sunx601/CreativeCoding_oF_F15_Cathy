#include "ofApp.h"
#include "MSAOpenCL.h"

typedef struct{
	float4 target;
	float speed;
    float dummy1;
	float dummy2;
    float dummy3;
} Particle;

msa::OpenCL opencl;

msa::OpenCLBufferManagedT<Particle>	particles; // vector of Particles on host and corresponding clBuffer on device
msa::OpenCLBufferManagedT<float4> particlePos; // vector of particle positions on host and corresponding clBuffer on device
GLuint vbo;

int n = 1000000;


//--------------------------------------------------------------
void ofApp::setup(){
  
    ofEnableAlphaBlending();
    image.loadImage("image2.jpg");
    
    //Sound and Screen Setup
    ofToggleFullscreen();
    sound.loadSound( "music/selfie.mp3" );
    sound.setLoop(true);
    sound.play();
    
    //Camera
	cam.setDistance(600);
    cam.disableMouseInput();
    
    //OpenCL
	opencl.setupFromOpenGL();
	opencl.loadProgramFromFile("Particle.cl");
	opencl.loadKernel("updateParticle");
    
    //vbo
    glGenBuffersARB(1, &vbo);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float4) * n, 0, GL_DYNAMIC_COPY_ARB);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    
    // init host and CL buffers
    particles.initBuffer(n);
    particlePos.initFromGLObject( vbo, n );
    
    
    becomeCube(false);
    

	
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    image.update();
    
    //Update particles positions
    
    //Link parameters to OpenCL
    opencl.kernel("updateParticle")->setArg(0, particles.getCLMem());
	opencl.kernel("updateParticle")->setArg(1, particlePos.getCLMem());
   

    opencl.kernel("updateParticle")->run1D( n );
	opencl.finish();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
    
    ofPushStyle();

    ofSetColor(100);
    image.draw(0,0,ofGetWidth(),ofGetHeight());
    
    ofPopStyle();


    //camera rotate
    float time = ofGetElapsedTimef();
    cam.orbit(time*12, 0, 600, ofPoint( 0, 0, 0 ) );
    cam.begin();
    
    ofPushStyle();
    ofEnableBlendMode( OF_BLENDMODE_ADD );

    
    ofSetColor( 16, 16, 16, 25);
    glPointSize(ofRandom(2,3) );
    
    //Drawing particles
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof( float4 ), 0);
	glDrawArrays(GL_POINTS, 0, n );
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    
    cam.end();
    ofPopStyle();
    

}


//--------------------------------------------------------------
void ofApp::becomeCube( bool setPos ) {       //Morphing to cube

	for(int i=0; i<n; i++) {
		//Getting random point at cube
        float rad = 400;
        ofPoint point( ofRandom(-rad, rad), ofRandom(-rad, rad), ofRandom(-rad, rad));
        
        //project point on cube's surface
        int axe = ofRandom( 0, 6 );
        if ( axe == 0 ) { point.x = ( point.x >= 0 ) ? rad : (-rad ); }
        if ( axe == 1 ) { point.y = ( point.y >= 0 ) ? rad : (-rad ); }
        if ( axe == 2 ) { point.z = ( point.z >= 0 ) ? rad : (-rad ); }
        
        if ( axe == 3 ) { point.x = ( point.x >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 4 ) { point.y = ( point.y >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 5 ) { point.z = ( point.z >= 0 ) ? rad/3 : (-rad/3 ); }
        
        
        axe = (axe + 1) % 3;
        if ( axe == 0 ) { point.x = ( point.x >= 0 ) ? rad : (-rad ); }
        if ( axe == 1 ) { point.y = ( point.y >= 0 ) ? rad : (-rad ); }
        if ( axe == 2 ) { point.z = ( point.z >= 0 ) ? rad : (-rad ); }
        
        if ( axe == 3 ) { point.x = ( point.x >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 4 ) { point.y = ( point.y >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 5 ) { point.z = ( point.z >= 0 ) ? rad/3 : (-rad/3 ); }
        
        axe = (axe + 1) % 3;
        if ( axe == 0 ) { point.x = ( point.x >= 0 ) ? rad : (-rad ); }
        if ( axe == 1 ) { point.y = ( point.y >= 0 ) ? rad : (-rad ); }
        if ( axe == 2 ) { point.z = ( point.z >= 0 ) ? rad : (-rad ); }
        
        if ( axe == 3 ) { point.x = ( point.x >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 4 ) { point.y = ( point.y >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 5 ) { point.z = ( point.z >= 0 ) ? rad/3 : (-rad/3 ); }
        
        axe = (axe + 1) % 3;
        if ( axe == 0 ) { point.x = ( point.x >= 0 ) ? rad : (-rad ); }
        if ( axe == 1 ) { point.y = ( point.y >= 0 ) ? rad : (-rad ); }
        if ( axe == 2 ) { point.z = ( point.z >= 0 ) ? rad : (-rad ); }
        
        if ( axe == 3 ) { point.x = ( point.x >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 4 ) { point.y = ( point.y >= 0 ) ? rad/3 : (-rad/3 ); }
        if ( axe == 5 ) { point.z = ( point.z >= 0 ) ? rad/3 : (-rad/3 ); }

        
        point.y -= 80;
        
        //Setting to particle
		Particle &p = particles[i];
        p.target.set( point.x, point.y, point.z, 0 );
        p.speed = 0.02;
        
        if ( setPos ) {
            particlePos[i].set( point.x, point.y, point.z, 0 );
        }
	}
    
    //upload to GPU
    particles.writeToDevice();
    if ( setPos ) {
        particlePos.writeToDevice();
    }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == ' ' ) { becomeCube( false ); }
    

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
