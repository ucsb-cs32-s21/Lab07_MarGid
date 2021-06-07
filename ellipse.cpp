//Zack Marks and Anand Giduthuri
//CS32 S21		Prof. Wood
//Lab07

#include "ellipse.h"
#include "vec2.h"


std::ostream& operator<<(std::ostream &out, const ellipse &theEllipse) {
	out << "an ellipse\n";
	return out;
}


void ellipse:: validate(){
    // Check if center vertex is less than 0
    try {
        if (center.x() < 0 || center.y() < 0)
            throw std::domain_error("ellipse center less zero");
    } catch (const std::domain_error& err2) {
        this->setColor(color(0));
        std::cerr << err2.what() << std::endl;
    }

    // Test ellipse divide zero
    try {
        if (radii.x() == 0 || radii.y() == 0)
            throw std::underflow_error("ellipse divide zero");

    } catch (const std::underflow_error& err1) {
        if (radii.x() == 0) radii.setX(2);
        if (radii.y() == 0) radii.setY(2);
        this->setColor(color(255, 0, 0));
        std::cerr << err1.what() << std::endl;
    }
    
}