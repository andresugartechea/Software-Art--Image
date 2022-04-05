#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetFrameRate(5);

	imageBackground.load("images/sadShower.jpg");
	gui.setup();

	//to control the thickness of the lines
	gui.add(intSlider.setup("stroke", 2, 1, 5));
	//to control the colors of the lines
	gui.add(vec3Slider.setup("color", ofVec3f(0,0,0), ofVec3f(0,0,0), ofVec3f(255,255,255)));
	//to control the limits of the drawing
	gui.add(vec4Slider.setup("frame", ofVec4f(257, 221, 383, 286), ofVec4f(0, 0, 0, 0), ofVec4f(ofGetWidth(), ofGetHeight(), ofGetWidth(), ofGetHeight())));
}

//--------------------------------------------------------------
void ofApp::update(){
	//the lines are drawn inside the frame
	myLine.addVertex(ofRandom(vec4Slider->x, vec4Slider->z), ofRandom(vec4Slider->y, vec4Slider->w));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	imageBackground.draw(0, 0, ofGetWidth(), ofGetHeight());

	ofSetColor(vec3Slider->x, vec3Slider->y, vec3Slider->z);
	ofSetLineWidth(intSlider);

	myLine.draw();
	gui.draw();
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
