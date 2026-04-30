#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[101];
    printf("Enter a string (max 100 characters): ");

    /* TODO: read an input string until the new-line character is read. 
             remove the new line character and check if the string is a palindrome.
             your check should ignore all non alpha-numeric characters and case-sensitivity.
             print if the string is a palindrome or not.
             your print statements should match the sample output prints shown in the pdf. */
             
    scanf("%[^\n]",&str);

    char newStr[101];
    int count = 0;
    for (int n = 0; n < strlen(str); n++) {
        if (isalnum(str[n])) {
            newStr[count] = str[n];
            count++;
        }
    }
    int isPalindrome = 1;
    for (int n = 0; n < (strlen(newStr) + 1)/2; n++) {
        //printf("%c %c\n",tolower(newStr[n]),tolower(newStr[strlen(newStr)-n-1]));
        if (tolower(newStr[n]) != tolower(newStr[strlen(newStr)-n-1]))  {
            isPalindrome = 0;
            break;
        }

    }
    printf("The string is ");
    if (isPalindrome == 0) {
        printf("not ");
    }
    printf("a palindrome.");
    return 0;
}
