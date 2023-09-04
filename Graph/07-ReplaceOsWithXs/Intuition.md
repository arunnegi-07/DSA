## Intuition:

1. Actually problem is interesting and a variation of **Flood Fill Algorithm**. 

2. In first glance problem looks little hard to manage because it is saying "Set of O's surrounded by X's", but if 
   we think about it in another way then we found out that we just have to check only those O's which are at the boundries 
   and all the O's in contact with that 'O' (going till depth of it) will never be covered with X's because that boundary 'O' 
   will never be covered by 'X'.

3. So, our problem is broken down to just checking boundry O's and for every such O's we will go till depth of it in 4 directions
   using DFS traversal and keep on marking all the O's touched with them with some unique characters (let's say '$') and finally after
   making all the sufficient chnages we will just traverse our matrix and turn back all the '$' to 'O' (because they are not surrounded by 'X')
   and all the values with are still remain 'O' (means they are surrounded by 'X') we will make them 'X'.

So, problem is simple just dry run it yourself by taking few examples and this think will become clear to you.