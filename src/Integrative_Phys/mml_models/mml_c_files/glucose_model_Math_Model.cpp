//////////////////////////////////////////////////////
// Implementation of glucose_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_G_p(double variable,Phys_Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_G_t(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_G(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
};
