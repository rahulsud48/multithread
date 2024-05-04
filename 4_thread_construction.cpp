#include<iostream>
#include<thread>
#include <sstream>

void hello()
{
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Hello, Thread! with ID: " << std::this_thread::get_id()<<"\n";
}

void func(std::thread thr)
{
    std::cout << "Received thread with ID "<<thr.get_id() << "\n";

    // The function argument now owns the system thread
    // It is responsible for calling join
    thr.join();
}

std::thread func1()
{
    std::thread thr(hello);
    std::cout << "Received thread with ID "<<thr.get_id() << "\n";

    return thr;
}

int main()
{
    // std::thread is a move only object
    std::thread thr1(hello);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout<<"Hello thread ID "<<thr1.get_id()<<"\n";

    

    std::thread thr2 = func1();
    func(std::move(thr1));

    thr2.join();


}

