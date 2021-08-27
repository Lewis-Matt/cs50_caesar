/*
Caesar's cipher, ci = (pi + k) % 26, where i is subscript for ith position, % 26 is modulus (remainder when dividing by 26).
k = key, p = plaintext, c = ciphertext
User provides the key to use (non negative integer) as a command line arguement when executing the program.
Lower/uppercase letters are preserved
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> // atoi() converts string to int
#include <string.h> // strlen()
#include <ctype.h> // isdigit(), isupper(), islower()

int main(int argc, string argv[]) // structure for accepting command line arguments
{
    // checks if there is exactly 2 arguments (the program and the key)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // converts 2nd position string to int, checks if int is non-negative
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Key must be a number >= 0\n");
        return 1;
    }

    // accesses the string in the 2nd postion of the array, and checks if each ith char is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a number >= 0\n");
            return 1;
        }
    }
    printf("Your key is valid: %i\n", key);

    // get a string from user
    string pt = get_string("plaintext: ");
    printf("ciphertext: ");

    // check each char in the string
    for (int i = 0; i < strlen(pt); i++)
    {
        // checks for lowercase
        if (islower(pt[i]))
        {
            printf("%c", (((pt[i] + key) - 'a') % 26) + 'a');
        }

        // checks for uppercase
        else if (isupper(pt[i]))
        {
            printf("%c", (((pt[i] + key) - 'A') % 26) + 'A');
        }

        // if it is neither upper or lowercase char, it will just print that char (i.e. spaces, punctuation)
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");

}


/*
Line 24: convert 2nd argument to an int (this must be declared after argc has already been checked,
other wise it will pass 'segmentation fault' which means it is trying to access memoy location that doesn't exist yet).

Line 52, 58: it is looking at ASCII, ex: for a plaintext char 'C' and a key of 3. (67 + 3) = 70. Where is C with respect
to the beginning of the alphabet? Well, 'A' (65) is the begining of the UPPERCASE (97 for lower) alphabet, so we have to subtract
the 'A' from 'C' to get back to 0 (start).  67 - 65 = 2 from the start. Add our key (3) to see how much it has been shifted:
3 + 2 = shifted 5 (right) from the start. (or do this step as 67 + 3 - 65). To keep it within the alphabetical boundaries
of 26 characters; we modulo the 5 by 26. Just incase it goes over 26 we want to know how much extra is left over.
If there is any left over then that would be how many characters in from 0 again.
Because it has been shifted 5 times from the beginning, we have to start from 'A', so we add the 65 at the end.

IOW; modulo handles wrap-around characters (when we hit the end of the alphabet, we start back over at 0)
*/
