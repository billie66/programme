/* This code is from
 * http://en.wikipedia.org/wiki/Callback_%28computer_programming%29
 */

#include <stdio.h>
#include <stdlib.h>
 
/* The calling function takes a single callback as a parameter. */
void PrintTwoNumbers(int (*numberSource)(void)) {
    printf("%d and %d\n", numberSource(), numberSource());
}
 
/* One possible callback. */
int overNineThousand(void) {
    return (rand() % 1000) + 9000;
}
 
/* Another possible callback. */
int fortyTwo(void) {
    return 42;
}
 
/* Here we call PrintTwoNumbers() with three different callbacks. */
int main(void) {
    PrintTwoNumbers(rand);
    PrintTwoNumbers(overNineThousand);
    PrintTwoNumbers(fortyTwo);
}

