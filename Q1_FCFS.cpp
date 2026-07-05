// Q1. First Come First Serve (FCFS) Scheduling
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrival, burst;
    int completion, turnaround, waiting;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter arrival time and burst time of process " << p[i].id << ": ";
        cin >> p[i].arrival >> p[i].burst;
    }

    // FCFS => sort by arrival time (ties broken by input order)
    stable_sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival;          // CPU idle until process arrives
        currentTime += p[i].burst;
        p[i].completion = currentTime;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
    }

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (auto &pr : p) {
        cout << "P" << pr.id << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t\t" << pr.turnaround << "\t\t" << pr.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
