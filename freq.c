/* Getting the frequency of leading digits */

#include <stdio.h>

int getMSDigit(int x) {
   /* TODO: extract the leading digit of integer x and return it */
   int tempNum = x;
   int currDigit = 0;
   do {
      currDigit = tempNum % 10;
      tempNum /= 10;

   } while (tempNum > 0);
   return currDigit;
}

int main() {
   // auto fills the rest with 0s.

   // so the 0th index is for how many 0s, 1st for how many 1s, 2nd for how many 2s, etc.
   /* TODO: 
    * Read input from the stdin till EOF
    * For each integer, obtain the leading digit
    * Calculate the frequencies of the leading digits
    * Print the frequencies on stdout */
   // auto initializes all 13 spots to 0.
   int currIn= 0;
   int freqs[10] = {0,0,0,0,0,0,0,0,0,0};
   //input loop
   int MSD = 0;
   //printf("%d",getMSDigit(12));
   
   // scanf("%d", &x) == 1
   // fix this input method later
   while (scanf("%i", &currIn) == 1) {

         MSD = getMSDigit(currIn);
         //printf("%d\n", MSD);
         freqs[MSD] = freqs[MSD] + 1;

   }
         for (int n = 0; n < 9; n++) {
         printf("%d:%d ",n,freqs[n]);
      }
      printf("%d:%d ",9,freqs[9]);
   

   

   

    return 0;
}
