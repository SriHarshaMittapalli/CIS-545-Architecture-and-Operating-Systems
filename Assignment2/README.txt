Project Description:
--------------------

1. Deadlock detection:
a) Enter file name like input_file.txt or input_file1.txt
b) The permutations function calculates orders based on number of processes
c) If there is a deadlock, it will print Deadlock! at the end of individual order.
d) If there is no deadlock, it will just print all the orderings

Compiling instruction and execution instruction :
-------------------------------------------------

srmittap@spirit:~/sriharsha_mittapalli_proj2$ python deadlock.py
Enter File Name : input_file.txt

srmittap@spirit:~/sriharsha_mittapalli_proj2$ python deadlock.py
Enter File Name : input_file1.txt

Test Cases :
------------

srmittap@spirit:~/sriharsha_mittapalli_proj2$ python deadlock.py
Enter File Name : input_file.txt
ORDER 1: A req R, A req S, A rel R, A rel S, C req T, C req R, C rel T, C rel R, B req S, B req T, B rel S, B rel T
ORDER 2: A req R, A req S, A rel R, A rel S, B req S, B req T, B rel S, B rel T, C req T, C req R, C rel T, C rel R
ORDER 3: C req T, C req R, C rel T, C rel R, A req R, A req S, A rel R, A rel S, B req S, B req T, B rel S, B rel T
ORDER 4: C req T, C req R, C rel T, C rel R, B req S, B req T, B rel S, B rel T, A req R, A req S, A rel R, A rel S
ORDER 5: B req S, B req T, B rel S, B rel T, A req R, A req S, A rel R, A rel S, C req T, C req R, C rel T, C rel R
ORDER 6: B req S, B req T, B rel S, B rel T, C req T, C req R, C rel T, C rel R, A req R, A req S, A rel R, A rel S

srmittap@spirit:~/sriharsha_mittapalli_proj2$ python deadlock.py
Enter File Name : input_file1.txt
ORDER 5036: F req W, F req S, F rel W, F rel S, G req V, G req U, G rel V, G rel U, D req U, D req S, D req T, D rel U, D rel S, D rel T, E req T, E req V, E rel T, E rel V, A req R, A req S, A rel R, A rel S, B req T, B rel T, C req S, C rel S
ORDER 5037: F req W, F req S, F rel W, F rel S, G req V, G req U, G rel V, G rel U, D req U, D req S, D req T, D rel U, D rel S, D rel T, E req T, E req V, E rel T, E rel V, C req S, C rel S, A req R, A req S, A rel R, A rel S, B req T, B rel T
ORDER 5038: F req W, F req S, F rel W, F rel S, G req V, G req U, G rel V, G rel U, D req U, D req S, D req T, D rel U, D rel S, D rel T, E req T, E req V, E rel T, E rel V, C req S, C rel S, B req T, B rel T, A req R, A req S, A rel R, A rel S
ORDER 5039: F req W, F req S, F rel W, F rel S, G req V, G req U, G rel V, G rel U, D req U, D req S, D req T, D rel U, D rel S, D rel T, E req T, E req V, E rel T, E rel V, B req T, B rel T, A req R, A req S, A rel R, A rel S, C req S, C rel S
ORDER 5040: F req W, F req S, F rel W, F rel S, G req V, G req U, G rel V, G rel U, D req U, D req S, D req T, D rel U, D rel S, D rel T, E req T, E req V, E rel T, E rel V, B req T, B rel T, C req S, C rel S, A req R, A req S, A rel R, A rel S

Existing bugs: 
--------------

As of now, there are no bugs exists.