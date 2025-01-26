#include <iostream>
#include <queue>

//TASK 1
bool isSorted(std::queue<int> Queue)
{
    if(Queue.empty()) return true;

    std::queue<int> x = Queue;

    for(int i = x.front(); x.size() != 0; i = x.front())
    {
        x.pop(); // попваме фронта
        if(i>x.front())
        {
            return false;
        }
    }
    return true;
}

//TASK 2

