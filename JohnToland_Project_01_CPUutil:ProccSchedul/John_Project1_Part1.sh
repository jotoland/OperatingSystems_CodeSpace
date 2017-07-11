#!/bin/bash

########## CS4352 Shell Experiences and Programming #### John G. Toland 3/14/17
# CPU utilization = 1- p^n
# log(1-CPU)/log(p) = n
# 1. Prompt users to enter the I/O fraction time (p) (in the range from 0 to 1)
# You should check if the input is valid or not. If not, ask users to re-enter.
# 2. Prompt users to enter the expected CPU utilization (in the range from 0 to 1)
# You should check if the input is valid or not. If not, ask users to re-enter.
# 3. Print out this minimum number of processes (integer) to achieve this goal.
#####################################################################################
# boundary variables
low=0.1
high=0.9
one=1
echo "[ello]: ...and Welcome to Minimum Number of Processes Calculator "
# prompt the user for p & CPU
echo -n "Enter the I/O fraction time between 0 - 1: "
read p
echo -n "Enter expected CPU utilization between 0 - 1: "
read CPU

#checking if input is correct
if (( $(echo "$p < $low" | bc -l) || $(echo "$CPU < $low" | bc -l) ||
$(echo "$p > $high" | bc -l) || $(echo "$CPU > $high" | bc -l) ))
	then
	if (( $(echo "$p < $low" | bc -l) && $(echo "$CPU < $low" | bc -l) ||
	$(echo "$p > $high" | bc -l) && $(echo "$CPU > $high" | bc -l) ))
		then
		echo "Invalid I/0 fraction time & CPU Utilization"
	elif (( $(echo "$p < $low" | bc -l) || $(echo "$p > $high" | bc -l) ))
		then
			echo "Invalid I/0 fraction time"
	elif (( $(echo "$CPU < $low" | bc -l) || $(echo "$CPU > $high" | bc -l) ))
		then
			echo "Invalid CPU utilization"
	fi
else
	echo "[ello]: Valid Input!"
	echo "[ello]: Calculating..."
	echo ""
	##this is where the math will go down!!!
	## need to compute log(1-CPU)/log(p) = n
	# 1 - CPU
	oneMinusCPU=`echo $one - $CPU | bc -l`
	echo "oneMinusCPU = $oneMinusCPU"
	# log(1-CPU)
	numer=`echo "l($oneMinusCPU)/l(10)" | bc -l`
	echo "numer = $numer"
	# log(p)
	denom=`echo "l($p)/l(10)" | bc -l`
	echo "denom = $denom"
	# log(1-CPU)/log(p)
	n=`echo $numer / $denom | bc -l`
	echo ""
	echo "Before Evaluation n = $n"
	echo ""
	
	if (( $(echo "$n > 1.0" | bc -l) ))
	then
	truncatedN=`echo ${n%.*}`
		if (( $(echo "$truncatedN < $n" | bc -l) ))
		then
			#echo "$n is not an integer !!"
			temp=`echo "($n+1.0)/1" | bc -l`
			roundedN=`echo ${temp%.*}`
		else
			#echo "$n is an integer !!"
			roundedN=`echo ${n%.*}`
		fi
	else
		roundedN=1
	fi
#################### Print out the results ############################
	echo "n = $roundedN"
	echo ""
	echo "[ello]: The minimum number of processes needed: n = $roundedN "
	echo ""
	echo "Minimum Processes: n = $roundedN "
	echo "I/O fraction time: p = $p "
	echo "CPU utilization: cpuUtil = $CPU "
	echo $USAGE
	exit 1
fi






