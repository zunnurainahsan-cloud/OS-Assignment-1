// Q4. Round Robin Scheduling
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burst;
    int remaining;
    int completion, turnaround, waiting;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time of process P" << p[i].id << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    queue<int> q; // holds indices of processes
    for (int i = 0; i < n; i++) q.push(i);

    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        int execTime = min(quantum, p[i].remaining);
        currentTime += execTime;
        p[i].remaining -= execTime;

        if (p[i].remaining > 0) {
            q.push(i); // still needs more CPU time, goes to back of queue
        } else {
            p[i].completion = currentTime;
            p[i].turnaround = p[i].completion; // arrival assumed 0
            p[i].waiting = p[i].turnaround - p[i].burst;
        }
    }

    for (auto &pr : p) {
        totalWaiting += pr.waiting;
        totalTurnaround += pr.turnaround;
    }

    cout << "\nProcess\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (auto &pr : p) {
        cout << "P" << pr.id << "\t" << pr.burst << "\t" << pr.completion
             << "\t\t" << pr.turnaround << "\t\t" << pr.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
