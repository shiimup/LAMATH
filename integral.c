#include "integral.h"

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
        double h=(b-a)/n;
        float acc=0;
        float acc_0=0;
        float acc_1=0;
        float acc_2=0;

       for(int i=1;i<n-1;i+=3){             /* Eval the function */
               acc_0+=function(a+i*h);
       }

        acc_0*=3;

       for(int i=2;i<n-1;i+=3){
               acc_1+=function(a+i*h);
       }

        acc_1*=3;

       for(int i=3;i<n-1;i+=3){
                acc_2+=function(a+i*h);
       }

        acc_2*=2;

        acc+=function(a);
        acc+=function(b);

        acc=acc+acc_2+acc_1+acc_0;

        acc = ((3*acc)/8) * h;

       return acc;
}
