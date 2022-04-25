#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//to initialize audio
	sound.load("century_arca.mp3");
	sound.play();
	sound.setLoop(true);

	fft = new float[512]; //max possible
	for (int i = 0; i < 512; i++) {
		fft[i] = 0;
	}
	bands = 512; //numbers of points to draw the visualization

	time = 0; //audio time
	obj_x = 100; //espace in the middle
}

//--------------------------------------------------------------
void ofApp::update(){
	time = sound.getPosition()*10;
	transp = time * 5;

	//for audio
	ofSoundUpdate();
	soundSpectrum = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++) {
		fft[i] *= 0.9;
		if (fft[i] < soundSpectrum[i]) {
			fft[i] = soundSpectrum[i];
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

	for (int i = 0; i < bands; i += 16){
		ofPolyline polyline;
		for (int j = 0; j < bands; j++) {
			ofSetColor(255, 0, 0, transp); //more clear the more time it passes
			drawObject(obj_x, fft[j] * 200.0, 10);
			ofSetColor(0, 0, 255, 50 - transp); //loses clarity the more time it passes
			polyline.addVertex(j, fft[j] * 100.0);
		}
		ofRotateDeg(45, 0, 0, 1); //this creates the vortex effect
		polyline.draw();
	}

}

//--------------------------------------------------------------
void ofApp::drawObject(int x, int size, int sides) {
	ofNoFill();
	ofSetLineWidth(1);
	ofSetCircleResolution(sides);
	ofDrawCircle(x, 0, size);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		sound.setPosition(0.0f);
	}

	//Commented out: this part helped me check is the transparency was linked to the audio
	//if (key == ' ') {
	//	ofLog(OF_LOG_NOTICE, ofToString(transp));
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
