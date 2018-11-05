#ifndef __trMAINSCENE_H__
#define __trMAINSCENE_H__

#include "trModule.h"
#include "Quadtree.h"

class GameObject;
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

	void DrawDebug();

	// Called before quitting
	bool CleanUp();

	void ClearScene();

	void Draw();

	// Load / Save
	bool Load(JSON_Object* config = nullptr);
	bool Save(JSON_Object* config = nullptr) const;

	GameObject* GetRoot()const;

	void InsertGoInQuadtree(GameObject* go);
	void EraseGoInQuadtree(GameObject* go);

	void ReDoQuadtree();

	GameObject* CreateGameObject(GameObject* parent);
	GameObject* CreateGameObject(const char* name, GameObject* parent = nullptr);

private:

	PGrid* grid = nullptr;
	std::string* default_mesh = nullptr;

	GameObject* root = nullptr;
	GameObject* main_camera = nullptr;

	std::list<GameObject*> static_go;
	
public:
	Quadtree quadtree;

};

#endif // __trRENDER_H__