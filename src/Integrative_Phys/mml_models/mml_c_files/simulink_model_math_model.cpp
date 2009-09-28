//////////////////////////////////////////////////////
// Implementation of simulink_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_v1(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_v2(double variable, Container<double> in_list){
double result=variable;
result = 0.5*(*(in_list.getNextItem()))/(*(in_list.getNextItem()))+(*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
};
static double math_model_v3(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))/(*(in_list.getNextItem())))*(*(in_list.getNextItem()));
return result;
};
static double math_model_v4(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
