//Zack Marks and Anand Giduthuri
//CS32 S21		Prof. Wood
//Lab07

#ifndef RECT_H
#define RECT_H

#include "vec2.h"
#include "shape.h"

/* simple data representation of a rectangle */
class Rect : public shape {
  public:
	Rect(double lX, double lY, double rX, double rY, color C, double deep) : shape{C, deep},
		upperL(lX, lY), lowerR(rX, rY) {}
	
	Rect(vec2(left), vec2(right), color C, double deep) : shape{C, deep},
		upperL(left), lowerR(right) {}
	Rect(vec2(left), double width, double height, color C, double deep) : shape{C, deep},
		upperL(left), lowerR(left.x()+width,left.y()+height) {}

	bool eval(double x, double y) override {
		if ((x >= upperL.x() && x <= lowerR.x()) && (y >= upperL.y() && y <= lowerR.y())) {
			return true;
		}
		return false;
	}

	void translate(vec2 offset) {
		upperL += offset;
		lowerR += offset;
	}

	double getWidth() const {return lowerR.x() - upperL.x(); }
	double getHeight() const {return lowerR.y() - upperL.y(); }
	double getArea() const {return (lowerR.x() - upperL.x())*(lowerR.y() - upperL.y());}

	void setLCorner(vec2 inLCor) { upperL = inLCor; }
	void setRCorner(vec2 inRCor) {lowerR = inRCor;}

	void validate(){
        // Check if any vertex is less than 0
        try {
            if (upperL.x() < 0 || upperL.y() < 0 || lowerR.x() < 0 || lowerR.y() < 0)
                throw std::domain_error("rect vert less zero");
        } catch (const std::domain_error& err2) {
            this->setColor(color(0));
            std::cout << err2.what() << std::endl;
        }

        // Check vertex order
        try {
            if (upperL.y() > lowerR.y() || upperL.x() > lowerR.x())
                throw std::domain_error("rect order incorrect");
        } catch (const std::domain_error& err2) {
            // reversed corners
            if (upperL.y() > lowerR.y() && upperL.x() > lowerR.x())
                std::swap<vec2>(upperL, lowerR);
            // inverted corners (horizontal)
            else if (upperL.x() > lowerR.x()) {
                int L = lowerR.x();
                lowerR.setX(upperL.x());
                upperL.setX(L);
            }
            // inverted corners (vertical)
            else if (upperL.y() > lowerR.y()) {
                int U = lowerR.y();
                lowerR.setY(upperL.y());
                upperL.setY(U);
            }

            this->setColor(color(255, 0, 0));
            std::cout << err2.what() << std::endl;
        }
	}

  private:
	vec2 upperL;
	vec2 lowerR;

};

#endif
