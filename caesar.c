#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
#define KEY 3

void cipher(char *message , int encrypt)
{
    for (int i = 0; i < strlen(message); i++)
    {
        if (isalpha(message[i]))
        {
            int offset = isupper(message[i]) ? 'A' : 'a';
            message[i] = encrypt ? (message[i] - offset + KEY) % 26 + offset :(message[i] - offset - KEY + 26) % 26 + offset;
        }
    }
}
int main()
{
    char message[MAX_LEN];

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_LEN, stdin); 
    message[strcspn(message, "\n")] = '\0';
    printf("Original message: %s\n", message);

    cipher(message , 1); 
    printf("Encrypted message: %s\n", message);

    cipher(message , 0);
    printf("Decrypted message: %s\n",message);

    return 0;
} 
