#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetCircleResolution(36);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofColor color;
	if (ofRandom(100) < 50) {

		this->locations.push_back(glm::vec2());
		this->velocities.push_back(glm::normalize(glm::vec2(ofRandom(-1, 1), ofRandom(-1, 1))) * 2);
		color.setHsb(ofRandom(255), 255, 255);
		this->colors.push_back(color);
	}

	for (int i = this->locations.size() - 1; i > -1; i--) {

		this->locations[i] += this->velocities[i];

		if (glm::length(this->locations[i]) > 720){

			this->locations.erase(this->locations.begin() + i);
			this->velocities.erase(this->velocities.begin() + i);
			this->colors.erase(this->colors.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (int i = 0; i < this->locations.size(); i++) {

		ofSetColor(this->colors[i]);

		float radius = (2 * PI * glm::length(this->locations[i])) / 360 * 10;
		ofDrawCircle(this->locations[i], radius);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}