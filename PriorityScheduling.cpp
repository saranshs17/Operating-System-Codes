#include <bits/stdc++.h>
using namespace std;
class Process {
 public:
  int pid, at, bt, pr, ct, tat, wt;
  int ind;
  int burst_rem;
};
struct Compare {
  bool operator()(Process p1, Process p2) {
    return (p1.pr < p2.pr) || (p1.pr == p2.pr && p1.at > p2.at);
  }
};
bool sortByArrival(Process p1, Process p2) { return p1.at < p2.at; }
bool sortById(Process p1, Process p2) { return p1.pid < p2.pid; }
int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;
  Process proc[n];
  cout << "Enter arrival time of the processes : " << endl;
  priority_queue<Process, vector<Process>, Compare> pq;
  for (int i = 0; i < n; i++) {
    cin >> proc[i].at;
    proc[i].pid = i + 1;
  }
  cout << "Enter burst time of the processes : " << endl;
  for (int i = 0; i < n; ++i) {
    cin >> proc[i].bt;
    proc[i].burst_rem = proc[i].bt;
  }
  cout << "Enter priority of ther processes: \n";
  for (int i = 0; i < n; ++i) {
    cin >> proc[i].pr;
    proc[i].pr=n-proc[i].pr;
  }
  sort(proc, proc + n, sortByArrival);
  for (int i = 0; i < n; i++) proc[i].ind = i;
  int currTime = proc[0].at, complete = 0, currInd = 1;
  pq.push(proc[0]);
  while (complete < n) {
    while (currInd < n && proc[currInd].at <= currTime) {
      pq.push(proc[currInd]);
      currInd++;
    }
    Process p = pq.top();
    pq.pop();
    p.burst_rem--;
    currTime++;
    if (p.burst_rem == 0) {
      int idx = p.ind;
      proc[idx].ct = currTime;
      proc[idx].tat = proc[idx].ct - proc[idx].at;
      proc[idx].wt = proc[idx].tat - proc[idx].bt;
      complete++;
    } else {
      pq.push(p);
    }
  }
  sort(proc, proc + n, sortById);
  float wait_avg = 0, turnaround_avg = 0;
  for (int i = 0; i < n; i++) {
    wait_avg += proc[i].wt;
    turnaround_avg += proc[i].tat;
  }
  wait_avg /= n;
  turnaround_avg /= n;
  cout << endl
       << "P\t"
       << "AT\t"
       << "BT\t"
       << "PRI\t"
       << "CT\t"
       << "TAT\tWT\n";
  for (int i = 0; i < n; i++) {
    cout << proc[i].pid << "\t" << proc[i].at << "\t";
    cout << proc[i].bt << "\t" << n-proc[i].pr << "\t";
    cout << proc[i].ct << "\t" << proc[i].tat << "\t";
    cout << proc[i].wt << "\n";
  }
  cout << "Average waiting time:" << wait_avg << "\n";
  cout << "Average turnaround time:" << turnaround_avg << "\n";
}
