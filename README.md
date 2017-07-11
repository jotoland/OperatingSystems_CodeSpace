# OperatingSystems_CodeSpace
Repo for C programs and ShellScripting


Project 1:
  Part 1:
  This program prompts the user to enter the I/O fraction time (p) (in the range from 0 to 1)
  and checks if the input is valid or not. If not, asks the user to re-enter.
  Then the program prompts the user to enter the expected CPU utilization (in the range from 0 to 1)
  and checks if the input is valid or not. If not, asks the user to re-enter.
  Finally it prints out the minimum number of processes (integer) to achieve this goal.
  
  Part 2:
  This program prompts the user to enter the number of jobs (without checking for input error,
  it assumes that user inputs a valid integer from 0 to 10).
  Then the program prompts the user to enter the run time for each job (in seconds)
  Finally it prints out the order of jobs using Shortest Job First (SJF) scheduling.

Project 2:
This program implements process creation
(creating multiple children processes to work under one parent process) and termination
on a Linux platform. In theory, children processes can do their own work
separately or cooperatively to accomplish a task. In this program, these children
processes perform independent tasks: they simply print out a “my id: ” message together with
their PIDs (process IDs) and the Fibonacci result on modulo 20 of their PIDs and then exits.


Project 3:
This program implements a simplified version of the list
utility on Linux system. The list of files is printed out in tree format.
