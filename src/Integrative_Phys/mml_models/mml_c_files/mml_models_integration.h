
#ifndef _MML_MODELS_H
#define _MML_MODELS_H
#include "heart_model_Math_Model.cpp"
#include "systemic_circulation_Math_Model.cpp"
#include "pulmonary_circulation_Math_Model.cpp"
#include "baroreceptor_Math_Model.cpp"
#include "airway_mechanics_Math_Model.cpp"
#include "pericardium_Math_Model.cpp"
#include "coronary_circulation_Math_Model.cpp"
#include "iv_model_Math_Model.cpp"
#include "iv_injection_heart_Math_Model.cpp"
class function_factory{
public: 
double (*getFunction(char *fun_name))(double variable, Phys_Container<double> in_list){
	 if(strcmp(fun_name,"Tsv") == 0){
		 return &math_model_Tsv;
	 }
	 if(strcmp(fun_name,"Tsa") == 0){
		 return &math_model_Tsa;
	 }
	 if(strcmp(fun_name,"tshift") == 0){
		 return &math_model_tshift;
	 }
	 if(strcmp(fun_name,"afs_con2") == 0){
		 return &math_model_afs_con2;
	 }
	 if(strcmp(fun_name,"EDPLV") == 0){
		 return &math_model_EDPLV;
	 }
	 if(strcmp(fun_name,"EDPRV") == 0){
		 return &math_model_EDPRV;
	 }
	 if(strcmp(fun_name,"EDVLV") == 0){
		 return &math_model_EDVLV;
	 }
	 if(strcmp(fun_name,"EDVRV") == 0){
		 return &math_model_EDVRV;
	 }
	 if(strcmp(fun_name,"trela") == 0){
		 return &math_model_trela;
	 }
	 if(strcmp(fun_name,"trelv") == 0){
		 return &math_model_trelv;
	 }
	 if(strcmp(fun_name,"yla") == 0){
		 return &math_model_yla;
	 }
	 if(strcmp(fun_name,"yra") == 0){
		 return &math_model_yra;
	 }
	 if(strcmp(fun_name,"ylv") == 0){
		 return &math_model_ylv;
	 }
	 if(strcmp(fun_name,"yrv") == 0){
		 return &math_model_yrv;
	 }
	 if(strcmp(fun_name,"P_QRSwave") == 0){
		 return &math_model_P_QRSwave;
	 }
	 if(strcmp(fun_name,"Era") == 0){
		 return &math_model_Era;
	 }
	 if(strcmp(fun_name,"Vrar") == 0){
		 return &math_model_Vrar;
	 }
	 if(strcmp(fun_name,"Erv") == 0){
		 return &math_model_Erv;
	 }
	 if(strcmp(fun_name,"Vrvr") == 0){
		 return &math_model_Vrvr;
	 }
	 if(strcmp(fun_name,"Ela") == 0){
		 return &math_model_Ela;
	 }
	 if(strcmp(fun_name,"Vlar") == 0){
		 return &math_model_Vlar;
	 }
	 if(strcmp(fun_name,"Elv") == 0){
		 return &math_model_Elv;
	 }
	 if(strcmp(fun_name,"Vlvr") == 0){
		 return &math_model_Vlvr;
	 }
	 if(strcmp(fun_name,"Vla") == 0){
		 return &math_model_Vla;
	 }
	 if(strcmp(fun_name,"Fla") == 0){
		 return &math_model_Fla;
	 }
	 if(strcmp(fun_name,"Pla") == 0){
		 return &math_model_Pla;
	 }
	 if(strcmp(fun_name,"Plac") == 0){
		 return &math_model_Plac;
	 }
	 if(strcmp(fun_name,"Vlv") == 0){
		 return &math_model_Vlv;
	 }
	 if(strcmp(fun_name,"Flv") == 0){
		 return &math_model_Flv;
	 }
	 if(strcmp(fun_name,"Plv") == 0){
		 return &math_model_Plv;
	 }
	 if(strcmp(fun_name,"Plvc") == 0){
		 return &math_model_Plvc;
	 }
	 if(strcmp(fun_name,"Vra") == 0){
		 return &math_model_Vra;
	 }
	 if(strcmp(fun_name,"Fra") == 0){
		 return &math_model_Fra;
	 }
	 if(strcmp(fun_name,"Pra") == 0){
		 return &math_model_Pra;
	 }
	 if(strcmp(fun_name,"Prac") == 0){
		 return &math_model_Prac;
	 }
	 if(strcmp(fun_name,"Vrv") == 0){
		 return &math_model_Vrv;
	 }
	 if(strcmp(fun_name,"Frv") == 0){
		 return &math_model_Frv;
	 }
	 if(strcmp(fun_name,"Prv") == 0){
		 return &math_model_Prv;
	 }
	 if(strcmp(fun_name,"Prvc") == 0){
		 return &math_model_Prvc;
	 }
	 if(strcmp(fun_name,"COutput") == 0){
		 return &math_model_COutput;
	 }
	 if(strcmp(fun_name,"SV") == 0){
		 return &math_model_SV;
	 }
	 if(strcmp(fun_name,"Rsa") == 0){
		 return &math_model_Rsa;
	 }
	 if(strcmp(fun_name,"Rvc") == 0){
		 return &math_model_Rvc;
	 }
	 if(strcmp(fun_name,"Paopc") == 0){
		 return &math_model_Paopc;
	 }
	 if(strcmp(fun_name,"Paop") == 0){
		 return &math_model_Paop;
	 }
	 if(strcmp(fun_name,"MAP") == 0){
		 return &math_model_MAP;
	 }
	 if(strcmp(fun_name,"Paodc") == 0){
		 return &math_model_Paodc;
	 }
	 if(strcmp(fun_name,"Paod") == 0){
		 return &math_model_Paod;
	 }
	 if(strcmp(fun_name,"PaodFOL") == 0){
		 return &math_model_PaodFOL;
	 }
	 if(strcmp(fun_name,"Psa_a") == 0){
		 return &math_model_Psa_a;
	 }
	 if(strcmp(fun_name,"Psa_p") == 0){
		 return &math_model_Psa_p;
	 }
	 if(strcmp(fun_name,"Psa") == 0){
		 return &math_model_Psa;
	 }
	 if(strcmp(fun_name,"Psap") == 0){
		 return &math_model_Psap;
	 }
	 if(strcmp(fun_name,"Psc") == 0){
		 return &math_model_Psc;
	 }
	 if(strcmp(fun_name,"Psv") == 0){
		 return &math_model_Psv;
	 }
	 if(strcmp(fun_name,"Pvc") == 0){
		 return &math_model_Pvc;
	 }
	 if(strcmp(fun_name,"Pvcc") == 0){
		 return &math_model_Pvcc;
	 }
	 if(strcmp(fun_name,"Fcrb") == 0){
		 return &math_model_Fcrb;
	 }
	 if(strcmp(fun_name,"Fsap") == 0){
		 return &math_model_Fsap;
	 }
	 if(strcmp(fun_name,"Fsa") == 0){
		 return &math_model_Fsa;
	 }
	 if(strcmp(fun_name,"Fsc") == 0){
		 return &math_model_Fsc;
	 }
	 if(strcmp(fun_name,"Fsv") == 0){
		 return &math_model_Fsv;
	 }
	 if(strcmp(fun_name,"Fvc") == 0){
		 return &math_model_Fvc;
	 }
	 if(strcmp(fun_name,"Vaop") == 0){
		 return &math_model_Vaop;
	 }
	 if(strcmp(fun_name,"Vaod") == 0){
		 return &math_model_Vaod;
	 }
	 if(strcmp(fun_name,"Vsap") == 0){
		 return &math_model_Vsap;
	 }
	 if(strcmp(fun_name,"Vsa") == 0){
		 return &math_model_Vsa;
	 }
	 if(strcmp(fun_name,"Vsc") == 0){
		 return &math_model_Vsc;
	 }
	 if(strcmp(fun_name,"Vsv") == 0){
		 return &math_model_Vsv;
	 }
	 if(strcmp(fun_name,"Vvc") == 0){
		 return &math_model_Vvc;
	 }
	 if(strcmp(fun_name,"Faop") == 0){
		 return &math_model_Faop;
	 }
	 if(strcmp(fun_name,"Faod") == 0){
		 return &math_model_Faod;
	 }
	 if(strcmp(fun_name,"Vtot") == 0){
		 return &math_model_Vtot;
	 }
	 if(strcmp(fun_name,"VBcirc") == 0){
		 return &math_model_VBcirc;
	 }
	 if(strcmp(fun_name,"SysArtVol") == 0){
		 return &math_model_SysArtVol;
	 }
	 if(strcmp(fun_name,"SysVenVol") == 0){
		 return &math_model_SysVenVol;
	 }
	 if(strcmp(fun_name,"PulArtVol") == 0){
		 return &math_model_PulArtVol;
	 }
	 if(strcmp(fun_name,"PulVenVol") == 0){
		 return &math_model_PulVenVol;
	 }
	 if(strcmp(fun_name,"Ppapc1") == 0){
		 return &math_model_Ppapc1;
	 }
	 if(strcmp(fun_name,"Ppapc2") == 0){
		 return &math_model_Ppapc2;
	 }
	 if(strcmp(fun_name,"Ppap") == 0){
		 return &math_model_Ppap;
	 }
	 if(strcmp(fun_name,"Ppadc") == 0){
		 return &math_model_Ppadc;
	 }
	 if(strcmp(fun_name,"Ppad") == 0){
		 return &math_model_Ppad;
	 }
	 if(strcmp(fun_name,"Ppa") == 0){
		 return &math_model_Ppa;
	 }
	 if(strcmp(fun_name,"Ppac") == 0){
		 return &math_model_Ppac;
	 }
	 if(strcmp(fun_name,"Ppapc") == 0){
		 return &math_model_Ppapc;
	 }
	 if(strcmp(fun_name,"Ppc") == 0){
		 return &math_model_Ppc;
	 }
	 if(strcmp(fun_name,"Ppcc") == 0){
		 return &math_model_Ppcc;
	 }
	 if(strcmp(fun_name,"Ppv") == 0){
		 return &math_model_Ppv;
	 }
	 if(strcmp(fun_name,"Ppvc") == 0){
		 return &math_model_Ppvc;
	 }
	 if(strcmp(fun_name,"Fps") == 0){
		 return &math_model_Fps;
	 }
	 if(strcmp(fun_name,"Fpa") == 0){
		 return &math_model_Fpa;
	 }
	 if(strcmp(fun_name,"Fpc") == 0){
		 return &math_model_Fpc;
	 }
	 if(strcmp(fun_name,"Fpv") == 0){
		 return &math_model_Fpv;
	 }
	 if(strcmp(fun_name,"Vpap") == 0){
		 return &math_model_Vpap;
	 }
	 if(strcmp(fun_name,"Vpad") == 0){
		 return &math_model_Vpad;
	 }
	 if(strcmp(fun_name,"Vpa") == 0){
		 return &math_model_Vpa;
	 }
	 if(strcmp(fun_name,"Vpc") == 0){
		 return &math_model_Vpc;
	 }
	 if(strcmp(fun_name,"Vpv") == 0){
		 return &math_model_Vpv;
	 }
	 if(strcmp(fun_name,"Fpap") == 0){
		 return &math_model_Fpap;
	 }
	 if(strcmp(fun_name,"Fpad") == 0){
		 return &math_model_Fpad;
	 }
	 if(strcmp(fun_name,"HR") == 0){
		 return &math_model_HR;
	 }
	 if(strcmp(fun_name,"Nbr") == 0){
		 return &math_model_Nbr;
	 }
	 if(strcmp(fun_name,"Nbr_t") == 0){
		 return &math_model_Nbr_t;
	 }
	 if(strcmp(fun_name,"N_hrv") == 0){
		 return &math_model_N_hrv;
	 }
	 if(strcmp(fun_name,"F_hrv") == 0){
		 return &math_model_F_hrv;
	 }
	 if(strcmp(fun_name,"b_hrv") == 0){
		 return &math_model_b_hrv;
	 }
	 if(strcmp(fun_name,"N_hrs") == 0){
		 return &math_model_N_hrs;
	 }
	 if(strcmp(fun_name,"F_hrs") == 0){
		 return &math_model_F_hrs;
	 }
	 if(strcmp(fun_name,"b_hrs") == 0){
		 return &math_model_b_hrs;
	 }
	 if(strcmp(fun_name,"N_con") == 0){
		 return &math_model_N_con;
	 }
	 if(strcmp(fun_name,"F_con") == 0){
		 return &math_model_F_con;
	 }
	 if(strcmp(fun_name,"N_vaso") == 0){
		 return &math_model_N_vaso;
	 }
	 if(strcmp(fun_name,"b_vaso") == 0){
		 return &math_model_b_vaso;
	 }
	 if(strcmp(fun_name,"F_vaso") == 0){
		 return &math_model_F_vaso;
	 }
	 if(strcmp(fun_name,"HRcont") == 0){
		 return &math_model_HRcont;
	 }
	 if(strcmp(fun_name,"afs_con") == 0){
		 return &math_model_afs_con;
	 }
	 if(strcmp(fun_name,"bfs_con") == 0){
		 return &math_model_bfs_con;
	 }
	 if(strcmp(fun_name,"Rc") == 0){
		 return &math_model_Rc;
	 }
	 if(strcmp(fun_name,"Rs") == 0){
		 return &math_model_Rs;
	 }
	 if(strcmp(fun_name,"Ru") == 0){
		 return &math_model_Ru;
	 }
	 if(strcmp(fun_name,"dV") == 0){
		 return &math_model_dV;
	 }
	 if(strcmp(fun_name,"Pl") == 0){
		 return &math_model_Pl;
	 }
	 if(strcmp(fun_name,"Pcw") == 0){
		 return &math_model_Pcw;
	 }
	 if(strcmp(fun_name,"Pc") == 0){
		 return &math_model_Pc;
	 }
	 if(strcmp(fun_name,"Ppl") == 0){
		 return &math_model_Ppl;
	 }
	 if(strcmp(fun_name,"Pve") == 0){
		 return &math_model_Pve;
	 }
	 if(strcmp(fun_name,"PplmmHg") == 0){
		 return &math_model_PplmmHg;
	 }
	 if(strcmp(fun_name,"Pmouth") == 0){
		 return &math_model_Pmouth;
	 }
	 if(strcmp(fun_name,"Pplc") == 0){
		 return &math_model_Pplc;
	 }
	 if(strcmp(fun_name,"PplcFOL") == 0){
		 return &math_model_PplcFOL;
	 }
	 if(strcmp(fun_name,"RespRcont") == 0){
		 return &math_model_RespRcont;
	 }
	 if(strcmp(fun_name,"Pcc") == 0){
		 return &math_model_Pcc;
	 }
	 if(strcmp(fun_name,"Ps") == 0){
		 return &math_model_Ps;
	 }
	 if(strcmp(fun_name,"Vcw") == 0){
		 return &math_model_Vcw;
	 }
	 if(strcmp(fun_name,"Qdotco") == 0){
		 return &math_model_Qdotco;
	 }
	 if(strcmp(fun_name,"Qdotup") == 0){
		 return &math_model_Qdotup;
	 }
	 if(strcmp(fun_name,"Qdotve") == 0){
		 return &math_model_Qdotve;
	 }
	 if(strcmp(fun_name,"Qdotsm") == 0){
		 return &math_model_Qdotsm;
	 }
	 if(strcmp(fun_name,"VA") == 0){
		 return &math_model_VA;
	 }
	 if(strcmp(fun_name,"Vve") == 0){
		 return &math_model_Vve;
	 }
	 if(strcmp(fun_name,"Vc") == 0){
		 return &math_model_Vc;
	 }
	 if(strcmp(fun_name,"Alvflux") == 0){
		 return &math_model_Alvflux;
	 }
	 if(strcmp(fun_name,"PA") == 0){
		 return &math_model_PA;
	 }
	 if(strcmp(fun_name,"PD") == 0){
		 return &math_model_PD;
	 }
	 if(strcmp(fun_name,"PDc") == 0){
		 return &math_model_PDc;
	 }
	 if(strcmp(fun_name,"Pup") == 0){
		 return &math_model_Pup;
	 }
	 if(strcmp(fun_name,"Ppcd") == 0){
		 return &math_model_Ppcd;
	 }
	 if(strcmp(fun_name,"Ppcdc") == 0){
		 return &math_model_Ppcdc;
	 }
	 if(strcmp(fun_name,"Vpcd") == 0){
		 return &math_model_Vpcd;
	 }
	 if(strcmp(fun_name,"Pcorisfc") == 0){
		 return &math_model_Pcorisfc;
	 }
	 if(strcmp(fun_name,"Fcorao") == 0){
		 return &math_model_Fcorao;
	 }
	 if(strcmp(fun_name,"Fcorea") == 0){
		 return &math_model_Fcorea;
	 }
	 if(strcmp(fun_name,"Fcorla") == 0){
		 return &math_model_Fcorla;
	 }
	 if(strcmp(fun_name,"Fcorsa") == 0){
		 return &math_model_Fcorsa;
	 }
	 if(strcmp(fun_name,"Fcorcap") == 0){
		 return &math_model_Fcorcap;
	 }
	 if(strcmp(fun_name,"Fcorsv") == 0){
		 return &math_model_Fcorsv;
	 }
	 if(strcmp(fun_name,"Fcorlv") == 0){
		 return &math_model_Fcorlv;
	 }
	 if(strcmp(fun_name,"Fcorev") == 0){
		 return &math_model_Fcorev;
	 }
	 if(strcmp(fun_name,"Pcorao") == 0){
		 return &math_model_Pcorao;
	 }
	 if(strcmp(fun_name,"Pcorea") == 0){
		 return &math_model_Pcorea;
	 }
	 if(strcmp(fun_name,"Pcorla") == 0){
		 return &math_model_Pcorla;
	 }
	 if(strcmp(fun_name,"Pcorsa") == 0){
		 return &math_model_Pcorsa;
	 }
	 if(strcmp(fun_name,"Pcorcap") == 0){
		 return &math_model_Pcorcap;
	 }
	 if(strcmp(fun_name,"Pcorsv") == 0){
		 return &math_model_Pcorsv;
	 }
	 if(strcmp(fun_name,"Pcorlv") == 0){
		 return &math_model_Pcorlv;
	 }
	 if(strcmp(fun_name,"Pcorev") == 0){
		 return &math_model_Pcorev;
	 }
	 if(strcmp(fun_name,"Pcoraoc") == 0){
		 return &math_model_Pcoraoc;
	 }
	 if(strcmp(fun_name,"Pcoreac") == 0){
		 return &math_model_Pcoreac;
	 }
	 if(strcmp(fun_name,"Pcorlac") == 0){
		 return &math_model_Pcorlac;
	 }
	 if(strcmp(fun_name,"Pcorsac") == 0){
		 return &math_model_Pcorsac;
	 }
	 if(strcmp(fun_name,"Pcorcapc") == 0){
		 return &math_model_Pcorcapc;
	 }
	 if(strcmp(fun_name,"Pcorsvc") == 0){
		 return &math_model_Pcorsvc;
	 }
	 if(strcmp(fun_name,"Pcorlvc") == 0){
		 return &math_model_Pcorlvc;
	 }
	 if(strcmp(fun_name,"Pcorevc") == 0){
		 return &math_model_Pcorevc;
	 }
	 if(strcmp(fun_name,"Vcorao") == 0){
		 return &math_model_Vcorao;
	 }
	 if(strcmp(fun_name,"Vcorea") == 0){
		 return &math_model_Vcorea;
	 }
	 if(strcmp(fun_name,"Vcorla") == 0){
		 return &math_model_Vcorla;
	 }
	 if(strcmp(fun_name,"Vcorsa") == 0){
		 return &math_model_Vcorsa;
	 }
	 if(strcmp(fun_name,"Vcorcap") == 0){
		 return &math_model_Vcorcap;
	 }
	 if(strcmp(fun_name,"Vcorsv") == 0){
		 return &math_model_Vcorsv;
	 }
	 if(strcmp(fun_name,"Vcorlv") == 0){
		 return &math_model_Vcorlv;
	 }
	 if(strcmp(fun_name,"Vcorev") == 0){
		 return &math_model_Vcorev;
	 }
	 if(strcmp(fun_name,"Vcorcirc") == 0){
		 return &math_model_Vcorcirc;
	 }
	 if(strcmp(fun_name,"Conc_inj") == 0){
		 return &math_model_Conc_inj;
	 }
	 if(strcmp(fun_name,"Conc_unmixed") == 0){
		 return &math_model_Conc_unmixed;
	 }
	 if(strcmp(fun_name,"Conc_pa") == 0){
		 return &math_model_Conc_pa;
	 }
	 if(strcmp(fun_name,"Ca") == 0){
		 return &math_model_Ca;
	 }
	 	 if(strcmp(fun_name,"Conc_inj") == 0){
		 return &math_model_Conc_inj;
	 }
	 if(strcmp(fun_name,"Conc_unmixed") == 0){
		 return &math_model_Conc_unmixed;
	 }
	 if(strcmp(fun_name,"Conc_pa") == 0){
		 return &math_model_Conc_pa;
	 }
	 if(strcmp(fun_name,"Ca") == 0){
		 return &math_model_Ca;
	 }	 
	 if(strcmp(fun_name,"h_conc") == 0){
		 return &math_model_h_conc;
	 }
};
};
#endif
