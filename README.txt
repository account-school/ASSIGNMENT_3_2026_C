6. Explain your answers (25 points)

Please answer the following questions for each file you wrote as part of this assignment.

1. Frequency of leading digits
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

So I basically divided this into two subtasks. The first one was to find the Most Significant Digit of any number.
I did this by adding a do-while loop that basically extracts the last digit of the number and stores it in a temporary location, to be overwritten each way.
The reason we don't just skip to the first digit (MSD), is because I don't know how to convert int to a string, and then set a char variable to str[0], and then convert that to an int.
So for the do while loop we first modulo by 10, store it in the thing to return, and then divide the original number by 10, if the new number is > 0, keep going, and replace the modulo 10 with the new last digit.
The idea is when it hits 0, we would have gotten there by dividing (0-->9) by 10. And then the modulo IS that last digit, to then exit the loop because 0 is not greater than 0, so return the modulo.
That is also why i did not declare the variables inside the do while loop, so that the modulo could still be  returned afterwards.


The next subtask is to get input and add each MSD to the frequency chart AS each number goes  through.

And the way to do this actually quite simple. Create an array with 10 0's in it. Representing the frequency of the MSD being
0,1,2,3,4,5,6,7,8,9
Per every input, find the MSD, and then for each MSD number, increment freq[MSD] by 1. The MSD that is correlated can easily be stored in the index, so there is no need to make a 2D array.


Then print it out using a for loop.


2. Checking if a string is a palindrome
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.


For this assingment, I had to add the library <string.h>, because I made heavy use of it.
My first primary step was to remove all of the non-alphanumeric characters, by simply making a new longer empty string and using isalnum() as a determiner as to whether to copy the next character in.
My second step was to do the palindrome detection. This works via a for loop that cycles from 0 --> less than (strlen + 1)/2.
Why < (strlen+1)/2? because if it is an even number, it gives (ex: (4+1)/2 = 5/2 = 2, ) and in an odd number, it still gives (3+1)/2 = 4/2 = 2), returning  <2 as the middle both times.

c**a**ts
m**e**t
ba**g**el


And then all I had to do was use tolower() on each char and then compare str[n] with str[strlen-n-1]

so on "cats"
this would be
0 --> < 2
c  s
a  t 

and then if any one of them didn't match we set the flag variable to 0 and exited the loop.
We assumed that it was until proven otherwise.

no match.


on 

"12321" it would be
0 --> < 3

1 1
2 2
3 3  (note here that strlen-2-1 == n == 2)

it matches!



3. We shall trim!
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

So what I did was really simple.
I set a variable to store the  position of the last 'whitespace' value.
 All I had to do was cycle backwards through the string and see if the next character was a space, \t, \n, \r, or ' '. If it was, set the variable to the current index. If not, we have our first non white space's location, and  thus we can exit the loop.
 All we have to do now is set the str[location +1] = '\0' (null terminator) and we have trimmed the string!


4. Multiplying matrices
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

For the input:

 I had to do some weird things. For each input, I had to declare a seperate variable j that counted how many inputs were typed in, (which was also the exit condition, since the)
user specified the dimensions of the matrice earlier). And so I determine the position of the inputted number by matrice [j/#cols][j%#cols] =  number_inputted; followed by a "j" incrementer. This applied for all matrices until (j = (width * height) -1)
Why -1 ? Because it evaluates the left hand side of the expression first, it will go through (width * height times), before realizing on the last time it needs to exit. To compensate for this, we add a manual insertion at the end, with the "J" and "M" still being usable since they were both declared outside the scope of the loop. 


For the matrix multiplcation itself:
I used https://www.youtube.com/watch?v=yRwQ7A6jVLk to help conceptually explain in non-code terms how to solve a matrice.
I used their first example of solving a [3x1] * [1x3] matrice by hand with math to figure out how to implememnt the logic from one row,
 and then just looped it for each major row in the first matrice.

I remember having to tweak the variable names and litteraly put my finger on the screen after having printed matrices a and b for me to understand which vairable went in which column and row.

5. Merge sort
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.



YAYYY IT WORKS! THE TEACHER HELPED ME IN OFFICE HOURSE AND TOLD ME THE KIND OF MINDSET AND CONCEPTUALLY HELPED ME A LOT.


So basically the difference between what I tried to do and what the teacher helped with was 

1) making sure that merging a subarray into a larger array worked without needing to return or copy the array
[pass by reference] (this is a separate function called insertInPlace)

2) separating the merge steps by copying the left-mid & mid+1 right  into two seperate left and right temp arrays before merging them into a new tempArray
to then use the above function

3) realizing that the length of the right array could be calculated by right-mid, if the length of the left one includes mid, (left one calculated by mid-left+1);
since

if we have [0 1 2 3];

right = 3
left = 0
mid = (left + right) / 2 = 1
len right and left = 2


3-1 = 2

and

1 - 0 + 1 = 2

thereby evenly splitting it

in an odd lengthed case:

[0 1 2 3 4]

right = 4
left = 0
mid = 2

4- 2 = 2 [3 4]
2 - 0 + 1 = 3 [0 1 2]

with a relatively even split.



