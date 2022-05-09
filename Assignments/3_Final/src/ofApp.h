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

		//Functions to displays different scenes
		void watchingP0rn();
		void instaStory();
		void messages();
		void diary();
		void spotify();

		//Variables used in all scenes
		ofTrueTypeFont font;
		ofTrueTypeFont font2;
		ofTrueTypeFont font3;
		ofTrueTypeFont font4;
		int width;
		int height;
		int cnt;
		int scene_cnt;
		int story;
		float time;

		//Variables for watchingp0rn()
		string scene;
		string text;
		string ref_text;
		ofImage browser;
		ofImage browser2;
		ofImage browser3;
		ofImage nopor;
		ofImage nopor2;
		ofImage nopor3;
		ofImage nopor4;
		ofImage nopor5;
		ofImage nopor6;
		ofImage nopor7;
		ofImage nopor8;
		ofImage nopor9;
		ofImage nopor10;

		//Variables for instaStory()
		int camera_w;
		int camera_h;
		int next_message;
		int button_y;
		bool button_clicked;
		bool button2_clicked;
		ofVideoGrabber camera;
		ofTexture videoTexture;
		string asciiCharacters;
		ofImage cat;
		
		//Variables for diary()
		ofSoundPlayer sound;
		ofImage notes;
		float *fft;
		float *soundSpectrum;
		float intensity;
		float line_width;
		float line_number;
		float audio_position;
		float line_progress;
		float opacity_progress;
		float recording_time;
		bool move_to_next;
		int bands;
		int note_transparency;

		//Variables for spotify()
		ofSoundPlayer sound2;
		ofSoundPlayer ring;
		ofImage home;
		ofImage search;
		ofImage shelf;
		ofImage play;
		ofImage pause;
		ofImage wallpaper;
		float audio2_position;
		float ring_position;
		bool diary_end;
		int play_transparency;
		int call_transparency;
};
