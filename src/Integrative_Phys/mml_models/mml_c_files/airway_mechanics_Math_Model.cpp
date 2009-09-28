//////////////////////////////////////////////////////
// Implementation of airway_mechanics_Math_Model
//////////////////////////////////////////////////////
#include <math.h>
#include "utilities.h" 
#define PI 3.14159265
static double math_model_Rc(double variable, Container<double> in_list){
double result=variable;
if ((*(in_list.getNextItem()))>(*(in_list.getNextItem()))){
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
}
for(int i =0;i<2;i++){
in_list.getNextItem();
}
result = (*(in_list.getNextItem()))*(pow(((*(in_list.getNextItem()))/(*(in_list.getNextItem()))),2))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Rs(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*exp((*(in_list.getNextItem()))*((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Ru(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))*abs((*(in_list.getNextItem())));
return result;
};
static double math_model_dV(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(*(in_list.getNextItem()));
return result;
};
static double math_model_Pl(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*exp((*(in_list.getNextItem()))*(*(in_list.getNextItem())))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Pcw(double variable, Container<double> in_list){
double result=variable;
result = (((*(in_list.getNextItem()))*sin(((6.283185307179586*(*(in_list.getNextItem())))*((*(in_list.getNextItem()))-(*(in_list.getNextItem()))))*0.016666666666666666))-(*(in_list.getNextItem())))*1.3565;
return result;
};
static double math_model_Pc(double variable, Container<double> in_list){
double result=variable;
if (((*(in_list.getNextItem()))/(*(in_list.getNextItem())))<.5){
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*(pow((((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-.7),2)));
return result;
}
for(int i =0;i<4;i++){
in_list.getNextItem();
}
result = ((*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.03999999999999998))-((*(in_list.getNextItem()))*log(((*(in_list.getNextItem()))/(*(in_list.getNextItem())))-0.999));
return result;
};
static double math_model_Ppl(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_Pve(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))/(*(in_list.getNextItem()));
return result;
};
static double math_model_PplmmHg(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*.7371913011426465;
return result;
};
static double math_model_Pmouth(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))*1.3565;
return result;
};
static double math_model_Pplc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_PplcFOL(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/(0.001);
return result;
};
static double math_model_RespRcont(double variable, Container<double> in_list){
double result=variable;
if (((*(in_list.getNextItem()))/6.283185307179586)>2.0000000000000004){
result = 120;
return result;
}
for(int i =0;i<0;i++){
in_list.getNextItem();
}
result = ((*(in_list.getNextItem()))/6.283185307179586)*59.999999999999986;
return result;
};
static double math_model_Pcc(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Ps(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))-(*(in_list.getNextItem()));
return result;
};
static double math_model_Vcw(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_Qdotco(double variable, Container<double> in_list){
double result=variable;
result = (((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/((*(in_list.getNextItem()))+(*(in_list.getNextItem()))))*1000.0000000000001;
return result;
};
static double math_model_Qdotup(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()));
return result;
};
static double math_model_Qdotve(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))/(*(in_list.getNextItem())))*1000.0000000000001;
return result;
};
static double math_model_Qdotsm(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))/(*(in_list.getNextItem())))*1000.0000000000001;
return result;
};
static double math_model_VA(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))/1000.0000000000001;
return result;
};
static double math_model_Vve(double variable,Container<double> in_list){
double result = variable;
result = (*(in_list.getNextItem()))-((*(in_list.getNextItem()))*.001);
return result;
};
static double math_model_Vc(double variable,Container<double> in_list){
double result = variable;
result = ((*(in_list.getNextItem()))-(*(in_list.getNextItem())))*.001;
return result;
};
static double math_model_Alvflux(double variable, Container<double> in_list){
double result=variable;
result = ((((*(in_list.getNextItem()))*(*(in_list.getNextItem())))/(((*(in_list.getNextItem()))+1030.94)*(*(in_list.getNextItem()))))*((*(in_list.getNextItem()))+(*(in_list.getNextItem()))))*.022608333333333334;
return result;
};
static double math_model_PA(double variable, Container<double> in_list){
double result=variable;
result = (*(in_list.getNextItem()))+(*(in_list.getNextItem()))+(*(in_list.getNextItem()));
return result;
};
static double math_model_PD(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*(*(in_list.getNextItem())))*9.999999999999998E-4;
return result;
};
static double math_model_PDc(double variable, Container<double> in_list){
double result=variable;
result = (((*(in_list.getNextItem()))*(*(in_list.getNextItem())))+((*(in_list.getNextItem()))*1000.0000000000001))*9.999999999999998E-4;
return result;
};
static double math_model_Pup(double variable, Container<double> in_list){
double result=variable;
result = ((*(in_list.getNextItem()))*((*(in_list.getNextItem()))+(*(in_list.getNextItem()))))*9.999999999999998E-4;
return result;
};
