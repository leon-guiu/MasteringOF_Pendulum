#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set screen frame rate
    ofSetFrameRate(60);
    
    //set intitial values
    pos0 = ofPoint(512, 300);
    pos = ofPoint(600, 200);
    velocity = ofPoint(100, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //constants
    float dt = 1.0 / 60.0;    //time step
    float mass = 0.1;         //mass of a ball
    float rubberLen = 200.0;  //segment's lenght
    float k = 0.5;            //segment's stiffness
    ofPoint g(0.0 , 9.8);   //gravity force
    
    //compute hook's force
    ofPoint delta = pos - pos0;
    float len = delta.length();  //vector's lenght
    float hookeValue = k * (len - rubberLen);
    delta.normalize ();          //normalize vector's lenght
    ofPoint hookForce = delta * (-hookeValue);
    
    //update velocity and position
    ofPoint force = hookForce + g;
    ofPoint a = force / mass;
    velocity += a * dt;
    pos += velocity * dt;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //set white background
    ofBackground(255, 255, 255);
    
    //draw rubber as a blue line
    ofSetColor(0, 0, 255);
    ofLine(pos0.x, pos0.y, pos.x, pos.y);
    
    //draw ball as a red circle
    ofSetColor(255, 0, 0);
    ofFill();
    ofCircle(pos.x, pos.y, 20);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
