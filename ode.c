#include "ode.h"
float rk4(float t0,float y0,float t,float (*function)(float, float)){
    const float h = 0.001;
    for(;t0<t;t0+=h){
        float k1 = function(t0,y0);
        float k2 = function(t0+(h/2),y0 + (h*(k1/2)));
        float k3 = function(t0+(h/2),y0 +  (h*(k2/2)));
        float k4 = function(t0+h,y0+h*k3);
        y0 = y0 + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
    }
    return y0;
}
