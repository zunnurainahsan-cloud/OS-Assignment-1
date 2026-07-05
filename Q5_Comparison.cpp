// Q5. Comparison of FCFS, SJF, and Priority Scheduling
// Runs the same set of processes through all three algorithms and
// compares average waiting time to find the best-performing one.
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burst;
    int priority;
};

// All three algorithms below assume every process arrives at time 0,
// which is the standard simplification used for this kind of comparison.

double runFCFS(vector<Process> p) {
    // FCFS = original submission order
    int currentTime = 0;
    double totalWaiting = 0;
    for (auto &pr : p) {
        currentTime += pr.burst;
        int turnaround = currentTime;
        int waiting = turnaround - pr.burst;
        totalWaiting += waiting;
    }
    return totalWaiting / p.size();
}

double runSJF(vector<Process> p) {
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.burst < b.burst;
    });
    int currentTime = 0;
    double totalWaiting = 0;
    for (auto &pr : p) {
        currentTime += pr.burst;
        int turnaround = currentTime;
        int waiting = turnaround - pr.burst;
        totalWaiting += waiting;
    }
    return totalWaiting / p.size();
}

double runPriority(vector<Process> p) {
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.priority < b.priority; // lower number = higher priority
    });
    int currentTime = 0;
    double totalWaiting = 0;
    for (auto &pr : p) {
        currentTime += pr.burst;
        int turnaround = currentTime;
        int waiting = turnaround - pr.burst;
        totalWaiting += waiting;
    }
    return totalWaiting / p.size();
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time and priority of process P" << p[i].id << ": ";
        cin >> p[i].burst >> p[i].priority;
    }

    double avgFCFS = runFCFS(p);
    double avgSJF = runSJF(p);
    double avgPriority = runPriority(p);

    cout << fixed << setprecision(2);
    cout << "\n--- Comparison of Average Waiting Time ---\n";
    cout << "FCFS Average Waiting Time     : " << avgFCFS << "\n";
    cout << "SJF Average Waiting Time      : " << avgSJF << "\n";
    cout << "Priority Average Waiting Time : " << avgPriority << "\n";

    string best = "FCFS";
    double bestValue = avgFCFS;
    if (avgSJF < bestValue) { best = "SJF"; bestValue = avgSJF; }
    if (avgPriority < bestValue) { best = "Priority"; bestValue = avgPriority; }

    cout << "\nBest-performing algorithm for this data set: " << best
         << " (Average Waiting Time = " << bestValue << ")\n";

    // Note: SJF is provably optimal for minimizing average waiting time
    // when all processes are available at time 0, so it will always be
    // the best or tied-best result unless Priority happens to produce
    // the exact same ordering as SJF for this input.

    return 0;
}
