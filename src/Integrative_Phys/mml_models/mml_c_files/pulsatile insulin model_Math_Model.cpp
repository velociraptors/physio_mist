//////////////////////////////////////////////////////
// Implementation of pulsatile insulin model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_plasma_insulin(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(((*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))/(*(in_list.getNextItem())))*(*(in_list.getNextItem())))-((*(in_list.getNextItem()))/(*(in_list.getNextItem())));
return result;
};
static double math_model_remote_insulin(double variable,Container<double> in_list){
double result = variable;
result = (((*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))/(*(in_list.getNextItem())))*(*(in_list.getNextItem())))-((*(in_list.getNextItem()))/(*(in_list.getNextItem())));
return result;
};
static double math_model_plasma_glucose(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_f1_z(double variable, Container<double> in_list){
double result=variable;
result = 209/(1+exp(-(*(in_list.getNextItem()))/(300*(*(in_list.getNextItem())))+6.6));
return result;
};
static double math_model_f2_z(double variable, Container<double> in_list){
double result=variable;
result = 72*(1-exp(-(*(in_list.getNextItem()))/(144*(*(in_list.getNextItem())))));
return result;
};
static double math_model_f3_z(double variable, Container<double> in_list){
double result=variable;
result = (0.01*(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_f4_y(double variable, Container<double> in_list){
double result=variable;
result = 90/(1+exp(-1.772*log((*(in_list.getNextItem()))*(1/(*(in_list.getNextItem()))+1/((*(in_list.getNextItem()))*(*(in_list.getNextItem())))))+7.76))+4;
return result;
};
static double math_model_f5_h3(double variable, Container<double> in_list){
double result=variable;
result = 180/(1+exp(0.29*(*(in_list.getNextItem()))/(*(in_list.getNextItem()))-7.5));
return result;
};
static double math_model_h1(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_h2(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_h3(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
