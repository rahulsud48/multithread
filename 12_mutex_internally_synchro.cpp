#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<vector>

using namespace std::literals;

class Vector
{
    std::mutex mut;
    std::vector<int> vec;

public:
    void push_back(const int& i)
    {
        mut.lock();

        // start of critical section
        vec.push_back(i);

        // End of critical section
        mut.unlock();
    }

    void print()
    {
        mut.lock();

        // Start of critical section
        for (auto i : vec)
        {
            std::cout << i << ", ";
        }

        mut.unlock();
    }
};

void func(Vector& vec)
{
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main()
{
    Vector vec;
    std::thread thr1(func, std::ref(vec));
    std::thread thr2(func, std::ref(vec));
    std::thread thr3(func, std::ref(vec));

    thr1.join();
    thr2.join();
    thr3.join();

}