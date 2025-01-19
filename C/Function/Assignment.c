#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random password of length N
void generatePassword(int length) {
    // Character sets for different types
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*";
    
    // All characters combined for random selection
    const char allChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

    int uppercaseSize = sizeof(uppercase) - 1;
    int lowercaseSize = sizeof(lowercase) - 1;
    int digitsSize = sizeof(digits) - 1;
    int specialSize = sizeof(special) - 1;
    int allCharsSize = sizeof(allChars) - 1;

    // Initialize the random number generator
    srand(time(NULL));

    // Ensure password has at least one of each required character type
    char password[length + 1]; // +1 for the null terminator
    password[0] = uppercase[rand() % uppercaseSize];
    password[1] = lowercase[rand() % lowercaseSize];
    password[2] = digits[rand() % digitsSize];
    password[3] = special[rand() % specialSize];

    // Fill the rest of the password with random characters from allChars
    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % allCharsSize];
    }

    // Shuffle the password to randomize the order
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % length;
        char temp = password[i];
        password[i] = password[randomIndex];
        password[randomIndex] = temp;
    }

    // Null-terminate the password
    password[length] = '\0';

    // Display the generated password
    printf("Generated Password: %s\n", password);
}

int main() {
    int length;

    // Get the desired password length from the user
    printf("Enter the desired password length (minimum 6): ");
    scanf("%d", &length);

    // Ensure the password length is at least 6
    if (length < 6) {
        printf("Error: Password length must be at least 6.\n");
        return 1;
    }

    // Generate and display the password
    generatePassword(length);

    return 0;
}
