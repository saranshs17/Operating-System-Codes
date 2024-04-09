#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;
mutex mtx;
condition_variable cv;
queue<int> q;

void T1(int n) {
    for (int i = 1; i <= n; ++i) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, []{ return q.size() < 5; });
        q.push(i);
        cout << "T1 added data id: " << i << ". Current size: " << q.size() <<endl;
        cv.notify_one();
    }
}

void T2(int n) {
    for (int i = 1; i <= n; ++i) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, []{ return !q.empty(); });
        int data_id = q.front();
        q.pop();
        cout << "T2 deleted data id: " << data_id << ". Current size: " << q.size() <<endl;
        cv.notify_one();
    }
}

int main() {
    int n;
    cin >> n;
    thread t1(T1, n);
    thread t2(T2, n);
    t1.join();
    t2.join();
    return 0;
}
