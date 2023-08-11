#include "numerical_diff.h"

float diff_cen(float (*function)(float),float x)
{
const float h = 0.001;
return ((function(x+h) - function(x-h)) / (2 * h));
}
