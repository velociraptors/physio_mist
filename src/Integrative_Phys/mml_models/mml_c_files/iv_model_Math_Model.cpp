//////////////////////////////////////////////////////
// Implementation of iv_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Conc_inj(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Conc_unmixed(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))<(*(in_list.getNextItem()))){
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<2;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Conc_pa(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))/(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_Ca(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>((*(in_list.getNextItem()))/((*(in_list.getNextItem()))/(*(in_list.getNextItem()))))){
result = (((*(in_list.getNextItem()))-((*(in_list.getNextItem()))/((*(in_list.getNextItem()))/(*(in_list.getNextItem())))))*(1-(*(in_list.getNextItem()))));
return result;
}
for(int i =0;i<5;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
