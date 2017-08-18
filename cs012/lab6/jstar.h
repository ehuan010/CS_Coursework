
//class Shape header file

#ifndef __JSTAR_H__
#define __JSTAR_H__

#include "instinct.h"
#include "jshape.h"

//base class
class JStar : public JShape
{
public:
    JStar();
    JStar(Point);
		JStar(Point ll,Color c);
    JStar(Point,double);
		JStar(Point l_l, double r,Color c);
    virtual double area() const ;
    virtual void plot() const;
    // virtual ~JShape();
private:

    double radius;
};

#endif

