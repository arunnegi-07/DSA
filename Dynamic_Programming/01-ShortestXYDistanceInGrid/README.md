# Problem : Shortest XY distance in Grid

Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan distance between a X and a Y.

**Manhattan Distance :**
| row_index_x - row_index_y | + | column_index_x - column_index_y |

```
Example 1:

Input:
N = 4, M = 4
grid  = {{X, O, O, O}
         {O, Y, O, Y}
         {X, X, O, O}
         {O, Y, O, O}}  

Output:
1

Explanation:
{{X, O, O, O}
{O, Y, O, Y}
{X, X, O, O}
{O, Y, O, O}}
The shortest X-Y distance in the grid is 1.
One possible such X and Y are marked in bold
in the above grid.
```

```
Example 2:

Input:
N = 3, M = 3
grid = {{X, X, O}
        {O, O, Y}
        {Y, O, O}}

Output:
2

Explanation:
{{X, X, O}
 {O, O, Y}
 {Y, O, O}}
The shortest X-Y distance in the grid is 2.
One possible such X and Y are marked in bold
in the above grid.
```
```
Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
```
```
Constraints:
1 ≤ N*M ≤ 10^5

There exists at least one 'X' and at least one 'Y' in the grid.
```