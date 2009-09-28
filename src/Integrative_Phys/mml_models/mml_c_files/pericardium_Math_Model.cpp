//////////////////////////////////////////////////////
// Implementation of pericardium_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Ppcd(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*exp(((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()))))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Ppcdc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Vpcd(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
