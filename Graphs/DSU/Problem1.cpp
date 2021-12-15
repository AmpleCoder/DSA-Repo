/*
initially we have n persons
each of them are friend with each other 
after each day given pair {i,j} breaks there friendship
and (a,b) forms the part of same club if there exist some sequence a,i1,i2,....ix,b such that 
(a,i1) (i1,i2)....(ix,b) are friends 

after each day we need to print the number of clubs left
assuming offline query
*/

/*
pretty simple approach 
we can first form components with all the pairs which are not present in the query set after that we can iterate from the back and 
do union of that pair and figure out the number of components we have  
*/

