#include "integral.h"
#include <stdio.h>
// Try multithreading this thing sometime!

/*
float smp38(float (*function)(float),float a,float b,float h){

        int counter=0;
        int coeff[3]={3,3,2};

       for(float i=a+h;i<b-h;i+=h){          // Eval the function
                counter++;

       }
        // Add the first f(X) and the last f(Xi)
}
*/

float smp38(float (*function)(float),float a,float b,int n){
        float h=(b-a)/n;
        float acc=0;
        float acc_0=0;
        float acc_1=0;
        float acc_2=0;
        printf("h: %.4f\n",h);
       for(int i=1;i<n-1;i+=3){             /* Eval the function */
               acc_0+=function(a+i*h);
               printf("acc_0: %.4f i: %d\n",acc_0,i);
       }

        acc_0*=3;

       for(int i=2;i<=n-1;i+=3){
               acc_1+=function(a+i*h);
               printf("acc_1: %.4f i: %d\n",acc_1,i);
       }

        acc_1*=3;

       for(int i=3;i<n-1;i+=3){
                acc_2+=function(a+i*h);
                printf("acc_2: %.4f i: %d\n",acc_2,i);

       }

        acc_2*=2;

        acc+=function(a);
        acc+=function(b);

        acc=acc+acc_2+acc_1+acc_0;
        printf("Total Acc: %.6f\n", acc);
        acc = ((3*h)/8) * acc;

       return acc;
}
