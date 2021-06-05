#ifndef CREATEIMAGE_H
#define CREATEIMAGE_H


//#include "image.h"
/*write out PPM data, using the defined implicit equation 
interior points write a differnt color then exterior points */

//color
template <typename T>
void createImage(image<T>& theImg, 
				vector<shared_ptr<shape>> theShapes, T inC) {

	//float res;
	//color drawC;

	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					inC = eq->getInC();
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}

//grey
template <>
void createImage(image<int>& theImg, 
				vector<shared_ptr<shape>> theShapes, int inC) {

	//float res;
	color drawC = color(inC);
	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					inC = eq->getInC().bright();
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}
//char
template <>
void createImage(image<char>& theImg, 
				vector<shared_ptr<shape>> theShapes, char inC) {

	//float res;
	//color drawC;
	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					//inC = eq->getInC();
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {
				cout << inC;			
				//theImg.setPixel(x, y, inC);
			}
		}
	}
}
//bit
template <>
void createImage(image<bool>& theImg, 
				vector<shared_ptr<shape>> theShapes, bool inC) {

	//float res;
	//color drawC = color();
	if(inC);
		//drawC.setC(color(255,255,255));
	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					//inC = eq->getInC();
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {
				theImg.setPixel(x, y, inC);
			}
		}
	}
}
#endif