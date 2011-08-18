#include <stdio.h>

int main(int argc, const char *argv[])
{
/*
 * segmentation fault( a pieces of memory which only be read,
 * but you write to it).
 */

/* 
 * Bug #1 - uninitialized pointer. The pointer p is 
 * uninitialized, and points to a random location 
 * in the memory when you declare it.
 */

/* 
    int *p;
    *p = 12;
    printf("output %d\n", *p);
 */

/* 
 * Bug #2 - invalid pointer reference. The pointer q is 
 * uninitialized, so after you assign q to p, 
 * the pointer p points to a random location, the same as Bug #1.
 */

/*
    int *p, *q;
    p = q;
    *p = 12;
    printf("output %d\n", *p);
 */

/* 
 * Bug #3 - zero pointer reference. There is no block pointed to by p.
 * Therefore, reading or writing anything from or to that block is an
 * invalid zero pointer reference. Dereferencing such a pointer is invalid.
 */ 

    int *p = 0;
    *p = 12;
    printf("output %d\n", *p);

    return 0;
}
