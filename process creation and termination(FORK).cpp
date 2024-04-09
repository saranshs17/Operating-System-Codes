#include <stdio.h> 
#include<bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        cout<<"Child process: My PID is "<<getpid()<<"\n";
        cout<<"Child process: My parent's PID is "<<getppid()<<"\n";
        cout<<"Child process: Terminating...\n";
        cout<<"Parent process: Terminating...\n";
    }
    else {
        cout<<"Parent process: My PID is "<< getpid()<<"\n";
        cout<<"Parent process: My child's PID is "<<pid<<"\n";
    }
    return 0;
}
