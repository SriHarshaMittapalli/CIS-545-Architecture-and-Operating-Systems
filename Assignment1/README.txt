Project Description:
--------------------

1. Calculate pi value using thread_atomic.c:
a) Take m and n as inputs where m is number of threads and n is number of terms in gregory-lebiniz series.
b) Initialize thread_start = 1 and thread_end = n (number of terms in gregory-lebiniz series)/ m (number of threads).
c) Declaring thread_details array with size m and storing all details of thread like thread_index, thread_start, thread_end.
d) Created threads based on m value and provided thread_id.
e) Add the gregory-lebiniz series across the range.
f) After the sum of above series, we print for each and every thread which is created.
g) We update the global totalGregoryLeibnizSeriesSum after getting the lock so that no other threads can access it.
h) We release the lock after the update is completed.
i) pthread_barrier_wait will wait the current thread till all other threads completed.
j) We multiply the global totalGregoryLeibnizSeriesSum by 4 times which gives the pi value.

2. Calculate pi value using thread_atomic.c:
a) Take m and n as inputs where m is number of threads and n is number of terms in gregory-lebiniz series.
b) Initialize thread_start = 1 and thread_end = n (number of terms in gregory-lebiniz series)/ m (number of threads).
c) Declaring args array with size m and storing all details of thread like thread_index, thread_start, thread_end.
d) Created threads based on m value and provided thread_id.
e) Add the gregory-lebiniz series across the range from start to end.
f) After the sum of above series, we store it in a array.
g) At the end, only last thread will print the output and all other threads are reduced.

Compiling instruction and execution instruction :
-------------------------------------------------

PS C:\Users\Harsha\Desktop\Multithreading> gcc thread_atomic.c -o thread_atomic
PS C:\Users\Harsha\Desktop\Multithreading> ./thread_atomic 16 1024

PS C:\Users\Harsha\Desktop\Multithreading> gcc thread_reduce.c -o thread_reduce
PS C:\Users\Harsha\Desktop\Multithreading> ./thread_reduce 16 1024

Test Cases :
------------

PS C:\Users\Harsha\Desktop\Multithreading> gcc thread_atomic.c -o thread_atomic
PS C:\Users\Harsha\Desktop\Multithreading> ./thread_atomic 16 1024
thread 0: 0.781492
thread 1: 0.001953
thread 2: 0.000651
thread 3: 0.000326
thread 4: 0.000195
thread 5: 0.000130
thread 6: 0.000093
thread 7: 0.000070
thread 8: 0.000054
thread 9: 0.000043
thread 10: 0.000036
thread 11: 0.000030
thread 12: 0.000025
thread 13: 0.000021
thread 14: 0.000019
thread 15: 0.000016
Pi value is: 3.140616

PS C:\Users\Harsha\Desktop\Multithreading> gcc thread_reduce.c -o thread_reduce
PS C:\Users\Harsha\Desktop\Multithreading> ./thread_reduce 16 1024
middle result 0: 3.125969 
 middle result 1: 0.007812 
 middle result 2: 0.002604 
 middle result 3: 0.001302 
 middle result 4: 0.000781 
 middle result 5: 0.000521 
 middle result 6: 0.000372 
 middle result 7: 0.000279 
 middle result 8: 3.126186 
 middle result 9: 0.007985 
 middle result 10: 0.002746 
 middle result 11: 0.001420 
 middle result 12: 3.127067 
 middle result 13: 0.008592 
 middle result 14: 3.130260 
 middle result 15: 3.140616 
 pi value: 3.140616
 
Existing bugs: 
--------------

As of now, there are no bugs exists.