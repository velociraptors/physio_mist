#ifndef _PHY_MIST_MANAGER_
#define _PHY_MIST_MANAGER_

#include "Simulation_Manager.h"

/*
Main manager for the application. Implements the singleton pattern
*/

class Phy_MIST_Manager{
	public:
		static Phy_MIST_Manager* getInstance();

		Simulation_Manager* get_simulation_manager();
		void set_simulation_manager(Simulation_Manager *manager);
		void create_XML_file(System::String ^filename);
		void load_XML_file(System::String ^filename);
	
protected:
	Phy_MIST_Manager();

	 ~Phy_MIST_Manager(){
		delete simulation_manager;
	};


private:
      
	static Phy_MIST_Manager *instance;

	Simulation_Manager *simulation_manager;

};
#endif