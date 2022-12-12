#include "ThreadedGrid.h"
#include <thread>
#include <vector>
#include <mutex>
ThreadedGrid::ThreadedGrid()
    : NumberGrid(), Queu()
{
    // Queu{1*1};
    // std::make_pair(0,0);
    // Queu.push_back(position);
}

ThreadedGrid::ThreadedGrid(const int &height, const int &width)
    : NumberGrid(height, width), Queu()
{
    // Queu = ThreadedVector<std::pair<int,int>>(height*width);
    // Queu.push_back(position);
    // Queu=std::make_pair(height,width);
}

ThreadedGrid::~ThreadedGrid() {}
void ThreadedGrid::worker()
{
    std::vector<std::pair<int, int>> possition;
    while (Queu.empty() != true)
    {
        possition.clear();
        
        Queu.pop_back(possition,1);
        if(possition.size()>0){
        std::pair<int,int> possitionnew=possition[0];
        int num = calculateNumber(possitionnew.first, possitionnew.second);
        setNumber(possitionnew.first, possitionnew.second, num);
        }

    }
}
void ThreadedGrid::calculateAllNumbers()
{
    std::vector<std::thread> threads;
    for (int i=0; i < getHeight(); i++)
    {
        for (int j=0; j < getWidth(); j++)
        {
            Queu.push_back(std::pair<int,int>(i, j));
        }
    }
    int max_threads = std::thread::hardware_concurrency();
    for (int thread = 0; thread < max_threads; thread++)
    {
        // this -> worker();
        try
        {
            threads.push_back(std::thread(&ThreadedGrid::worker, this));
        }
        catch (...)
        {
            std::cout << "error, failed to make thread"<<std::endl;
        }
    }

    for (int i = 0; i < max_threads; i++)
    {
        threads[i].join();
    }
}
