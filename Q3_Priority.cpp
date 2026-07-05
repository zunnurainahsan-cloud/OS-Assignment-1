// Q3. Priority Scheduling (Non-Preemptive)
// Lower priority number = higher priority
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burst;
    int priority;
    int completion, turnaround, waiting;
    bool done = false;
};

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

    vector<int> executionOrder;
    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    for (int count = 0; count < n; count++) {
        int idx = -1, bestPriority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].priority < bestPriority) {
                bestPriority = p[i].priority;
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
    cout << "\n\nProcess\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (auto &pr : p) {
        cout << "P" << pr.id << "\t" << pr.burst << "\t" << pr.priority
             << "\t\t" << pr.completion << "\t\t" << pr.turnaround
             << "\t\t" << pr.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
