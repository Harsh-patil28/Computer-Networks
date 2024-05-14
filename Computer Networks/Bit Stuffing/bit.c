#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
// Function to perform bit stuffing
void bitStuffing(char* data, int* size) {
int count = 0;
int newSize = *size;

for (int i = 0; i < *size; i++) {
if (data[i] == '1') {
count++;
} else {
count = 0;
}

if (count == 5) {
// Shift all elements to the right by one
for (int j = newSize; j > i + 1; j--) {
data[j] = data[j - 1];
}

// Insert '0' after the fifth consecutive '1'
data[i + 1] = '0';
newSize++;
count = 0;

}
}

*size = newSize;
}

int main() {
char data[MAX_SIZE];
int size;

// Input data
printf("Enter the data (consisting of 0's and 1's): ");
scanf("%s", data);

// Calculate the size of the data
for (size = 0; data[size] != '\0'; size++);

// Perform bit stuffing
bitStuffing(data, &size);

// Display stuffed data
printf("Stuffed data: %s\n", data);

return 0;
}
