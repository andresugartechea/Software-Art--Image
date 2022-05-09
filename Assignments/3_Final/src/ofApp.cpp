#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

	//To load images
	browser.load("/images/scene1_browser.png");
	browser2.load("/images/scene1_browser2.png");
	browser3.load("/images/scene1_browser3.png");
	nopor.load("/images/scene1_str.png");
	nopor2.load("/images/scene1_str2.png");
	nopor3.load("/images/scene1_str3.png");
	nopor4.load("/images/scene1_bi.png");
	nopor5.load("/images/scene1_bi2.png");
	nopor6.load("/images/scene1_bi3.png");
	nopor7.load("/images/scene1_gay.png");
	nopor8.load("/images/scene1_gay2.png");
	nopor9.load("/images/scene1_gay3.png");
	nopor10.load("/images/scene1_salad.png");
	wallpaper.load("/images/wallpaper.jpg");
	notes.load("/images/note.jpg");
	cat.load("/images/scene2_cat.png");
	home.load("/images/home.jpg");
	search.load("/images/search.jpeg");
	shelf.load("/images/book.jpeg");
	play.load("/images/play.jpg");
	pause.load("/images/pause.jpeg");

	//To load fonts
	font.load("Courier New Bold.ttf", 9);
	font2.load("Arial.ttf", 15);
	font3.load("Arial.ttf", 25);
	font4.load("Arial.ttf", 40);

	//Used for all scenes
	width = ofGetWidth();
	height = ofGetHeight();
	story = 0;
	cnt = 0;
	time = 0;
	ofRectMode(OF_RECTMODE_CENTER);

	//For instaStory()
	camera_w = 1275;
	camera_h = 900;
	camera.setVerbose(true);
	camera.setup(camera_w, camera_h);
	ofEnableAlphaBlending();
	asciiCharacters = string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
	button_clicked = false;
	button_y = height - 120;

	//For watchP0rn()
	scene_cnt = 1;
	scene = "p0rn" + ofToString(scene_cnt);
	text = "";
	move_to_next = false;

	//For diary()
	sound.load("recording.mp3");
	intensity = 250.0;
	line_width = 512;
	line_number = 8;
	note_transparency = 0;
	fft = new float[512];
	for (int i = 0; i < 512; i++) {
		fft[i] = 0;
	}
	bands = line_width;

	//For spotify()
	sound2.load("bornThisWay.wav");
	ring.load("ringtone.wav");
	play_transparency = 255;
	call_transparency = 0;
	diary_end = false; 
}

//--------------------------------------------------------------
void ofApp::update(){

	//To update time
	time = ofGetElapsedTimeMillis()/1000;

	//For instaStory()
	camera.update();

	//For watchP0rn()
	scene = "p0rn" + ofToString(scene_cnt);

	//For diary()
	audio_position = sound.getPosition() * 100;
	ofSoundUpdate();
	soundSpectrum = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++) {
		fft[i] *= 0.9;
		if (fft[i] < soundSpectrum[i]) {
			fft[i] = soundSpectrum[i];
		}
	}

	//For spotify()
	audio2_position = sound2.getPosition();
	ring_position = ring.getPosition();
	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//To set the order of the stories/sequences
	if (story == 0) {
		ofSetBackgroundColor(0);
		wallpaper.draw(0, 0, width, height);
		ofPushStyle();
		ofSetColor(0);
		font2.drawString("Swipe up to unlock", 340, height / 2);
		ofPopStyle();
	}
	else if (story == 1) {
		watchingP0rn();
	}
	else if (story == 2) {
		instaStory();
	}
	else if (story == 3) {
		messages();
	}
	else if (story == 4) {
		diary();
	}
	else if (story == 5) {
		spotify();
	}
}

//--------------------------------------------------------------
void ofApp::watchingP0rn() {

	//For each scene, when the keys are pressed each character in 'ref_text' is drawn on screen. After typing all the characters, the next scene is called with ENTER.
	if (scene == "p0rn1") {
		ofSetColor(255);
		browser.draw(0, 0, ofGetWidth(), ofGetHeight()); //draws a background images
		ref_text = "p0rn"; //text used as reference for 'text' variable
		ofSetColor(0);
		font2.drawString(text, 235, 550); //"text" changes with key pressed
	}
	else if (scene == "p0rn2") {
		ref_text = "";
		ofSetColor(255);
		if (time < 1) {
			nopor.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 2) {
			nopor2.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 3) {
			nopor3.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else {
			nopor.draw(0, 0, ofGetWidth(), ofGetHeight());
			ofResetElapsedTimeCounter(); //to loop the animation
		}
	}
	else if (scene == "p0rn3") {
		ofSetColor(255);
		browser2.draw(0, 0, ofGetWidth(), ofGetHeight());
		ref_text = "bi p0rn";
		ofSetColor(0);
		font2.drawString(text, 235, 550);
	}
	else if (scene == "p0rn4") {
		ref_text = "";
		ofSetColor(255);
		if (time < 1) {
			nopor4.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 2) {
			nopor5.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 3) {
			nopor6.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else {
			nopor4.draw(0, 0, ofGetWidth(), ofGetHeight());
			ofResetElapsedTimeCounter();
		}
	}
	else if (scene == "p0rn5") {
		ofSetColor(255);
		browser3.draw(0, 0, ofGetWidth(), ofGetHeight());
		ref_text = "g@y p0rn";
		ofSetColor(0);
		font2.drawString(text, 235, 550);
	}
	else if (scene == "p0rn6") {
		ref_text = "";
		ofSetColor(255);
		if (time < 1) {
			nopor7.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 2) {
			nopor8.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else if (time < 3) {
			nopor9.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		else {
			nopor7.draw(0, 0, ofGetWidth(), ofGetHeight());
			ofResetElapsedTimeCounter();
		}
	}
	else if (scene == "p0rn7") {
		ofSetColor(255);
		browser3.draw(0, 0, ofGetWidth(), ofGetHeight());
		ref_text = "right in front of my salad?";
		ofSetColor(0);
		font2.drawString(text, 235, 550);
	}
	else if (scene == "p0rn8") {
		ref_text = "";
		ofSetColor(255);
		nopor10.draw(0, 0, ofGetWidth(), ofGetHeight());
		move_to_next = true; //since it's the last scene, pressing ENTER let us jump to the next story if this variable is TRUE
	}
}

//--------------------------------------------------------------
void ofApp::instaStory() {

	//This code is based on Dan Buzzo's tutorial: https://www.youtube.com/watch?v=S0ZBDbNddm4

	ofSetBackgroundColor(0);
	float alphaValue = ofMap(mouseY, height/2, button_y, 255, 0); //The transparency changes when mouseY is lower than half the screen

	//The camera effect becomes transparent when the button is reached
	ofSetColor(62, 142, 174, alphaValue);
	ofPixelsRef pixelsRef = camera.getPixels(); 

	int effect_w = 0;
	// "here we make a loop that loops through from 0 to camWidth, in steps of 7" - Dan Buzzo
        for (int i = 0; i < camera_w - effect_w; i+= 7){
    // "inside this is another loop that loops from 0 to the camHeight in steps of 9" - Dan Buzzo
			for (int j = 0; j < camera_h; j+= 9){
                // "get the pixel and its lightness (lightness is the average of its RGB values)" - Dan Buzzo
				float lightness = pixelsRef.getColor(i,j).getLightness();

                // "calculate the index of the character from our asciiCharacters array" - Dan Buzzo
                int character = powf(ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();

                // "draw the character at the correct location" - Dan Buzzo
                font.drawString(ofToString(asciiCharacters[character]), width-i, j);
            }
        }

	//Draw a picture of a cat when button is reached
	ofSetColor(255, 255, 255, 255-alphaValue);
	cat.draw(0, 0, width, height);

	//draw button
	ofSetColor(255);
	ofSetCircleResolution(100);
	ofDrawCircle(width / 2, button_y, 60);
	ofPushStyle();
	ofSetColor(0);
	ofNoFill();
	ofSetLineWidth(4);
	ofDrawCircle(width / 2, button_y, 52);
	ofPopStyle();

	//"Your story" button appears after clicking the first button
	if (button_clicked) {
		ofSetColor(255);
		cat.draw(0, 0, width, height);
		ofSetColor(0, 200);
		ofDrawRectRounded(50, button_y, 300, 70, 90);
		ofSetColor(255, 200);
		ofDrawCircle(105, 815, 20);
		font3.drawString("Your story", 155, 825);
	}
}

//--------------------------------------------------------------
void ofApp::messages() {

	//This part displays chat boxes that rotate according to the mouse position. They display a message when the rotation is slight

	ofSetBackgroundColor(0);
	
	int messages_w = 2*width/3;
	int messages_h = height/10;
	int start_x = 100;
	int start_y = 80;
	int sep = 40;

	int transp = 240;
	int transp1 = 0;
	int transp2 = 0;
	int transp3 = 0;
	int transp4 = 0;
	int transp5 = 0;
	int transp6 = 0;
	
	int ver_rot = ofMap(mouseY, 0, height, 0, 720);
	int hor_rot = ofMap(mouseX, 0, width, 0, 720);

	//initial rotation of each chat box
	int mess1_rot = -40;
	int mess2_rot = -6;
	int mess3_rot = -5;
	int mess4_rot = 20;
	int mess5_rot = 5;
	int mess6_rot = -5;

	//Count (cnt) changes when mouse is pressed and the chat box has a minimum rotation
	if (cnt == 0) {
		mess1_rot += ver_rot;
	}
	else if (cnt == 1) {
		mess1_rot = 0;
		mess2_rot += hor_rot;

		transp1 = 255;
	}
	else if (cnt == 2) {
		mess1_rot = 0;
		mess2_rot = 0;
		mess3_rot += ver_rot;

		transp1 = 255;
		transp2 = 255;
	}
	else if (cnt == 3) {
		mess1_rot = 0;
		mess2_rot = 0;
		mess3_rot = 0;
		mess4_rot += hor_rot;

		transp1 = 255;
		transp2 = 255;
		transp3 = 255;
	}
	else if (cnt == 4) {
		mess1_rot = 0;
		mess2_rot = 0;
		mess3_rot = 0;
		mess4_rot = 0;
		mess5_rot += ver_rot;

		transp1 = 255;
		transp2 = 255;
		transp3 = 255;
		transp4 = 255;
	}
	else if (cnt == 5) {
		mess1_rot = 0;
		mess2_rot = 0;
		mess3_rot = 0;
		mess4_rot = 0;
		mess5_rot = 0;
		mess6_rot += ver_rot;

		transp1 = 255;
		transp2 = 255;
		transp3 = 255;
		transp4 = 255;
		transp5 = 255;
	}
	else if (cnt == 6) {
		mess1_rot = 0;
		mess2_rot = 0;
		mess3_rot = 0;
		mess4_rot = 0;
		mess5_rot = 0;
		mess6_rot = 0;

		transp1 = 255;
		transp2 = 255;
		transp3 = 255;
		transp4 = 255;
		transp5 = 255;
		transp6 = 255;
	}


	//// FOR MESSAGE 1
	ofPushMatrix();
	ofRotateX(mess1_rot);
	if ((cnt == 0) && (((mess1_rot < 10) && (mess1_rot > -10)) || ((mess1_rot < 370) && (mess1_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 2; //when rotation is minimun, it enables the option to go to the next message
		transp1 = 255;
	}
	else {
		ofSetColor(255);
		next_message = 1;
	}
	ofDrawRectangle(start_x, start_y, messages_w, messages_h);
	ofSetColor(0,0,0, transp1);
	font4.drawString("Yes! Another one of us", 134, 141);
	ofPopMatrix();


	//// FOR MESSAGE 2
	ofPushMatrix();
	ofRotateY(mess2_rot);
	if ((cnt == 1) && (((mess2_rot < 10) && (mess2_rot > -10)) || ((mess2_rot < 370) && (mess2_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 3;
		transp2 = 255;
	}
	else {
		ofSetColor(56, 120, 231);
	}
	ofDrawRectangle(470, start_y + messages_h + sep, height-100-470, messages_h);
	ofSetColor(255, transp2);
	font4.drawString("Huh, wdym?", 488, 272);
	ofPopMatrix();

	//// FOR MESSAGE 3
	ofPushMatrix();
	ofRotateZ(mess3_rot);
	if ((cnt == 2) && (((mess3_rot < 10) && (mess3_rot > -10)) || ((mess3_rot < 370) && (mess3_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 4;
		transp3 = 255;
	}
	else {
		ofSetColor(255);
	}
	ofDrawRectangle(start_x, start_y + messages_h * 2 + sep * 2, messages_w-30, messages_h);
	ofSetColor(0, 0, 0, transp3);
	font4.drawString("A pusss..cat lover! Qt", 134, 405);
	ofPopMatrix();

	//// FOR MESSAGE 4
	ofPushMatrix();
	ofRotateY(mess4_rot);
	if ((cnt == 3) && (((mess4_rot < 10) && (mess4_rot > -10)) || ((mess4_rot < 370) && (mess4_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 5;
		transp4 = 255;
	}
	else {
		ofSetColor(56, 120, 231);
	}
	ofDrawRectangle(470, start_y + messages_h * 3 + sep * 3, height - 100 - 470, messages_h);
	ofSetColor(255, transp4);
	font4.drawString("Haha lol thx", 488, 535);
	ofPopMatrix();

	//// FOR MESSAGE 5
	ofPushMatrix();
	ofRotateZ(mess5_rot);
	if ((cnt == 4) && (((mess5_rot < 10) && (mess5_rot > -10)) || ((mess5_rot < 370) && (mess5_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 6;
		transp5 = 255;
	}
	else {
		ofSetColor(255);
	}
	ofDrawRectangle(start_x, start_y + messages_h * 4 + sep * 4, messages_w-60, messages_h);
	ofSetColor(0, 0, 0, transp5);
	font4.drawString("What are you up to?", 134, 663);
	ofPopMatrix();

	//// FOR MESSAGE 6
	ofPushMatrix();
	ofRotateX(mess6_rot);
	if ((cnt == 5) && (((mess6_rot < 10) && (mess6_rot > -10)) || ((mess6_rot < 370) && (mess6_rot > 350)))) {
		ofSetColor(255, 255, 0, transp);
		next_message = 7;
		transp6 = 255;
	}
	else {
		ofSetColor(56, 120, 231);
	}
	ofDrawRectangle(403, start_y + messages_h * 5 + sep * 5, height - 100 - 403, messages_h);
	ofSetColor(255, transp6);
	font4.drawString("Just chillin wbu", 422, 794);
	ofPopMatrix();

	//After displaying last message, it enables to option to jump to the next story after mouse is pressed
	if (cnt == 6) {
		next_message = 8;
	}
}

//--------------------------------------------------------------
void ofApp::diary() {

	//This code is based on Lewis Lepton's tutorial: https://www.youtube.com/watch?v=DfiIvAdrlRg&t=453s
	ofSetBackgroundColor(231, 207, 138);

	line_progress = ofMap(audio_position, 0, 100, 0, 512); //gain/lose width with audio position
	opacity_progress = ofMap(audio_position, 0, 100, 0, 255); //gain/lose opacity with audio position

	ofPushMatrix();
	ofTranslate(192, 200);
	for (int i = 0; i < line_progress; i += (line_width / line_number)) {
		ofPolyline polyline;
		for (int j = 0; j < line_progress; j++) {
			polyline.addVertex(j, i - fft[j] * intensity);

		}
		ofSetColor(0, 0, 0, 255-opacity_progress); //lines become transparent at the end of the audio
		polyline.draw();
	}
	ofPopMatrix();
	if ((audio_position > 0) && (audio_position < 99)) {
		note_transparency = opacity_progress / 3 * 2;
	}
	else if (audio_position > 99) {
		note_transparency == 255;
		diary_end = true;
	}
	ofSetColor(255, 255, 255, note_transparency); //lines become less transparent with audio progression
	notes.draw(84, 55, ofGetWidth()*0.8, ofGetHeight()*0.8);
}

//--------------------------------------------------------------
void ofApp::spotify() {

	//This part is based on Dan Buzzo's tutorial: https://www.youtube.com/watch?v=SSEnu6mp7y8
	
	ofSetBackgroundColor(0);

	//For pulsing circle
	ofColor drawColor;
	int length = 700;
	int barWidth = 20;
	float bandsToGet = 512;
	float width = (float)(5 * 128) / bandsToGet;
	float *val = ofSoundGetSpectrum(bandsToGet);

	for (int i = 0; i < bandsToGet; i++) {
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		ofRotateDeg(360.0 / bandsToGet * i);
		drawColor.setHsb(255 / bandsToGet * i, 255, 255, 100);
		ofSetColor(drawColor);
		ofDrawRectangle(100, barWidth / 2, val[i] * length, barWidth / 2);
		ofPopMatrix();

		//Audio progress
		ofSetColor(255);
		for (int j = 0; j < 3; j++) {
			ofDrawRectangle((j * 20) + 300, ofGetHeight() - 110, ofMap(audio2_position, 0, 1, 20, ofGetWidth() / 4 - 50), 5);
		}

		//Spotify text
		ofSetColor(255);
		ofDrawBitmapString("For You Playlist", 300, 170);

		//Spotify background
		ofSetColor(255, 255, 255, 180);
		home.draw(ofGetWidth() / 2 - 205, ofGetHeight() - 70, 70, 70);
		search.draw(ofGetWidth() / 2 - 40, ofGetHeight() - 65, 60, 60);
		shelf.draw(ofGetWidth() / 2 + 100, ofGetHeight() - 95, 120, 120);
		pause.draw(ofGetWidth() / 2 - 215, ofGetHeight() - 225, 100, 100);

		ofSetColor(0, 0, 0, call_transparency);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

		ofSetColor(255, 255, 255, play_transparency);
		play.draw(ofGetWidth() / 2 - 205, ofGetHeight() - 215, 75, 75);

		//ringtone & end of pride music
		if (audio2_position > 0.90) {
			play_transparency = 255;
			ring.play(); //ring tone starts after song ends
			call_transparency = 255;
		}

		//Message appears after song ends
		ofSetColor(170, 1, 20, call_transparency);
		ofDrawRectangle(ofGetWidth() / 2 - 200, ofGetHeight() / 2 - 50, 400, 100);
		ofSetColor(255, 255, 255, call_transparency);
		ofDrawBitmapString("Call from: DAD (p.s. don't pick up)", ofGetWidth() / 2 - 150, ofGetHeight() / 2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	//For watchP0rn()
	if (story == 1) {
		if (key != OF_KEY_RETURN) {
			if (cnt < ref_text.length()) {
				cnt++;
			}
			else {
				cnt = ref_text.length();
			}
			text = ref_text.substr(0, cnt);
		}
		else if ((cnt == ref_text.length()) && (key == OF_KEY_RETURN)) {
			cnt = 0;
			text = ref_text.substr(0, cnt);
			scene_cnt += 1;
			ofResetElapsedTimeCounter();
		}
		if ((move_to_next == true) && (key == OF_KEY_RETURN)) {
			cnt = 0;
			story = 4;
			sound.play();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//for spotify()
	if (story == 5) {
		if (key == ' ') {
			sound2.play();
			play_transparency = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (story == 0) {
		story = 2;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	//For instagramStory()
	if (story == 2) {
		if ((mouseX > width / 2 - 60) && (mouseX < width / 2 + 60) && (mouseY > button_y - 60) && (mouseY < button_y + 60)) {
			button_clicked = true;
		}
		if ((button_clicked) && (mouseX > 50) && (mouseX < 350) && (mouseY > button_y) && (mouseY < button_y + 70)) {
			story = 3;
		}
	}

	//For messages()
	if (story == 3) {
		if (next_message == 2) {
			cnt = 1;
		}
		else if (next_message == 3) {
			cnt = 2;
		}
		else if (next_message == 4) {
			cnt = 3;
		}
		else if (next_message == 5) {
			cnt = 4;
		}
		else if (next_message == 6) {
			cnt = 5;
		}
		else if (next_message == 7) {
			cnt = 6;
		}
		else if (next_message == 8) {
			story = 1;
			cnt = 0;
		}
	}

	//For diary() after recording finishes playing
	if ((story == 4) && (diary_end == true)) {
		story = 5;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

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
