#ifndef __trAPP_H__
#define __trAPP_H__

#include <list>
#include <string>
#include "trModule.h"
#include "trPerfTimer.h"
#include "trTimer.h"
#include "PugiXml\src\pugixml.hpp"
#include "trLog.h"

// Modules
class trWindow;
class trInput;
class trRenderer3D;
class trAudio;
class trCamera3D;
class trMainScene;
class trEditor;
class trHardware;

class trApp
{
public:

	// Constructor
	trApp(int argc, char* args[]);

	// Destructor
	virtual ~trApp();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

	// Add a new module to handle
	void AddModule(trModule* module);

	// Exposing some properties for reading
	int GetArgc() const;
	const char* GetArgv(int index) const;
	const char* GetTitle() const;
	const char* GetOrganization() const;

	// Load config file
	pugi::xml_node LoadConfig(pugi::xml_document&) const;


private:

	// Call modules before each loop iteration
	void PrepareUpdate();

	// Call modules before each loop iteration
	void FinishUpdate();

	// Call modules before each loop iteration
	bool PreUpdate();

	// Call modules on each loop iteration
	bool DoUpdate();

	// Call modules after each loop iteration
	bool PostUpdate();

public:

	// Modules
	trWindow*			win = nullptr;
	trInput*			input = nullptr;
	trRenderer3D*		render = nullptr;
	trAudio*			audio = nullptr;
	trCamera3D*			camera = nullptr;
	
	trMainScene*		main_scene = nullptr;

	trEditor*			editor = nullptr;
	trHardware*			hardware = nullptr;
	

	bool				cap_state = false;

private:

	std::list<trModule*>	modules;
	int					argc = 0;
	char**				args = nullptr;

	std::string			game_title;
	std::string			organization;
	std::string			vsync_to_show;
	std::string			cap_to_show;

	trPerfTimer			perf_timer;
	trTimer				simple_timer;

	trPerfTimer			ptimer;
	uint64				frame_count = 0;
	uint				cap = 0u;
	trTimer				startup_time;
	float				dt = 0.0f;
	int					capped_ms = -1;
	bool				all_modules_loaded = false;

};

extern trApp* App;

#endif