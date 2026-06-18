# How To Think

## #1 Two sum

Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target.

- Create look up table
- determine hash size and make sure it's bigger to prevent collision
- from the size create a hashTable with look up struct to store all the values
- check if table is occupied
- if occupied then check is the value = target
- if not store in lookUp table
- lookFor = target - nums[i];
- if nums[i] = lookFor, nums[i] return index of nums[i] else if (nums[i]) != lookFor
then store nums[i] index and value in look up table

You may assume that each input would have exactly one solution, and you may not use
the same element twice.
  
- exactly one solution so returnSize will always be 2

You can return the answer in any order

### Example
  
  Input: nums = [2,7,11,15], target = 9
  output = [0,1]
  explanation: Because num[0] + num[1] = 9
  return [0,1];

### Constraints
  
- numsLength > 2
- nums[i] not too big and not too small
- target is similar to one above
- only one valid answer
  
**Follow-Up**: come up with algorithm that is less than O(n^2) time complexity

## #2 Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

- create dummy node as a starting point
- if (l1 + l2) > 9 then (l1 + l2) / 10 = carry
- carry will be added to the next additions
- use pointer to jump to next value by creating a new node and linking it back to the
first node
- first node-> second node-> next node-> next...

You may assume the two numbers do not contain any leading zero, except the number 0
itself.

### Example
  
  **7->0->8**
  Input: l1 = [2,4,3], l2 = [5,6,4]
  Output = [7,0,8]
  Explanation = 342 + 564 = 807

### Constraints
  
- Number of index in a linked list is in range of 1-100
- Node.val is in 1 place
- List does not have leading zeros

## #3 Longest Substring Without repeating Characters

  Given a string s, find the length of the longest without duplicate characters.

### Example

  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab"
  are also correct answers.

- create an array to store the value of a substring
- determine the starting point and end point of the substring
- string start at any char it founds and ends when is no longer the same char
- every new substring compare the new lenght of the new substring with the lenght
  of the previous substring to determine which one is larger

### Constraints

- s.length is never 0
- s can be English letters, digits, symbols and spaces

## #4 Longest Palindromic Substring

  Given a string s, return the longest in s.

- check what condition does it need to be a palindrome
  - the first condition is the middle can contain either 1 or 2 of the same char if
    the palindrome is even
  - then expand outwards from the middle and check if the left char is equal to the
    right
- we will need a helper function for that
  - the helper function should be given the char, the starting point and the end point
    of the character in the middle of the palindrome
- place all that in a loop and use i as the middle of palindrome
- then check the currentLenght by checking which one is larger, either the palindrome
  with i, i+1 or i
- if the current lenght is larger than the maxlenght then maxlength = currentlength
- now we need a starting point of the palindrome that we will display and for that we need
  - start = i - (maxlength - 1) / 2

### Example
  
  Input: s = "babad"
  Output: "bab"
  Explanation: "aba" is also a valid answer.

## #6 Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
like this: (you may want to display this pattern in a fixed font for better
legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

- if numRows == 1  || numRows >= strlen(s) then we just return *s
- since numsRows = 3 we will need to take the next value on that first row first.
  so i think i can do

     for (int i = 0; i < numRows; i++){
        for (int j = 0; j < length ; j += 2 * numRows - 2)
     }

- 2* numRows - 2 is the same when we tried with numRows == 3 and numRows == 4 so
  we will try that
- then resultIdx = -1 and do resultIdx++ on every single loop
- and then we will assign resultIdx = s[j + i]
- and then if is not on the first row anymore we need to jump small since well we can't
  simply increase j anymore because it will add more than one so we can do this
  if (i != 0 && i != numRows - 1); we will do int middleIdx = j + (2 * numRows - 2) - i
  and then we will assign result to that middleIdx position

Write the code that will take a string and make this conversion given a number of
rows:

string convert(string s, int numRows);

### Example 1
  
  Input: s = "PAYPALISHIRING", numRows = 3
  Output: "PAHNAPLSIIGYIR"

### Example 2

  Input: s = "PAYPALISHIRING", numRows = 4
  Output: "PINALSIGYAHRPI"
  Explanation:
  P     I    N
  A   L S  I G
  Y A   H R
  P     I

### Constraints
  
- s.length > 1
- s contain letters, both lower and upper and also ',' and '.'
- 1 <= numRows <= 1000

## #11 Container with most water

  You are given an integer array height of length n. There are n vertical lines drawn such that
  the two endpoints of the ith line are (i, 0) and (i, height[i]).

  Find two lines that together with the x-axis form a container, such that the container
  contains the most water.

  Return the maximum amount of water a container can store.

  **Notice** that you may not slant the container.

  - HeightSize is the len of Height
  - place 1 pointer on the start and 1 at the end
    - if 1 of them is smaller than the other then move to the center
      - if it move and it get smaller then go back to the previous place

### Example
  Input: height = [1,8,6,2,5,4,8,3,7]
  Output: 49
  Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
  case, the max area of water (blue section) the container can contain is 49.

## #12 Integer to Roman

  Seven different symbols represent Roman numerals with the following values:
  Symbol	Value
    I	      1
    V	      5
    X	      10
    L	      50
    C	      100
    D	      500
    M	      1000
  
  Roman numerals are formed by appending the conversions of decimal place values from highest to 
  lowest. Converting a decimal place value into a Roman numeral has the following rules:
  
    - If the value does not start with 4 or 9, select the symbol of the maximal value that can
      be subtracted from the input, append that symbol to the result, subtract its value, and
      convert the remainder to a Roman numeral.

    - If the value starts with 4 or 9 use the subtractive form representing one symbol 
      subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9
      is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9
      (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).

    - Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent
      multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need 
      to append a symbol 4 times use the subtractive form.
  
  Given an integer, convert it to a Roman numeral.  

  - basically just make an array with all the values and another array with all the char
    and then loop through it while substracting the value of the input

## #11 Roman to integer

  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

  Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

  For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written
  as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

  Roman numerals are usually written largest to smallest from left to right. However, the numeral
  for four is not IIII. Instead, the number four is written as IV. Because the one is before the 
  five we subtract it making four. The same principle applies to the number nine, which is written 
  as IX. There are six instances where subtraction is used:
   
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

  Given a roman numeral, convert it to an integer.

    - this one is incredibly easy just use a switch case to determine each char value and then
      - loop through everything by using the length of the string and then we just need to check
        if the current value is lower than the value after then we will substract current value
        from total else we add and then return the total

## #14. Longest Common Prefix

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

### Example 

  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.

  - this is also really easy all i need to do is store the value i as the value of the current
    char and store j as the value of the current string and then just loop use double loop like
    this
    
      for(int i = 0; char[i] != '\0'; i++){
      char currentchar = char[i];
        for (int j = 0; j < strSize; j++){
          if (strs[j][i] == '\0' || strs[j][i] != currentchar){
            char[i] = '\0';
            return char;
          }
        }
      }

  - what it does? well basically loops through every string with j and then loop through char 
    with i and store currentchar to be compared with the char in the same char index as the
    previous string

## #17. Lettter Combinations of a phone number

  Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
  that the number could represent. Return the answer in any order.

  A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 
  1 does not map to any letters.

### Constraints
  
    1 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

### Example 
  
  Input: digits = "23"
  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    - this one is very easy the returnSize will be *returnSize = malloc(strlen(digits) * pow(3);
    - since 1 and 0 is not going to be inside of digits then it would be easier since there is
      no need to check whether it's valid or not
    - bascially the code will be -> take the digits one by one and define what's their possible
      chars and then we take it and mix everything that doesn't already exist
    - Nevermind this is not easy this is bullshit
    - create helper functions to take the index of an array, store combinations and check whether
      the current combinations already exist and then
