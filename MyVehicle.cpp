#include "MyVehicle.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

MyVehicle::MyVehicle(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;
}

void MyVehicle::draw()
{
	glPushMatrix();

	glTranslatef(x, y, z);
	glRotated(-rotation, 0, 1, 0);

	RectangularPrism rectangle = RectangularPrism(0, 0, 0,  4, 2, 4);
	rectangle.setColor(red, green, blue);
	rectangle.draw();

	TriangularPrism triangle = TriangularPrism(4, 0, 0, 4, 2, 4, 0.5);
	triangle.setColor(red, green, blue);
	triangle.draw();

	TrapezoidalPrism trapezoid = TrapezoidalPrism(0, 2, 0, 4, 2, 4, 1, 1);
	trapezoid.setColor(red, green, blue);
	trapezoid.draw();

	Cylinder leftCircle = Cylinder(0, 0, -3, 2, 1);
	leftCircle.setColor(red, green, blue);
	leftCircle.draw();

	Cylinder rightCircle = Cylinder(0, 0, 2, 2, 1);
	rightCircle.setColor(red, green, blue);
	rightCircle.draw();

	glPopMatrix();
};
