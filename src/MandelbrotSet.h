#ifndef _MandelbrotSet_H_
#define _MandelbrotSet_H_
#include "ComplexFractal.h"
class MandelbrotSet : public ComplexFractal

{
public:
MandelbrotSet( );
MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y );
virtual ~MandelbrotSet( );
//double getA( ) const;
//double getB( ) const;
//void setParameters( const double& a, const double& b );
//virtual void calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const;
virtual void calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const;
virtual int calculatePlaneEscapeCount( const double& x0, const double& y0 ) const;
virtual int calculateNumber( const int& row, const int& column ) const;

protected:
};

#endif


#ifndef _MandelbrotSetPower_H_
#define _MandelbrotSetPower_H_
#include "ComplexFractal.h"
 class MandelbrotPower  : public MandelbrotSet
 {
 public:
    MandelbrotPower();
    ~MandelbrotPower();
    double getPower() const;
    void setPower(const double& power);
    virtual void calculateNextPoint(const double x0, const double y0, const double& a, const double& b, double& x1, double &y1) const;
 protected:
    double UnlimitedPower;/* data */
 };
 
 

#endif
