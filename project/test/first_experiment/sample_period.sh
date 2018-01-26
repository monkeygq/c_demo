#!/bin/bash
period=50000
for((i=200;i>=60;i--)) 
do
sample_period=$[$i*$period]
echo "sample_period=$sample_period" >> computation-intensive.data
cmd="perf record -e cycles -c $sample_period ./computation-intensive 2>> computation-intensive.data"
	for((j=0;j<1;j++))
	do
	eval $cmd
	done

done
