#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

   
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

   
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char input[100]; 
   
    printf("Input: ");
    fgets(input, sizeof(input), stdin);

    
    int length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
       input[length - 1] = '\0';
    }

    
    int result = lengthOfLastWord(input);
    printf("Output: %d\n", result);

    return 0;
}
