#ifndef _ThreadedGrid_h_
#define _ThreadedGrid_h_
#include "NumberGrid.h"
#include "ThreadedVector.h"
#include <vector>
#include <utility>

/*class thread
{
private:
    int height;
    int width;
public:
    thread();
    thread(int Hheight,int Wwidth);
    ~thread();
    int getheight();
    int getwidth();
};*/
class ThreadedGrid : public NumberGrid
{
public:
    ThreadedGrid();
    ThreadedGrid(const int &height, const int &width);
    virtual ~ThreadedGrid();
    virtual void calculateAllNumbers();
    virtual void worker();

protected:
     ThreadedVector< std::pair<int,int> > Queu;
};
#endif