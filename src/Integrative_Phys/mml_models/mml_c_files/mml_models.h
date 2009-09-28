
#ifndef _MML_MODELS_H
#define _MML_MODELS_H
#include "glucose_model_Math_Model.cpp"
#include "insulin_model_Math_Model.cpp"
#include "unit_process_model_Math_Model.cpp"

class function_factory{
public: 

	double (*getFunction(char *fun_name))(double variable, Phys_Container<double> in_list){
	 if(strcmp(fun_name,"G_p") == 0){
		 return &math_model_G_p;
	 }
	 if(strcmp(fun_name,"G_t") == 0){
		 return &math_model_G_t;
	 }
	 if(strcmp(fun_name,"G") == 0){
		 return &math_model_G;
	 }
	 if(strcmp(fun_name,"I_l") == 0){
		 return &math_model_I_l;
	 }
	 if(strcmp(fun_name,"I_p") == 0){
		 return &math_model_I_p;
	 }
	 if(strcmp(fun_name,"I") == 0){
		 return &math_model_I;
	 }
	 if(strcmp(fun_name,"HE") == 0){
		 return &math_model_HE;
	 }
	 if(strcmp(fun_name,"m_3") == 0){
		 return &math_model_m_3;
	 }
	 if(strcmp(fun_name,"S_b") == 0){
		 return &math_model_S_b;
	 }
	 if(strcmp(fun_name,"EGP") == 0){
		 return &math_model_EGP;
	 }
	 if(strcmp(fun_name,"I_1") == 0){
		 return &math_model_I_1;
	 }
	 if(strcmp(fun_name,"I_d") == 0){
		 return &math_model_I_d;
	 }
	 if(strcmp(fun_name,"Q_sto") == 0){
		 return &math_model_Q_sto;
	 }
	 if(strcmp(fun_name,"Q_sto_1") == 0){
		 return &math_model_Q_sto_1;
	 }
	 if(strcmp(fun_name,"Q_sto_2") == 0){
		 return &math_model_Q_sto_2;
	 }
	 if(strcmp(fun_name,"Q_gut") == 0){
		 return &math_model_Q_gut;
	 }
	 if(strcmp(fun_name,"Ra") == 0){
		 return &math_model_Ra;
	 }
	 if(strcmp(fun_name,"U_ii") == 0){
		 return &math_model_U_ii;
	 }
	 if(strcmp(fun_name,"U_id") == 0){
		 return &math_model_U_id;
	 }
	 if(strcmp(fun_name,"V_m") == 0){
		 return &math_model_V_m;
	 }
	 if(strcmp(fun_name,"K_m") == 0){
		 return &math_model_K_m;
	 }
	 if(strcmp(fun_name,"X") == 0){
		 return &math_model_X;
	 }
	 if(strcmp(fun_name,"U") == 0){
		 return &math_model_U;
	 }
	 if(strcmp(fun_name,"S") == 0){
		 return &math_model_S;
	 }
	 if(strcmp(fun_name,"I_po") == 0){
		 return &math_model_I_po;
	 }
	 if(strcmp(fun_name,"S_po") == 0){
		 return &math_model_S_po;
	 }
	 if(strcmp(fun_name,"Y") == 0){
		 return &math_model_Y;
	 }
	 if(strcmp(fun_name,"E") == 0){
		 return &math_model_E;
	 }
};
};
#endif
