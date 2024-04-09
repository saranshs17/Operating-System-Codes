#include <bits/stdc++.h>
using namespace std;
class Process {
 public:
  int pid, at, bt, ct, tat, wt;
  int ind;
  int burst_rem;
};
bool sortByArrival(Process p1, Process p2) { return p1.at < p2.at; }
bool sortById(Process p1, Process p2) { return p1.pid < p2.pid; }
int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;
  Process proc[n];
  cout << "Enter arrival time of the processes : " << endl;
  queue<Process> q;
  for (int i = 0; i < n; i++) {
    cin >> proc[i].at;
    proc[i].pid = i + 1;
  }
  cout << "Enter burst time of the processes : " << endl;
  for (int i = 0; i < n; i++) {
    cin >> proc[i].bt;
    proc[i].burst_rem = proc[i].bt;
  }
  int quant;
  cout << "Enter quantum:";
  cin >> quant;
  sort(proc, proc + n, sortByArrival);
  for (int i = 0; i < n; i++) proc[i].ind = i;
  int currTime = 0, complete = 0, currInd = 0;

  while (complete < n) {
    if (q.empty()) {
      q.push(proc[currInd]);
      currTime = proc[currInd].at;
      currInd++;
    }
    Process p = q.front();
    q.pop();
    if (p.burst_rem <= quant) {
      currTime += p.burst_rem;
      p.burst_rem = 0;
      int idx = p.ind;
      proc[idx].ct = currTime;
      proc[idx].tat = proc[idx].ct - proc[idx].at;
      proc[idx].wt = proc[idx].tat - proc[idx].bt;
      complete++;
    } else {
      p.burst_rem -= quant;
      currTime += quant;
    }
    while (currInd < n && proc[currInd].at <= currTime) {
      q.push(proc[currInd]);
      currInd++;
    }
    if (p.burst_rem > 0) q.push(p);
  }
  sort(proc, proc + n, sortById);
  cout << endl
       << "Process\t"
       << "AT\t"
       << "BT\t"
       << "CT\t"
       << "TAT\t"
       << "WT\n";
  for (int i = 0; i < n; i++) {
    cout << proc[i].pid << "\t" << proc[i].at << "\t";
    cout << proc[i].bt << "\t" << proc[i].ct << "\t";
    cout << proc[i].tat << "\t" << proc[i].wt << "\n";
  }
}
