perf record -a -o perf.data.1 &
perf record -a -o perf.data.2 &
sleep 10
ps aux | grep "perf record" | awk '{print $2}' | xargs kill -SIGINT &
