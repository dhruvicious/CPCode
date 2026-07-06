## Problem Statement
if we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000;

## Thought Process
Sooo, here's what i am thinking i can go through each number between 1 and 1000 one at a time and check if it's a multiple of 3 or 5 and add it to the running sum if it is but that's linear time complexity 
and since this is ProjectEuler i have to clever about it, thus i am thinking a purely mathematical solution maybe an geometric progression
so here's my process i go and sum all the multiples of 3 from 1 to 1000 them i go sum all the multiples of 5 between 1 to 1000 and then since we added the multiples of 3 and 5 twice in the process i substract the sum of multiples of 15 between 1 to 1000