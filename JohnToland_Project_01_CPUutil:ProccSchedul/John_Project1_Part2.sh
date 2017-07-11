#!/bin/bash
########## CS4352 Shell Experiences and Programming #### John G. Toland 3/14/17
# Process scheduling.
# 
# 1. Prompt users to enter the number of jobs (no checking, assume that users input a
# valid integer from 0 to 10).
# 2. Prompt users to enter the run time for each job (in seconds)
# 3. Print out the order of jobs using Shortest Job First (SJF) scheduling..
####################################################################################

echo "[ello]: ...and Welcome to SJF Process Scheduler "
# prompt the user for p & CPU
echo -n "Enter number of jobs from 0 - 10: "
read numOfJobs

for((i=0;i<$numOfJobs;i++))
do
	echo -n "Enter Runtime for job: $i "
	read temp
	runTime4Jobs[$i]=$temp
done

echo ""
echo "The number of jobs = "${#runTime4Jobs[@]}
echo "The runtimes of the jobs are = "${runTime4Jobs[@]}
echo "[ello]: Calculating..."
echo ""

runTime4Jobs=($(for i in ${runTime4Jobs[@]} ; do echo $i; done | sort -n))

echo "[ello]: The SJF Schedule "${runTime4Jobs[@]}


