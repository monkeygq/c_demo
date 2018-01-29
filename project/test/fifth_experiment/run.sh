#!/bin/bash
cmd="./memory-intensive >> perf_event.data"
recompile="gcc -o memory-intensive memory-intensive.c"
cache="echo 3 > /proc/sys/vm/drop_caches"
for((size=1;size<=20;size++))
do
	change="sed -i '27c #define MAX (1024 \* $size)' memory-intensive.c"
	eval $change
	eval $recompile 
	for((i=0;i<20;i++))
	do
	#sleep 10
	eval $cache
	eval $cmd
	done
done
