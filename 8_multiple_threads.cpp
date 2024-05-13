#include<iostream>
#include<thread>
#include <sstream>

void hello(int num)
{
    if (num == 2)
    {
        std::cout<<"\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << "Hello, Thread! with ID: " << std::this_thread::get_id()<<"\n";
}

int main()
{
    // create the thread object
    std::thread thr1(hello, 1);
    std::thread thr2(hello, 2);
    std::thread thr3(hello, 3);

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr1.join();
    thr2.join();
    thr3.join();

}