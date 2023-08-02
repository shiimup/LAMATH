#ifndef INTEGRAL_H__
#define INTEGRAL_H__

/* float* eval(float (*functionPtr)(float),a,b,h); Maybe have a generic function that evals a function from a to b for every h sized step and then return the result as a pointer to an array of floats?  */

float smp38(float (*function)(float),float a,float b,int n);


#endif
