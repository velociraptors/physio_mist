//////////////////////////////////////////////////////
// Implementation of iv_injection_heart_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_h_conc(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))-(*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
