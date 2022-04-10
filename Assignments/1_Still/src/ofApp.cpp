#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("A Pair of Lovers");
	ofSetFrameRate(20);
	linePercent = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
	linePercent += 0.01;

	myLine.curveTo(68, 561);
	myLine.curveTo(586, 924);

	myLine.curveTo(122, 863);
	myLine.curveTo(325, 504);
	myLine.curveTo(358, 763);
	myLine.curveTo(548, 618);

	myLine.curveTo(548, 618);
	myLine.curveTo(499, 752);
	myLine.curveTo(499, 752);
	myLine.curveTo(358, 763);
	myLine.curveTo(499, 752);
	myLine.curveTo(586, 924);
	myLine.curveTo(322, 740);
	myLine.curveTo(311, 756);
	myLine.curveTo(398, 399);
	myLine.curveTo(504, 312);
	myLine.curveTo(398, 399);
	myLine.curveTo(594, 553);
	myLine.curveTo(594, 553);
	myLine.curveTo(751, 191);
	myLine.curveTo(504, 312);
	myLine.curveTo(932, 522);
	myLine.curveTo(580, 349);
	myLine.curveTo(590, 324);


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(255);

	//For circles 
	ofSetCircleResolution(500);
	ofSetColor(255, 0, 0);
	ofDrawCircle(288, 474, 12);
	ofDrawCircle(297, 924, 12);
	ofDrawCircle(671, 588, 12);
	ofDrawCircle(611, 57, 12);
	ofDrawCircle(436, 265, 12);

	//For Lines
	ofSetLineWidth(4);
	ofSetColor(0);
	ofDrawLine(68, 561, 586, 924);
	ofDrawLine(122, 863, 325, 504);
	ofDrawLine(358, 763, 548, 618);
	ofDrawLine(548, 618, 499, 752);
	ofDrawLine(499, 752, 358, 763);
	ofDrawLine(499, 752, 586, 924);
	ofDrawLine(322, 740, 311, 756);
	ofDrawLine(398, 399, 504, 312);
	ofDrawLine(398, 399, 594, 553);
	ofDrawLine(594, 553, 751, 191);
	ofDrawLine(504, 312, 932, 522);
	ofDrawLine(580, 349, 590, 324);
	
	//For Beziers
	ofSetCurveResolution(100);
	ofDrawBezier(68, 561, 28, 674, 33, 770, 122, 863);
	ofDrawBezier(228, 672, 241, 722, 280, 744, 322, 740);
	ofDrawBezier(217, 697, 232, 733, 273, 760, 311, 756);
	ofDrawBezier(325, 504, 439, 400, 506, 600, 594, 553);
	ofDrawBezier(398, 399, 403, 465, 544, 561, 548, 618);
	ofDrawBezier(580, 349, 615, 342, 647, 360, 663, 390);
	ofDrawBezier(590, 324, 625, 320, 653, 336, 676, 364);
	ofDrawBezier(751, 191, 897, 243, 975, 400, 932, 522);

	//For animation of circles 
	ofSetColor(255,0,0);
	ofDrawCircle(myLine.getPointAtPercent(linePercent), 30);
	ofDrawCircle(myLine.getPointAtPercent(linePercent*1.05), 30);
	linePercent = 0.0;

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
