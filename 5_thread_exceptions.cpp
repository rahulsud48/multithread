#include<iostream>
#include<thread>

// Try and catch block should always be inside the thread function

void hello()
{
    // // Exception in hello function
    // try
    // {
    //     //Throw an exceptionm
    //     throw std::exception();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cout << e.what() << '\n';
    // }
    // std::cout<<"Hello, Thread! \n";

    // Exception in main function
    throw std::exception();
    std::cout<<"Hello, Thread! \n";
    
}

int main()
{
    // Create an std::thread object
    std::thread thr(hello);
    thr.join();

    // If exception is in main
    try
    {
        std::thread thr(hello);
        thr.join();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}