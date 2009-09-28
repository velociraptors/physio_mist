//////////////////////////////////////////////////////
// Implementation of insulin_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_I_l(double variable,Phys_Container<double> in_list){
double result = variable;
result = -((*(in_list.getNextItem()))+(*(in_list.getNextItem())))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_I_p(double variable,Phys_Container<double> in_list){
double result = variable;
result = -((*(in_list.getNextItem()))+(*(in_list.getNextItem())))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_I(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
};
static double math_model_HE(double variable, Phys_Container<double> in_list){
double result=variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_m_3(double variable, Phys_Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(1-(*(in_list.getNextItem())));
return result;
};
static double math_model_S_b(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
