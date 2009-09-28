//////////////////////////////////////////////////////
// Implementation of unit_process_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_EGP(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_I_1(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_I_d(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_Q_sto(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Q_sto_1(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_Q_sto_2(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_Q_gut(double variable, Phys_Container<double> in_list){
double result=variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_Ra(double variable, Phys_Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*(*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_U_ii(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_U_id(double variable, Phys_Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*(*(in_list.getNextItem())))/((*(in_list.getNextItem()))+(*(in_list.getNextItem())));
return result;
};
static double math_model_V_m(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_K_m(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_X(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_U(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_S(double variable, Phys_Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_I_po(double variable,Phys_Container<double> in_list){
double result = variable;
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_S_po(double variable, Phys_Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>0){
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Y(double variable,Phys_Container<double> in_list){
double result = variable;
if ((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))>=-(*(in_list.getNextItem()))){
result = -(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))));
return result;
}
for(int i =0;i<5;i++){
in_list.getNextItem();
}
result = -(*(in_list.getNextItem()))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()));
return result;
};
static double math_model_E(double variable, Phys_Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
