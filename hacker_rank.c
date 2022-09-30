#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
int a =10,b=25,c=15;
int res =0;

while(b>0) {

        res += (a%c) + (c%a);
        b -= a%c;
        swap(&a,&c);
}

printf("%d",res);

}

output 45


train A goes 5km and reach in 7 hrs
train B goes 7km and rech in 5 hrs
if train A starts at 4pm and train B starts at 3pm when they reach

       3  4  5 6  6.30   7

tr a         7 14    17.5  21    

tr b      5  10 15   17.5   20



https://ttzztt.gitbooks.io/lc/content/longest-increasing-subsequence.html
3. Lowest Starting Stair A Monkey Is Jumping On A Long Staircase, On Which Each Stair Is Numbered; Th

1915. Number of Wonderful Substrings
int findLowestStartingStair(vector<int> jumps) {

A friend of Alex has gifted a movie collection, and Alex is excited to watch them all as quickly as possible. The duration of the movies is given in array durations[n], where n is the number of movies, and each movie duration lies between 1.01 and 3.00 units of time (up to two decimal places). Every day, Alex wants to spend no more than 3.00 units of time watching the movies but also wants to complete the movies in the least number of days possible. Alex does not leave a movie in between. That is, if Alex has picked up a movie, Alex watches the complete movie on the same day. Find the minimum number of days needed to watch all the movies.
A friend of Alex has gifted a movie collection, and Alex is excited to watch them all as quickly as possible.
The duration of the movies is given in array durations[n], where n is the number of movies,
and each movie duration lies between 1.01 and 3.00 units of time (up to two decimal places).
Every day, Alex wants to spend no more than 3.00 units of time watching the movies but also wants to complete the movies in the least number of days possible.
Alex does not leave a movie in between. That is, if Alex has picked up a movie, Alex watches the complete movie on the same day.
Find the minimum number of days needed to watch all the movies.

10:36 PM
HackerRank Question - Modify the String
www.hackerrank.com
10:30 PM
HackerRank Question - Inorder Tree Traversal
www.hackerrank.com
9:55 PM
HackerRank Question - Travel Time Chart Math
www.hackerrank.com
9:46 PM
HackerRank Question - Valid cleaning
www.hackerrank.com
9:46 PM
HackerRank Question - Time Complexity 2
www.hackerrank.com

findLowestStartingStair(vector<int> jumps)
