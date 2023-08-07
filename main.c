#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrix.h"
#include "integral.h"

#define PI 3.14159

int main(int argc,char **argv){

        srand(time(NULL)); /* Seed the RNG */

        // rand() % range + min;



        printf("Hello World!\n");
        float m1[N][N];
        float m2[N][N];
        float l[N][N];
        float res[N][N];
        float res2[N][N];
        init_matrix(res2);
        _fill_matrix(m1);
        _fill_matrix(m2);

//       print_matrix(m1);
 //       print_matrix(m2);
/*
        init_matrix(res);
        print_matrix(res);
        matmul(m1,m2,res);

        print_matrix(res);
*/

        init_matrix(l);
        init_matrix(res);
 //       print_matrix(l);
        print_matrix(m1);
        LUdecompose(l,m1,res);
        print_matrix(l);
        print_matrix(m1);
        matmul(l,m1,res2);
        print_matrix(res2);


        printf("%.4f\n",(smp38(&(sinf),4,23,27)));

        return 0;
}
