#ifndef __trMAINSCENE_H__
#define __trMAINSCENE_H__

#include "SDL/include/SDL.h"
#include "trModule.h"

class PGrid;

class trMainScene : public trModule
{
public:

	trMainScene();

	// Destructor
	virtual ~trMainScene();

	// Called before render is available
	bool Awake(JSON_Object* config = nullptr);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate(float dt);
	bool Update(float dt);
	bool PostUpdate(float dt);

	// Called before quitting
	bool CleanUp();

	void Draw();

	// Load / Save
	bool Load(JSON_Object* config = nullptr);
	bool Save(JSON_Object* config = nullptr) const;

private:

	PGrid* grid = nullptr;
	std::string default_mesh;
};

#endif // __trRENDER_H__