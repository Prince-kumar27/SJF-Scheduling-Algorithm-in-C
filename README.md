# SJF Scheduling Algorithm in C

## Description
> - This repository contains a C implementation of the Shortest Job First (SJF) scheduling algorithm, a non-preemptive CPU scheduling technique.</br>
> - The code simulates the SJF algorithm's process execution and calculates key metrics like average waiting time and turnaround time.</br>

## What is SJF ?

> - In Operating Systems, SJF stands for Shortest Job First, a CPU scheduling algorithm that aims to minimize the average waiting time of processes. Its core principle is simple: prioritize and execute the process with the shortest burst time (execution time) first.</br>

> Here's how it works:

> - step1: Process List: All processes waiting for execution are maintained in a queue.
> - step2: Shortest Selection: At each scheduling decision, the algorithm selects the process in the queue with the shortest remaining burst time.
> - step3: Execution: The chosen process is allocated the CPU and runs until completion.
> - Repeat: Steps 2 and 3 are repeated until all processes finish.
## Test-case for the algorithm
![Screenshot_1](https://github.com/Prince-kumar27/SJF_ALGO_IN_C/assets/111684530/c7479be3-a02d-4156-bee7-cd28415e26dd)

## Output:
![Screenshot_2](https://github.com/Prince-kumar27/SJF_ALGO_IN_C/assets/111684530/51244eb3-9a9e-4e59-9eb0-77e08244c10a)
