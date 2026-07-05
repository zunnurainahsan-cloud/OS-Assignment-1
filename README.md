# Assignment 1 — CPU Scheduling Algorithms

Implementations of classic CPU scheduling algorithms in C++, covering First
Come First Serve, Shortest Job First, Priority Scheduling, Round Robin, and a
comparison of all three non-preemptive algorithms.

Files

FileDescriptionQ1_FCFS.cppFirst Come First Serve schedulingQ2_SJF.cppNon-Preemptive Shortest Job First schedulingQ3_Priority.cppNon-Preemptive Priority schedulingQ4_RoundRobin.cppRound Robin schedulingQ5_Comparison.cppCompares FCFS, SJF, and Priority on the same data set

Requirements


A C++ compiler supporting C++17 (e.g. g++)


How to Compile and Run

Each file is standalone. Compile and run like this:

bashg++ -std=c++17 -O2 -o Q1_FCFS Q1_FCFS.cpp
./Q1_FCFS

Repeat with the corresponding file name for Q2–Q5:

bashg++ -std=c++17 -O2 -o Q2_SJF Q2_SJF.cpp
./Q2_SJF

g++ -std=c++17 -O2 -o Q3_Priority Q3_Priority.cpp
./Q3_Priority

g++ -std=c++17 -O2 -o Q4_RoundRobin Q4_RoundRobin.cpp
./Q4_RoundRobin

g++ -std=c++17 -O2 -o Q5_Comparison Q5_Comparison.cpp
./Q5_Comparison

Program Details

Q1 — FCFS Scheduling


Input: arrival time and burst time for each process.
Logic: processes are sorted by arrival time and executed strictly in
that order; the CPU sits idle if the next process hasn't arrived yet.
Output: Completion Time, Turnaround Time, Waiting Time per process,
and the Average Waiting Time / Turnaround Time.


Sample input (4 processes):

0 5
1 3
2 8
3 6

Sample output: Average Waiting Time = 5.75

Q2 — Non-Preemptive SJF Scheduling


Input: Process ID and burst time for each process (all assumed to
arrive at time 0, as is standard for this variant).
Logic: at each step, picks the not-yet-run process with the smallest
burst time.
Output: execution order, per-process timings, and average waiting time.


Q3 — Priority Scheduling (Non-Preemptive)


Input: burst time and priority for each process (lower number =
higher priority).
Logic: at each step, picks the not-yet-run process with the lowest
priority number.
Output: execution order, per-process timings, and average waiting time.


Q4 — Round Robin Scheduling


Input: burst time for each process, plus a time quantum.
Logic: processes are held in a FIFO queue; each gets at most one
quantum of CPU time per turn, and is re-queued at the back if it still
has remaining burst time.
Output: completion/turnaround/waiting time per process and averages.


Q5 — Comparison of Scheduling Algorithms


Input: burst time and priority for each process (used across all
three algorithms so the comparison is apples-to-apples).
Logic: runs FCFS, SJF, and Priority scheduling on the identical
process set and reports the average waiting time for each.
Output: a side-by-side comparison and the best-performing algorithm.

Assumptions


Q2, Q3, Q4, and Q5 assume all processes arrive at time 0. This matches
the simplest/standard textbook treatment of SJF, Priority, and Round
Robin scheduling and keeps the input format aligned with what the
assignment specifies (no arrival time is requested for these questions).
Q1 is the only algorithm here that explicitly incorporates arrival time,
as specified in the assignment.
