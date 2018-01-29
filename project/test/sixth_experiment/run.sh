#!/bin/bash
space=" "
for((size=1;size<=50;size++))
do
	cmd1="stress-ng -m 1 --vm-bytes $size"
	cmd2="M --perf -t 5 2>log && cat log | grep \"Cache Misses\" | awk -F '(' '{print \$2}' | awk -F '%' '{print \"" 
	cmd3="\"\$1}' >> rate.data"
	cmd=${cmd1}${cmd2}${size}${space}${cmd3}
	for((i=0;i<20;i++))
	do
	eval $cmd
	done
done
