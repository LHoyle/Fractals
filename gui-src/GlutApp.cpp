#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
    : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream), mMinX(-2.0), mMaxX(2.0), mMinY(-2.0), mMaxY(2.0), mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT), mMaxNumber(200), mColor1(0, 0, 255), mColor2(255, 0, 255), mNumColor(32)
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

  if (mInteractionMode == IM_FRACTAL)
  {
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
  else
  {
    if (mInteractionMode == IM_COLORTABLE)
    {

      displayColorTable();
    }
  }
  // glEnd();
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
 */
}

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
  // big M
  selectMandelbrot();
  configureGrid(600);
  // MandelbrotParameters(0.15,-0.62);
  fractalPlaneSize(-10, 1.0, -10, 1.0);

  fractalCalculate();

  gridApplyColorTable();
}
void GlutApp::createMandelbrot2()
{
  // little m
  selectMandelbrot();
  configureGrid(128);
  // MandelbrotParameters(0.15,-0.62);
  fractalPlaneSize(.2, .6, .2, .6);

  fractalCalculate();

  gridApplyColorTable();
}
void GlutApp::createComplexFractal()
{
  // big C
  selectComplexFractal();
  configureGrid(255);
  // ComplexFractalParameters(0.15,-0.62);
  fractalPlaneSize(0, .5, 0, .5);

  fractalCalculate();

  gridApplyColorTable();
}
void GlutApp::createComplexFractal2()
{
  // mini c
  selectComplexFractal();
  configureGrid(1028);
  // ComplexFractalParameters(0.15,-0.62);
  fractalPlaneSize(-2.0, 2.0, -20.0, 20.0);

  fractalCalculate();

  gridApplyColorTable();
}

//.
//.
// guipart2
//.
//.
void GlutApp::displayColorTable()
{
  glBegin(GL_POINTS);
  for (int k = mMinX; k < mMaxX; k++)
  {
    // double l = k * mNumColor / mHeight;
    for (int j = mMinY; j < mMaxY; j++)
    {
      double i = j * mNumColor / mWidth;
      //.
      //.
      // get help on this one.
      //.
      //.
      double red = mActionData.getTable()[i].getRed();
      double green = mActionData.getTable()[i].getGreen();
      double blue = mActionData.getTable()[i].getBlue();
      double truRed = red / 255.0;
      double truGreen = green / 255.0;
      double truBlue = blue / 255.0;
      glColor3d(truRed, truGreen, truBlue);
      glVertex2i(k, j);
    }
  }
  glEnd();
}

void GlutApp::setInteractionMode(InteractionMode mode)
{
  mInteractionMode = mode;
}

void GlutApp::setColorTable()
{
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mNumColor;
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-table-size", mMenuData, mActionData);
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue() << " " << mNumColor - 1 << " " << mColor2.getRed() << " "
        << mColor2.getGreen() << " " << mColor2.getBlue();
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-gradient", mMenuData, mActionData);
  /*
   mActionData.getTable().setNumberOfColors(mNumColor);
   mActionData.getTable().insertGradient(mColor1, mColor2, mMinX, mMaxX);
  */
}

void GlutApp::decreaseColorTableSize()
{
  if (mActionData.getTable().getNumberOfColors() > 10)
  {
    int newcolor = mActionData.getTable().getNumberOfColors() / 1.1;
    mActionData.getTable().setNumberOfColors(newcolor);
  }
}

void GlutApp::increaseColorTableSize()
{
  if (mActionData.getTable().getNumberOfColors() < 1024)
  {
    int newcolor = mActionData.getTable().getNumberOfColors() * 1.1;
    mActionData.getTable().setNumberOfColors(newcolor);
  }
}

void GlutApp::zoomIn()
{

  double dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  mMinX = mMinX + dx;
  mMaxX = mMaxX - dx;
  double dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  mMinY = mMinY + dy;
  mMaxY = mMaxY - dy;
}

void GlutApp::zoomOut()
{
  double dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  double dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  if (mMinX - dx >= -2.0)
  {
    mMinX = mMinX - dx;
  }
  if (mMaxX - dx <= 2.0)
  {
    mMaxX = mMaxX + dx;
  }
  if (mMinY - dy >= -2.0)
  {
    mMinY = mMinY - dy;
  }
  if (mMaxY - dy <= 2.0)
  {
    mMaxY = mMaxY + dy;
  }
}

void GlutApp::moveLeft()
{
  int dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  if (mMinX - dx > -2.0)
  {
    mMinX = mMinX - dx;
    mMaxX = mMaxX - dx;
  }
}

void GlutApp::moveRight()
{
  int dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  if (mMaxX + dx < 2.0)
  {
    mMinX = mMinX + dx;
    mMaxX = mMaxX + dx;
  }
}

void GlutApp::moveDown()
{
  int dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  if (mMinY - dy > -2.0)
  {
    mMinY = mMinY - dy;
    mMaxY = mMaxY - dy;
  }
}

void GlutApp::moveUp()
{
  int dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  if (mMaxY + dy < 2.0)
  {
    mMinY = mMinY + dy;
    mMaxY = mMaxY + dy;
  }
}

void GlutApp::setFractalMode(FractalMode mode)
{
  mFractalMode = mode;
}

void GlutApp::increaseMaxNumber()
{
  if (mMaxNumber < 2048)
  {
    mMaxNumber = mMaxNumber * 1.1;
  }
}

void GlutApp::decreaseMaxNumber()
{
  if (mMaxNumber > 11)
  {
    mMaxNumber = mMaxNumber / 1.1;
  }
}

void GlutApp::setAB(int x, int y)
{
  ComplexFractal *Mists = dynamic_cast<ComplexFractal *>(&mActionData.getGrid());
  if (mFractalMode == M_MANDELBROT && 0 != Mists)
  {
    double delta_x = (*Mists).getDeltaX();
    mA = mMinX + x * delta_x;
    double delta_y = (*Mists).getDeltaY();
    mB = mMinY + y * delta_y;
  }
}

void GlutApp::resetPlane()
{
  mMaxX = 2.0;
  mMinX = -2.0;
  mMaxY = 2.0;
  mMinY = -2.0;
}

void GlutApp::createFractal()
{
  if (mFractalMode == M_MANDELBROT)
  {
    selectMandelbrot();
  }
  else if (mFractalMode == M_JULIA)
  {
    selectJulia();
    juliaParameters(mA, mB);
  }
  else if (mFractalMode == M_COMPLEX)
  {
    selectComplexFractal();
  }
  configureGrid(mMaxNumber);
  fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
  fractalCalculate();
  gridApplyColorTable();
}