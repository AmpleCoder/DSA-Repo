/*
Union and find Data structure 
consider n objects initially in their own set 
{1},{2},{3}......{n}

union(a,b) -> merge the set in which a is present with the one in which b is present 
find(a,b) -> tells if a and b are in the same set or not 

example:- N=6 , {1},{2},{3},{4},{5},{6}
assume dsu is our data structure which implements two methods 1)union(a,b) 2)find(a,b)
dsu.union(1,3) -> {1,3},{2},{4},{5},{6}
dsu.union(3,4) -> {1,3,4},{2},{5},{6}
dsu.find(3,6) -> 0(as they are not in the same set)
dsu.find(1,4) -> 1
dsu.union(2,5) -> {1,3,4},{2,5},{6}

now one idea is to implement it via adj matrix in which union is O(1) and find is O(n)
other idea is using boo 2D adj matrix here again union is O(n) and find is O(1)
one good valid solution is using a vector of vector which will store all the ele. belonging to that given set and also maintaining the
position in which the ele. are present in the set and here find will be of O(1) and union initially will be of O(n) but can be 
optimised furthur how? we can push the set having smaller size into the set having larger size(try to figure out the amortized tc of this operation)
(it'll be O(logn) try solving it)

now what we'll be doing is we'll maintain a tree for each component and from each tree there will be one leader which can represent the 
parent for that component and parent for each ele in that comp is equal to that element 
*/


