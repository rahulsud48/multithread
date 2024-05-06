#include<iostream>
#include<thread>

// The parent thread might have an exception and it will stop the child thread 
// from executing and call the distructor of the child thread

void hello()
{
    std::cout<<"Hello, Thread! \n";
}

int main()
{
    std::thread thr(hello);
    // If exception is in main
    try
    {
        
        throw std::exception();
        thr.join();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        // comment the below to see core being dumped
        // thr.join();
    }
}