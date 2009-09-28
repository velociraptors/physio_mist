//////////////////////////////////////////////////////
// Implementation of systemic_circulation_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Rsa(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*exp(4*(*(in_list.getNextItem()))))+((*(in_list.getNextItem()))*pow(((*(in_list.getNextItem()))/(*(in_list.getNextItem()))),2));
return result;
};
static double math_model_Rvc(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*pow(((*(in_list.getNextItem()))/(*(in_list.getNextItem()))),2))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Paopc(double variable,Container<double> in_list){
double result = variable;
result = (((((*(in_list.getNextItem()))-(*(in_list.getNextItem())))-((*(in_list.getNextItem()))*16.66666666666667))-(*(in_list.getNextItem())))*((1/(*(in_list.getNextItem())))+((((*(in_list.getNextItem()))/1)*exp((*(in_list.getNextItem()))/(*(in_list.getNextItem()))))/(pow((exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1),2)))))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Paop(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_MAP(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Paodc(double variable, Container<double> in_list){
double result=variable;
result = ((((((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*(*(in_list.getNextItem())))-((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*(*(in_list.getNextItem())))*.059999999999999984))+((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(*(in_list.getNextItem())))*.060000000000000005))-((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1))*.059999999999999984))+(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*.059999999999999984))/((*(in_list.getNextItem()))+(*(in_list.getNextItem()))))*16.66666666666667;
return result;
};
static double math_model_Paod(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_PaodFOL(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(0.0005);
return result;
};
static double math_model_Psa_a(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*log10((((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem())))+1);
return result;
};
static double math_model_Psa_p(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+(*(in_list.getNextItem()))*pow(((*(in_list.getNextItem()))-(*(in_list.getNextItem()))),2);
return result;
};
static double math_model_Psa(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*(*(in_list.getNextItem()))+(1-(*(in_list.getNextItem())))*(*(in_list.getNextItem()));
return result;
};
static double math_model_Psap(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Psc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1));
return result;
};
static double math_model_Psv(double variable, Container<double> in_list){
double result=variable;
result = -(*(in_list.getNextItem()))*log10(((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-0.99);
return result;
};
static double math_model_Pvc(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))+(*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))-(*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1);
return result;
}
for(int i =0;i<10;i++){
in_list.getNextItem();
}
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-(*(in_list.getNextItem()))/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1);
return result;
};
static double math_model_Pvcc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+((*(in_list.getNextItem()))*.7371913011426465);
return result;
};
static double math_model_Fcrb(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fsap(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fsa(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fsc(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fsv(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Fvc(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Vaop(double variable,Container<double> in_list){
double result = variable;
result = ((((*(in_list.getNextItem()))-((*(in_list.getNextItem()))/(*(in_list.getNextItem()))))+((*(in_list.getNextItem()))*(1/(exp((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-1))))-((*(in_list.getNextItem()))*.7371913011426465))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Vaod(double variable,Container<double> in_list){
double result = variable;
result = (((*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.059999999999999984))-((*(in_list.getNextItem()))*.059999999999999984))*16.66666666666667;
return result;
};
static double math_model_Vsap(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vsa(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vsc(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vsv(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vvc(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Faop(double variable,Container<double> in_list){
double result = variable;
result = ((((*(in_list.getNextItem()))-(((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*16.66666666666667))-(*(in_list.getNextItem())))/(*(in_list.getNextItem())))*.059999999999999984;
return result;
};
static double math_model_Faod(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem()))*(*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Vtot(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_VBcirc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_SysArtVol(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_SysVenVol(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_PulArtVol(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_PulVenVol(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
