for((i=0;i<50;i++))
do
(time ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "1 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 3000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "3000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 4000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "4000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 5000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "5000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 6000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "6000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 7000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "7000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 8000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "8000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 9000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "9000000 "$1}' >> time.data
done

for((i=0;i<50;i++))
do
(time perf record \-e cycles \-c 10000000 ./computation-intensive) 2>log;cat log | grep real | awk -F 'm' '{print $2}' | awk -F 's' '{print "10000000 "$1}' >> time.data
done
