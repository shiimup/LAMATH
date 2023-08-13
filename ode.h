#ifndef ODE_H__
#define ODE_H__

float rk4(float t0,float y0,float t,float (*function) (float , float));

#endif