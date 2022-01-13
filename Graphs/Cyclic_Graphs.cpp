/*
problem : given a permutaion P , P^2 is defined as p^2[i]=p[p[i]]
eg: p=[3,4,2,1]
p^2=[p[3],p[4],p[2],p[1]]
p^2=[2,1,4,3]

so given a permutation q (i.e q=p^2) find the p or report that p doesn't exist

problem : https://codeforces.com/contest/612/problem/E
*/

/*
one coolest observation : in permutation problems if we form the graph between i and p[i] all
the components form cycle within them try taking any permutation of any size and see about the cycle

got the idea i'll code this one.
*/

/*
follow up : find the number of p possible for a given p^2
*/