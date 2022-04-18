#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	time = 0;
	restart = 0;
	seq = 1;
	obj_x = 0;
	speed = 5;
	start_side = 3;
	start_size = 20;
	space = 15;
}

//--------------------------------------------------------------
void ofApp::update(){
	time = ofGetElapsedTimef() - restart;

	if (time >= 10) {
		restart = 10;
		seq = 1;
	}
	else if (time >= 5) {
		seq = 2;
	}


	obj_x += speed;

	if ((obj_x >= ofGetWidth())||(obj_x == 0)) {
		speed = -speed;
		if (start_side <= 8) {
			start_side++;
		}
		else {
			start_side = 2;
			start_side++;
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (seq == 1) {
		ofSetBackgroundColor(255);
	}
	else if (seq == 2) {
		ofSetBackgroundColor(255, 255, 0);
	}

	for (int i = 0; i < 100; i++) {
		int fade = i;
		if (fade < 255) {
			ofSetColor(0, 0, 0, 255-i * 12);
		}
		else {
			ofSetColor(255);
		}
		drawObject(obj_x, start_size+i*space, start_side+i);
	}

	//ofLog(OF_LOG_NOTICE, ofToString(time));
}

//--------------------------------------------------------------
void ofApp::drawObject(int x, int size, int sides) {
	ofNoFill();
	ofSetLineWidth(4);
	ofSetCircleResolution(sides);
	ofDrawCircle(x, ofGetHeight()/2, size);
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
