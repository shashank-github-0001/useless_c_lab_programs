#include <stdio.h>

void toh(int n, char source, char dest, char aux) {
    if(n==1) printf("\n move disc no=%d from %c to %c",n,source,dest);
    else {
        toh(n-1,source,aux,dest);
        printf("\n move disc = %d from %c to %c",n,source,dest);
        toh(n-1,aux,dest,source);        
    }
}

int main() {
    toh(20, 'a', 'c', 'b');
    return 0;
}

/*
 * move disc no=1 from A to C
 * move disc = 2 from A to B
 * move disc no=1 from C to B
 * move disc = 3 from A to C
 * move disc no=1 from B to A
 * move disc = 2 from B to C
 * move disc no=1 from A to C%
 */
