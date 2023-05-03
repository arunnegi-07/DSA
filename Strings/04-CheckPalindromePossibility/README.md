# Problem : Check Palindrome Possibility (Easy)
You are given an array of strings arr of size ```n```. You have to find out if it is possible to make a palindromic string by concatenating the strings in any order.<br>
Provided that all the strings given in the array are of equal length.

**Example 1:**
```
Input:
n = 4
arr = {"djfh", "gadt", "hfjd", "tdag"}

Output:
YES

Explanation:
You can make the string "djfhgadttdaghfjd", by concatenating the given strings which is a palindrome.
```

**Example 2:**
```
Input:
n = 3
arr = {"jhjdf", "sftas", "fgsdf"}

Output:
NO

Explanation:
You can't make a palindromic string with this strings.
```

**Your Task:**
```
You don't need to read input or print anything. Your task is to complete the function makePalindrome() which takes an integer n and an array of strings arr respectively and returns true or false.
```

**Expected Time Complexity:** ```O(n * len(arr[i]))```
**Expected Space Complexity:** ```O(n * len(arr[i]))```

**Constraints:**
<li><code>1 <= n <= 10<sup>4</sup></code></li>
<li><code>0 <= |arr[i]| <= 10<sup>4</sup></code></li>
<li>The sum of <b>n*|arr[i]|<b> over all test cases won't exceed 10<sup>6</sup></li>


