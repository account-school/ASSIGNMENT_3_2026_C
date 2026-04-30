#include <stdio.h>

void trim(char s[]) {
   /* TODO: remove all trailing spaces at the end of the string s. 
    * Any other spaces in-between the string must be preserved.
   */
}

int main() {
   char str[100];  // Assuming max input length of 100 characters
   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);  // Read input including spaces
   printf("Input string: [%s]\n", str);
   trim(str);  // Call the function to trim trailing spaces
   printf("Trimmed string: [%s]\n", str);

   return 0;
}
