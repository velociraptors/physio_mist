//////////////////////////////////////////////////////
// Implementation of baroreceptor model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_HR(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>=((*(in_list.getNextItem()))+((1/(*(in_list.getNextItem())))*59.999999999999986)))){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_tshift(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>=((*(in_list.getNextItem()))+((1/(*(in_list.getNextItem())))*59.999999999999986)))){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_Nbr_t(double variable,Container<double> in_list){
double result = variable;
result = (((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))+(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*(*(in_list.getNextItem()))))-(*(in_list.getNextItem())))-(((*(in_list.getNextItem()))+(*(in_list.getNextItem())))*(*(in_list.getNextItem()))))/((*(in_list.getNextItem()))*(*(in_list.getNextItem())));
return result;
};
static double math_model_Nbr(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_deneme2(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem())))*(*(in_list.getNextItem()));
return result;
};
static double math_model_deneme(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem())))*(*(in_list.getNextItem()));
return result;
};
static double math_model_N_hrv(double variable,Container<double> in_list){
double result = variable;
if ((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (-(*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem()))))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_F_hrv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+1.0));
return result;
};
static double math_model_b_hrv(double variable, Container<double> in_list){
double result=variable;
result = 1-(*(in_list.getNextItem()));
return result;
};
static double math_model_N_hrs(double variable,Container<double> in_list){
double result = variable;
if ((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (-(*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem()))))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_F_hrs(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+1.0));
return result;
};
static double math_model_b_hrs(double variable, Container<double> in_list){
double result=variable;
result = 1-(*(in_list.getNextItem()));
return result;
};
static double math_model_N_con(double variable,Container<double> in_list){
double result = variable;
if ((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (-(*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem()))))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_F_con(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+1.0));
return result;
};
static double math_model_N_vaso(double variable,Container<double> in_list){
double result = variable;
if ((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (-(*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem()))))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_b_vaso(double variable, Container<double> in_list){
double result=variable;
result = 1-(*(in_list.getNextItem()));
return result;
};
static double math_model_F_vaso(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+1.0));
return result;
};
static double math_model_HRcont(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem())))-((*(in_list.getNextItem()))*pow((*(in_list.getNextItem())),2))-((*(in_list.getNextItem()))*(*(in_list.getNextItem())))+((*(in_list.getNextItem()))*pow((*(in_list.getNextItem())),2))-((*(in_list.getNextItem()))*(*(in_list.getNextItem()))*(*(in_list.getNextItem()))));
return result;
};
static double math_model_afs_con(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem())));
return result;
};
static double math_model_bfs_con(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*(*(in_list.getNextItem())));
return result;
};
