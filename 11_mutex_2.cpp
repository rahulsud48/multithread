#include<iostream>
#include<mutex>
#include<thread>
#include<string>
#include<chrono>

using namespace std::literals;


std::mutex the_mutex;


void task1 ()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "Task1 trying to lock the mutex" << std::endl;
    while(!the_mutex.try_lock())
    {
        std::cout<<"Task1 could not lock the mutex"<<std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout<<"Task1 has locked the mutex" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout<<"Task1 unlocking the mutex"<<std::endl;
    the_mutex.unlock();
}

void task2 ()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 trying to lock the mutex" << std::endl;
    while(!the_mutex.try_lock())
    {
        std::cout<<"Task2 could not lock the mutex"<<std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout<<"Task2 has locked the mutex" << std::endl;
    std::this_thread::sleep_for(200ms);
    std::cout<<"Task2 unlocking the mutex"<<std::endl;
    the_mutex.unlock();
}

int main()
{
    // create the thread object
    std::thread thr1(task1);
    std::thread thr2(task2);

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr1.join();
    thr2.join();
    
    return 0;
}