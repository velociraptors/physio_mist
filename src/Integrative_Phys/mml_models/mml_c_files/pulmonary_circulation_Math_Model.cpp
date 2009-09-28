//////////////////////////////////////////////////////
// Implementation of pulmonary_circulation_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Ppapc1(double variable, Container<double> in_list){
double result=variable;
result = ((((((*(in_list.getNextItem()))*((*(in_list.getNextItem()))/(*(in_list.getNextItem()))))-((*(in_list.getNextItem()))*((*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1)))))+((*(in_list.getNextItem()))*(*(in_list.getNextItem()))))-((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*(*(in_list.getNextItem())))*16.666666666666668))+(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*.7371913011426465))/((*(in_list.getNextItem()))+(*(in_list.getNextItem())));
return result;
};
static double math_model_Ppapc2(double variable, Container<double> in_list){
double result=variable;
result = ((((*(in_list.getNextItem()))/(*(in_list.getNextItem())))+((*(in_list.getNextItem()))*.7371913011426464))-(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*16.666666666666668))-((*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1)));
return result;
};
static double math_model_Ppap(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Ppadc(double variable, Container<double> in_list){
double result=variable;
result = ((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))+((*(in_list.getNextItem()))*.7371913011426465))+((*(in_list.getNextItem()))/(*(in_list.getNextItem()))))-((*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1)));
return result;
};
static double math_model_Ppad(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Ppa(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Ppac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Ppapc(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (*(in_list.getNextItem()));
return result;
}
for(int i =0;i<1;i++){
in_list.getNextItem();
}
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_Ppc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Ppcc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Ppv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Ppvc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Fps(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fpa(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fpc(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fpv(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Vpap(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*16.66666666666667);
return result;
};
static double math_model_Vpad(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.059999999999999984))*16.66666666666667;
return result;
};
static double math_model_Vpa(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vpc(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vpv(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Fpap(double variable,Container<double> in_list){
double result = variable;
result = ((((*(in_list.getNextItem()))-(*(in_list.getNextItem())))-(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*16.66666666666667))/(*(in_list.getNextItem())))*.059999999999999984;
return result;
};
static double math_model_Fpad(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
