#include<iostream>
#include<thread>
#include<mutex>
#include <condition_variable>

using namespace std;

mutex m1;
condition_variable cv;
bool flag=false;

void ping(){
    static int i=0;
    while(i++<10){
        m1.lock();
        cout<<"Ping"<<endl;
        flag = true;
        cv.notify_one();
        m1.unlock();
    }
}

bool is_flag(){
    return flag;
}

void pong(){
    static int i=0;
    while(i++<10){
        unique_lock<mutex> mlock(m1);
        //It internally acquires the mutex and check if required condition is met or not.
        //If not , It atomically releases the attached mutex, 
        //blocks the current thread, and adds it to the list of threads waiting on the current condition variable object.
        // The thread will be unblocked when some thread calls notify_one() or notify_all() on same condition variable object.
        // Condition Variable’s wait() function provides both these operations in atomic manner.
        cv.wait(mlock, is_flag);
        //while(flag!=true)
          //  cv.wait(mlock);
        // Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes.
        // It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met 
        cout<<"Pong"<<endl;
        flag = false;
        //mlock.unlock();
        

    }
}

int main(){
    
    thread t1(ping);
    thread t2(pong);

    t1.join();
    t2.join();


    return 0;
}