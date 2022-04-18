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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//my variables and functions
		float time;
		float restart;
		int seq; //to indicate number of sequence
		int obj_x;
		int speed;
		int start_side; //to indicate the number of sides of figure in the center
		int start_size; //to indicate size of figure in the center
		int space;
		void drawObject(int x, int size, int sides);
};
