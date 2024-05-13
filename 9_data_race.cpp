#include<iostream>
#include<thread>
#include <sstream>

std::string str_ = "pqr";

void print(std::string curr)
{
    for (int i=0; i<8; i++)
    {
        str_[i] = curr[i];
    }
}

int main()
{
    // create the thread object
    std::thread thr1(print, "abcdefgh");
    std::thread thr2(print, "qrstuvwx");
    std::thread thr3(print, "ijklmnop");

    // wait for the thread to complete
    // this calls the distructor and waits for the thread to finish
    thr1.join();
    thr2.join();
    thr3.join();

    for (int i=0; i<8; i++)
    {
        std::cout<<str_[i];
    }
    std::cout<<std::endl;

}