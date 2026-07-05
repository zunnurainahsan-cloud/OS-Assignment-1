// Q2. Non-Preemptive Shortest Job First (SJF) Scheduling
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burst;
    int completion, turnaround, waiting;
    bool done = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1; // Process ID (as required by the task)
        cout << "Enter burst time for process P" << p[i].id << ": ";
        cin >> p[i].burst;
    }

    // Non-preemptive SJF with all processes assumed available at time 0.
    // Simply pick the process with the smallest burst time each time.
    vector<int> executionOrder;
    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    for (int count = 0; count < n; count++) {
        int idx = -1, minBurst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        p[idx].done = true;
        currentTime += p[idx].burst;
        p[idx].completion = currentTime;
        p[idx].turnaround = p[idx].completion; // arrival assumed 0
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        executionOrder.push_back(p[idx].id);
        totalWaiting += p[idx].waiting;
        totalTurnaround += p[idx].turnaround;
    }

    cout << "\nExecution Order: ";
    for (int id : executionOrder) cout << "P" << id << " ";
    cout << "\n\nProcess\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (auto &pr : p) {
        cout << "P" << pr.id << "\t" << pr.burst << "\t" << pr.completion
             << "\t\t" << pr.turnaround << "\t\t" << pr.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
