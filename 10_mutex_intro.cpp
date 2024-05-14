// Mutex acts like a gate keeper, once a thread enters a critical section where data is a global variable, it will allow
// only one thread to enter and other threads need to wait

#include<iostream>
#include<mutex>
#include<thread>
#include<string>


std::mutex task_mutex;


void print (const std::string& str)
{
    for (int i=0; i<5; i++)
    {
        task_mutex.lock();

        std::cout << str[0] << str[1] << str[2] << "\n";

        task_mutex.unlock();
    }
}

int main()
{
    // create the thread object
    std::thread thr1(print, "abc");
    std::thread thr2(print, "pqr");
    std::thread thr3(print, "xyz");

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr1.join();
    thr2.join();
    thr3.join();
    
    return 0;
}