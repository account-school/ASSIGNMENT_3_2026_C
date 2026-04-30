#include <stdio.h>
#include<string.h>


void trim(char s[]) {
   /* TODO: remove all trailing spaces at the end of the string s. 
    * Any other spaces in-between the string must be preserved.
   */
  // go backwards until you hit an alpha numeric character.
  int lastCharNum = 0;
  char space = ' ';
  for (int n = strlen(s)-1; n >= 0; n--) {
   //printf("%c %c",s[n],space);
   if (s[n] == space || s[n] == '\n' || s[n] == '\t' || s[n] == '\r') {
      lastCharNum = n;
   } else {
      lastCharNum = n;
      break;
   }
  }
  //printf("%d", lastCharNum);
  // copy the left most characters only

  s[lastCharNum + 1] = '\0';
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
