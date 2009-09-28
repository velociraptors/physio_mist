//////////////////////////////////////////////////////
// Implementation of coronary_circulation_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Pcorisfc(double variable, Container<double> in_list){
double result=variable;
result = abs(((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/2);
return result;
};
static double math_model_Fcorao(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorea(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorla(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorsa(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorcap(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorsv(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorlv(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fcorev(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorao(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorea(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorla(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorsa(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorcap(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorsv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorlv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcorev(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Pcoraoc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_Pcoreac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorlac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorsac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorcapc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorsvc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorlvc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcorevc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorao(double variable,Container<double> in_list){
double result = variable;
result = (((*(in_list.getNextItem()))-(*(in_list.getNextItem())))-((*(in_list.getNextItem()))*16.66666666666667))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorea(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorla(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorsa(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorcap(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorsv(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorlv(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorev(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcorcirc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
