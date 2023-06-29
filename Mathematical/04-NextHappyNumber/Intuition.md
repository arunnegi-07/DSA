## Intuition :

**Even though it is placed in the Hard category but it is moderate level of Problem.**

**Few Things to Note :**
1. The numbers that, when you repeatedly sum the squares of their digits, eventually result in 1 are known as **"happy numbers"**.
2. Now, for single digit numbers : **1** and **7** are the only numbers which will lead us back to **1** all other number except them
    will start repeating same cycle but never reach to **1** ( we will see analysis of it below ).
3. Which means we just have to take care numbers which are more than **1** digit, we just repeatedly keep on cheking them by doing
    sum of square of their digits and there sum become single digit we will simply check if it's either **1** or **7**, if it is then we
    will return ***true** that is the current number is a **happy number** or we will return **false**.

**Now let us analyze all single digit numbers :** 

**Number 1:**
```
1^2 = 1
Since we have already reached 1, the process stops here. 1 is a happy number.
```

**Number 2:**
```
2^2 = 4
4^2 = 16
1^2 + 6^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 2 is not a happy number.
```

**Number 3:**
```
3^2 = 9
9^2 = 81
8^2 + 1^2 = 65
6^2 + 5^2 = 61
6^2 + 1^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 3 is not a happy number.
```

**Number 4:**
```
4^2 = 16
1^2 + 6^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 4 is not a happy number.
```

**Number 5:**
```
5^2 = 25
2^2 + 5^2 = 29
2^2 + 9^2 = 85
8^2 + 5^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 5 is not a happy number.
```

**Number 6:**
```
6^2 = 36
3^2 + 6^2 = 45
4^2 + 5^2 = 41
4^2 + 1^2 = 17
1^2 + 7^2 = 50
5^2 + 0^2 = 25
2^2 + 5^2 = 29
2^2 + 9^2 = 85
8^2 + 5^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 6 is not a happy number.
```

**Number 7:**
```
7^2 = 49
4^2 + 9^2 = 97
9^2 + 7^2 = 130
1^2 + 3^2 + 0^2 = 10
1^2 + 0^2 = 1
Since we have reached 1, the process stops here. 7 is a happy number.
```

**Number 8:**
```
8^2 = 64
6^2 + 4^2 = 52
5^2 + 2^2 = 29
2^2 + 9^2 = 85
8^2 + 5^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 8 is not a happy number.
```

**Number 9:**
```
9^2 = 81
8^2 + 1^2 = 65
6^2 + 5^2 = 61
6^2 + 1^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
Since we have reached 4 again, the process will continue in an infinite loop. 9 is not a happy number.
```

From above analysis, it is clear that only single digit numbers whose sum of sqaure of their digit will lead to **1** are : 1 and 7.