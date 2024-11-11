#include <stdio.h>
#include <unistd.h>  // Include this header to use the sleep function

int main() {
    printf("This is some text.\n");
    
    // Sleep for 2 seconds to simulate delay
    sleep(2);
    
    // Clear the terminal screen
    printf("\033[2J\033[H");

    printf("Screen cleared and this is new text.\n");
    
    return 0;
}
