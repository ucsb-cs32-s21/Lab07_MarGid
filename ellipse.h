//Zack Marks and Anand Giduthuri
//CS32 S21		Prof. Wood
//Lab07

#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <iostream>
#include "color.h"
#include "vec2.h"
#include "shape.h"

/* simple data representation of an implicit ellipse */
class ellipse : public shape {
  public:
	ellipse(double cX, double cY, double r1, double r2, color C) : shape{C, 0}, 
		center(cX, cY), radii(r1, r2) {}
	ellipse(vec2 inC, double r1, double r2, double d, color C) : shape{C, d},
		 center(inC), radii(r1, r2) {}
	ellipse(vec2 inC, vec2 inR, double d, color C) : shape{C, d},
		 center(inC), radii(inR) {}
	ellipse(double cX, double cY, double r1, double r2, double d, color C) : shape{C, d},
		center(cX, cY), radii(r1, r2) {}

	bool eval(double x, double y) override {
		if( ((center.x()-x)*(center.x()-x))/(radii.x()*radii.x()) + 
				((center.y()-y)*(center.y()-y))/(radii.y()*radii.y()) - 1.0f < 0) {
			return true;
		}
		return false;
	}
	//note lifted getters

	double getMaxR() {return fmax(radii.x(), radii.y());}
	vec2 getCenter() const { return center; }

	void setCenter(vec2 inCenter) { center = inCenter; }

	void validate(){
    // Check if center vertex is less than 0
    try {
        if (center.x() < 0 || center.y() < 0)
            throw std::domain_error("ellipse center less zero");
    } catch (const std::domain_error& err2) {
        this->setColor(color(0));
        std::cout << err2.what() << std::endl;
    }

    // Test ellipse divide zero
    try {
        if (radii.x() == 0 || radii.y() == 0)
            throw std::underflow_error("ellipse divide zero");

    } catch (const std::underflow_error& err1) {
        if (radii.x() == 0) radii.setX(2);
        if (radii.y() == 0) radii.setY(2);
        this->setColor(color(255, 0, 0));
        std::cout << err1.what() << std::endl;
    }
    
}

  private:
	vec2 center; //center point of ellipse
	vec2 radii; //radii of the ellipse
	//note lifted data
};


#endif