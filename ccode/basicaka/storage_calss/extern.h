#include <stdio.h>

int dd;
int add();

/* With the static keyword, the fun function can not 
 * be called by other files, except the source file 
 * defining the function.
 */
static void fun(); 

