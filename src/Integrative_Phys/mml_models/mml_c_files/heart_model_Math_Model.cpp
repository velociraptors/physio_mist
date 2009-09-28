//////////////////////////////////////////////////////
// Implementation of heart_model_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Tsv(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>=((*(in_list.getNextItem()))+((1/(*(in_list.getNextItem())))*59.999999999999986)))){
	 result = ((*(in_list.getNextItem()))*sqrt((1/(*(in_list.getNextItem())))/1))*7.745966692414832;
}
return result;
};
static double math_model_Tsa(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>=((*(in_list.getNextItem()))+((1/(*(in_list.getNextItem())))*59.999999999999986)))){
	 result = ((*(in_list.getNextItem()))*sqrt((1/(*(in_list.getNextItem())))/1))*7.745966692414832;
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
static double math_model_afs_con2(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))+(*(in_list.getNextItem()))>=((*(in_list.getNextItem()))+((1/(*(in_list.getNextItem())))*59.999999999999986)))){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_EDPLV(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))==0&&(*(in_list.getNextItem()))>0)){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_EDPRV(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))==0&&(*(in_list.getNextItem()))>0)){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_EDVLV(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))==0&&(*(in_list.getNextItem()))>0)){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_EDVRV(double variable, Container<double> in_list){
double result=variable;
	 if(((*(in_list.getNextItem()))==0&&(*(in_list.getNextItem()))>0)){
	 result = (*(in_list.getNextItem()));
}
return result;
};
static double math_model_trela(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_trelv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_yla(double variable, Container<double> in_list){
double result=variable;
if (0.0<=(*(in_list.getNextItem()))&&(*(in_list.getNextItem()))<(*(in_list.getNextItem()))){
result = (1.0-cos(PI*(*(in_list.getNextItem()))/(*(in_list.getNextItem()))))/2.0;
return result;
}
for(int i =0;i<2;i++){
in_list.getNextItem();
}
if((*(in_list.getNextItem()))<=(*(in_list.getNextItem()))&&(*(in_list.getNextItem()))<1.5*(*(in_list.getNextItem()))){
result = (1.0+cos(2.0*PI*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()))))/2.0;
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0.0;
return result;
};
static double math_model_yra(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_ylv(double variable, Container<double> in_list){
double result=variable;
if (0.0<=(*(in_list.getNextItem()))&&(*(in_list.getNextItem()))<(*(in_list.getNextItem()))){
result = (1.0-cos(PI*(*(in_list.getNextItem()))/(*(in_list.getNextItem()))))/2.0;
return result;
}
for(int i =0;i<2;i++){
in_list.getNextItem();
}
if((*(in_list.getNextItem()))<=(*(in_list.getNextItem()))&&(*(in_list.getNextItem()))<1.5*(*(in_list.getNextItem()))){
result = (1.0+cos(2.0*PI*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()))))/2.0;
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0.0;
return result;
};
static double math_model_yrv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_P_QRSwave(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))&&(*(in_list.getNextItem()))<(*(in_list.getNextItem()))+(0.02)){
result = 5;
return result;
}
for(int i =0;i<0;i++){
in_list.getNextItem();
}
if((*(in_list.getNextItem()))>((*(in_list.getNextItem()))+(*(in_list.getNextItem())))&&(*(in_list.getNextItem()))<((*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(0.02))){
result = 10;
return result;
}
for(int i =0;i<0;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Era(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vrar(double variable, Container<double> in_list){
double result=variable;
result = (1-(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Erv(double variable, Container<double> in_list){
double result=variable;
result = (((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vrvr(double variable, Container<double> in_list){
double result=variable;
result = (1-(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Ela(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vlar(double variable, Container<double> in_list){
double result=variable;
result = (1-(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Elv(double variable, Container<double> in_list){
double result=variable;
result = (((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vlvr(double variable, Container<double> in_list){
double result=variable;
result = (1-(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vla(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_Fla(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Pla(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp(((*(in_list.getNextItem())))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Plac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vlv(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_Flv(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Plv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp(((*(in_list.getNextItem())))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Plvc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vra(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem()))+(*(in_list.getNextItem())));
return result;
};
static double math_model_Fra(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Pra(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp(((*(in_list.getNextItem())))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Prac(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Vrv(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())));
return result;
};
static double math_model_Frv(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<3;i++){
in_list.getNextItem();
}
result = 0;
return result;
};
static double math_model_Prv(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Prvc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_COutput(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_SV(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))/(*(in_list.getNextItem())))*59.999999999999986;
return result;
};
