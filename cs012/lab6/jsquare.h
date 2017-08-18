//square header file

#ifndef __JSquare_H__
#define __JSquare_H__

#include "jrectangle.h"
#include "instinct.h"

class JSquare : public JRectangle
{
public:
    JSquare();
    JSquare(Point c);
		JSquare(Point c, Color col);
    JSquare(Point c, double side);
		JSquare(Point c, double side, Color color);

    virtual double area() const;
    virtual void plot() const;
    virtual ~JSquare();

private:
    double side;
};

#endif
