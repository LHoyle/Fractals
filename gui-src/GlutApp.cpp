#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
    : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream),mMinX(-2),mMinY(-2),mMaxX(2),mMaxY(2),mInteractionMode(IM_FRACTAL),mFractalMode(M_MANDELBROT),mMaxNumber(200),mColor1(0,0,255),mColor2(255,0,255)
{
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);
  setColorTable();
  createFractal();

  // // read1
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("pretty-mandel-1.ppm");
  // takeAction("read1", mMenuData, mActionData);

  // // copy
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("");
  // takeAction("copy", mMenuData, mActionData);
}

void GlutApp::setSize(int height, int width)
{
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const
{
  return mHeight;
}
int GlutApp::getWidth() const
{
  return mWidth;
}

void GlutApp::display()
{
  if(InteractionMode == IM_FRACTAL){
  PPM &p = mActionData.getOutputImage();
  double max = static_cast<double>(p.getMaxColorValue());
  double r, g, b;
  int row, column;
  glBegin(GL_POINTS);
  for (row = 0; row < p.getHeight(); row++)
  {
    for (column = 0; column < p.getWidth(); column++)
    {
      r = p.getChannel(row, column, 0) / max;
      g = p.getChannel(row, column, 1) / max;
      b = p.getChannel(row, column, 2) / max;
      glColor3d(r, g, b);
      glVertex2i(column, p.getHeight() - row - 1);
    }
  }
  glEnd();
  }
  else{ if (InteractionMode == IM_COLORTABLE){
    displayColorTable();
  }}
  glEnd();
}

void GlutApp::selectJulia()
{
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
}
void GlutApp::selectMandelbrot()
{
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("mandelbrot", mMenuData, mActionData);
}
void GlutApp::selectComplexFractal()
{
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("complex-fractal", mMenuData, mActionData);
}
void GlutApp::configureGrid(int max)
{
  // grid
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << max;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);
}
void GlutApp::juliaParameters(double a, double b)
{
  // julia-parameters
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << a << " " << b;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);
}
void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max)
{
  // fractal-plane-size
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " " << y_min << " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);
}
void GlutApp::fractalCalculate()
{

  // fractal-calculate
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("fractal-calculate", mMenuData, mActionData);
}
void GlutApp::gridApplyColorTable()
{
  // grid-apply-color-table
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("grid-apply-color-table", mMenuData, mActionData);
}
//.
//.
//.
// creating
//.
//.
//.
void GlutApp::createJulia()
{
  // J
  selectJulia();
  configureGrid(255);
  juliaParameters(0.15, -0.62);
  fractalPlaneSize(-10.0, 10.0, -5.0, 7.0);
  fractalCalculate();
  gridApplyColorTable();
  // julia
 /*mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
*/}

 void GlutApp::createJulia2()
 {
   // little j
   selectJulia();
   configureGrid(255);
   juliaParameters(0.35, -0.62);
   fractalPlaneSize(0, 10.0, -10.0, 0);

   fractalCalculate();

   gridApplyColorTable();
 }
 void GlutApp::createMandelbrot()
 {
    //big M
   selectMandelbrot();
   configureGrid(600);
   // MandelbrotParameters(0.15,-0.62);
   fractalPlaneSize(-10, 1.0, -10, 1.0);

   fractalCalculate();

   gridApplyColorTable();
 }
 void GlutApp::createMandelbrot2()
 {
    //little m
   selectMandelbrot();
   configureGrid(128);
   // MandelbrotParameters(0.15,-0.62);
   fractalPlaneSize(.2, .6, .2, .6);

   fractalCalculate();

   gridApplyColorTable();
 }
 void GlutApp::createComplexFractal()
 {
  //big C
   selectComplexFractal();
   configureGrid(255);
   // ComplexFractalParameters(0.15,-0.62);
   fractalPlaneSize(0, .5, 0, .5);

   fractalCalculate();

   gridApplyColorTable();
 }
 void GlutApp::createComplexFractal2()
 {
  //mini c
   selectComplexFractal();
   configureGrid(1028);
   // ComplexFractalParameters(0.15,-0.62);
   fractalPlaneSize(-2.0, 2.0, -20.0, 20.0);

   fractalCalculate();

   gridApplyColorTable();
 }
