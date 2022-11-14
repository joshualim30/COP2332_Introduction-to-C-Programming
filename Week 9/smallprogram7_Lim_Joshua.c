// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 7

// TO DO: remove newline character from inputs

char *deblank(char* str); // function to remove all spaces from a string
void pluralize(char* str); // takes noun and makes it plural
void fact(char* str); // takes a string and tells user how many letters, digits and punctuation characters are in the string
char *substring(char* str, char* sub); // takes a string and a substring and tells user if the substring is in the string at all

#include <stdio.h>
#include <string.h>

int main(void) {

    // Problem 1
    char str[20];
    printf("Enter a string: ");
    fgets(str, 20, stdin);
    deblank(str);
    printf("Output String with no blanks: %s", str);

    // Problem 2
    char noun[20];
    printf("Enter string to be pluralize: ");
    scanf("%s", noun);
    pluralize(noun);

    // Problem 3
    char factStr[20];
    printf("Enter a string with no spaces: ");
    scanf("%s", factStr);
    fact(factStr);

    // Problem 4 - almost done
    char fullStr[20];
    char subStr[20];
    printf("Enter the string: ");
    scanf("%s", fullStr);
    printf("Enter the substring you would like to look for: ");
    scanf("%s", subStr);
    if (substring(fullStr, subStr) == NULL) {
        printf("Substring %s doesn't exist!\n", subStr);
    } else {
        printf("Substring %s exists!\n", subStr);
    }

	return 0;
	
}

char *deblank(char* str) { // function to remove all spaces from a string

    int i = 0; // declare an integer variable named i, initialize to 0
    int j = 0; // declare an integer variable named j, initialize to 0

    while (str[i] != '\0') { // while the character at index i is not the null character
        if (str[i] != ' ') { // if the character at index i is not a space
            str[j] = str[i]; // set the character at index j to the character at index i
            j++; // increment j
        }
        i++; // increment i
    }
    str[j] = '\0'; // set the character at index j to the null character
    return str; // return the string

}

void pluralize(char* str) { // takes noun and makes it plural

    // check if string ends in y, s/ch/sh, or others
    // get end of string
    int len = strlen(str);
    char last2 = str[len - 2]; // get the second to last character in the string
    char last = str[len - 1]; // get the last character in the string

    // if the last character is y and the second to last character is not a vowel
    if (last == 'y' && last2 != 'a' && last2 != 'e' && last2 != 'i' && last2 != 'o' && last2 != 'u') {
        str[len - 1] = 'i'; // change the last character to i
        str[len] = 'e'; // add an e to the end of the string
        str[len + 1] = 's'; // add an s to the end of the string
        str[len + 2] = '\0'; // add a null character to the end of the string
    } else if (last == 's' || last == 'h' || last == 'x') { // if the last character is s, h, or x
        str[len] = 'e'; // add an e to the end of the string
        str[len + 1] = 's'; // add an s to the end of the string
        str[len + 2] = '\0'; // add a null character to the end of the string
    } else { // if the last character is not y, s, h, or x
        str[len] = 's'; // add an s to the end of the string
        str[len + 1] = '\0'; // add a null character to the end of the string
    }

    printf("Word pluralize: %s\n", str);

}

void fact(char* str) { // takes a string and tells user how many letters, digits and punctuation characters are in the string

    char newStr[20]; // declare a new variable newStr that has removed the newline character from the string
    // remove the newline character from the string
    int i = 0; // declare an integer variable named i, initialize to 0
    int j = 0; // declare an integer variable named j, initialize to 0
    while (str[i] != '\0') { // while the character at index i is not the null character
        if (str[i] != ' ') { // if the character at index i is not a space
            newStr[j] = str[i]; // set the character at index j to the character at index i
            j++; // increment j
        }
        i++; // increment i
    }
    newStr[j] = '\0'; // set the character at index j to the null character

    // count the number of letters, digits, and punctuation characters
    int len = strlen(newStr); // get the length of the string
    int letters = 0; // declare an integer variable named letters, initialize to 0
    int digits = 0; // declare an integer variable named digits, initialize to 0
    int punct = 0; // declare an integer variable named punct, initialize to 0

    for (int i = 0; i < len; i++) { // for each character in the string
        if (newStr[i] >= 'a' && newStr[i] <= 'z' || newStr[i] >= 'A' && newStr[i] <= 'Z') { // if the character is a letter
            letters++; // increment letters
        } else if (newStr[i] >= '0' && newStr[i] <= '9') { // if the character is a digit
            digits++; // increment digits
        } else { // if the character is not a letter or digit
            punct++; // increment punct
        }
    } // end for

    printf("%s has \n", newStr);
    printf("%d letters\n", letters);
    printf("%d digits\n", digits);
    printf("%d punctuation characters\n", punct);

}

char * substring(char* str, char* sub) { // takes a string and a substring and tells user if the substring is in the string at all

    // inititalize variables
    int subSize = strlen(sub); // get the length of the substring
    int stringSize = strlen(str); // get the length of the string
    int lastIndex = stringSize - subSize + 1; // get the last index of the string that the substring could start at

    // loop through the string
    for(int i = 0; i < lastIndex; i++) {

        // loop through the substring if the first character of the substring matches the i character of the string
        if (str[i] == sub[0]) {

            // loop through the substring
            int e = 0;
            while (e < subSize && str[i + e] == sub[e]) {
                e++; // increment e if the characters match
            }
            if (e == subSize) {
                return sub; // return the substring if subSize is equal to e (all characters match)
            }

        }

    }

    return NULL; // return NULL if the substring is not in the string

}