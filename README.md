# simpleserver

usage:

    simpleserver <ip> <port> <doc_root>
    
for example:

    simpleserver 0.0.0.0 8080 .

test.html:

    <html>
    test
    </html>
    
test:

    ab -n 10000 -c 10000 http://localhost:8080/test.html
    
output:
```
vladon@ubuntu:~/projects/simpleserver$ ab -n 10000 -c 10000 http://localhost:8080/test.html
This is ApacheBench, Version 2.3 <$Revision: 1604373 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking localhost (be patient)
Completed 1000 requests
Completed 2000 requests
Completed 3000 requests
Completed 4000 requests
Completed 5000 requests
Completed 6000 requests
Completed 7000 requests
Completed 8000 requests
Completed 9000 requests
Completed 10000 requests
Finished 10000 requests


Server Software:        
Server Hostname:        localhost
Server Port:            8080

Document Path:          /test.html
Document Length:        42 bytes

Concurrency Level:      10000
Time taken for tests:   1.614 seconds
Complete requests:      10000
Failed requests:        0
Total transferred:      1060000 bytes
HTML transferred:       420000 bytes
Requests per second:    6196.21 [#/sec] (mean)
Time per request:       1613.890 [ms] (mean)
Time per request:       0.161 [ms] (mean, across all concurrent requests)
Transfer rate:          641.40 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:      217  366  82.9    368     516
Processing:   221  488 214.1    464     885
Waiting:      181  477 220.1    457     881
Total:        686  854 132.8    832    1104

Percentage of the requests served within a certain time (ms)
  50%    832
  66%    920
  75%    973
  80%    996
  90%   1052
  95%   1082
  98%   1098
  99%   1102
 100%   1104 (longest request)
```
