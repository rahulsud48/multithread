#include<iostream>
#include<thread>

void hello()
{
    std::cout << "Hello, Thread!" << "\n";
}

int main()
{
    // create the thread object
    std::thread thr(hello);

    // display the child thread native handle
    std::cout << "Hello thread has native handle "<<thr.native_handle()<<"\n";

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr.join();

    // display the child thread native handle
    std::cout << "Hello thread has native handle "<<thr.native_handle()<<"\n";
}