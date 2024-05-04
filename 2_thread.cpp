#include<iostream>
#include<thread>
#include <sstream>

void hello()
{
    std::cout << "Hello, Thread! with ID: " << std::this_thread::get_id()<<"\n";
}

int main()
{
    // Display the main function thread id
    std::cout<<"The main function thread id is: "<<std::this_thread::get_id()<<"\n";
    
    // create the thread object
    std::thread thr(hello);

    // display the child thread ID
    std::stringstream thread_id;
    thread_id << thr.get_id();
    std::cout << "Hello thread has ID "<<thread_id.str()<<"\n";

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr.join();

    // display the child thread ID
    std::cout << "Hello thread has ID "<<thr.get_id()<<"\n";
}