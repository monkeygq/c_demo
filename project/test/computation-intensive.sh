perf record -a -o perf.data.1 &
perf record -a -o perf.data.2 &
perf record -a -o perf.data.3 &
perf record -a -o perf.data.4 &
perf record -a -o perf.data.5 &
perf record -a -o perf.data.6 &
perf record -a -o perf.data.7 &
perf record -a -o perf.data.8 &
perf record -a -o perf.data.9 &
perf record -a -o perf.data.10 &
perf record -a -o perf.data.11 &
perf record -a -o perf.data.12 &
perf record -a -o perf.data.13 &
sleep 10
ps aux | grep "perf record" | awk '{print $2}' | xargs kill -SIGINT &
