#include <stdio.h>

int main() {
    FILE *oddFile, *evenFile;
    int num, n;

    // Open odd.txt and even.txt in write mode
    oddFile = fopen("odd.txt", "w");
    evenFile = fopen("even.txt", "w");

    if (oddFile == NULL || evenFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        
        // Check if the number is even or odd, and write to respective file
        if (num % 2 == 0) {
            fprintf(evenFile, "%d\n", num);
        } else {
            fprintf(oddFile, "%d\n", num);
        }
    }

    // Close the files
    fclose(oddFile);
    fclose(evenFile);

    printf("Numbers have been successfully written to odd.txt and even.txt\n");
    
    return 0;
}
