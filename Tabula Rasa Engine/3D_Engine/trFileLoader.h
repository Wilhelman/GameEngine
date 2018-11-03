#ifndef __FILE_LOADER_H__
#define __FILE_LOADER_H__

#include "trModule.h"
#include "trDefs.h"
#include "MathGeoLib\MathGeoLib.h"

struct Mesh;

class GameObkject;
class ComponentMaterial;
class aiScene;
class aiNode;
class aiMaterial;
class GameObject;

class trFileLoader : public trModule
{
public:

	trFileLoader();
	~trFileLoader();

	// Called before render is available
	bool Awake(JSON_Object* config = nullptr);

	// Called before the first frame
	bool Start();
	bool CleanUp();

	bool Import3DFile(const char* file_path);
	void ImportNodesRecursively(const aiNode* node, const aiScene* scene, GameObject* parent_go, char* file_path);

	ComponentMaterial* LoadTexture(aiMaterial* material, GameObject* go);


	bool SaveMeshFile(const char* file_name);
	bool LoadMeshFile(const char* file_path);

private:

	Mesh* mesh_data = nullptr;
	
	std::vector<vec> scene_vertices;
	uint scene_num_vertex = 0;
	AABB* model_bouncing_box = nullptr;

};

#endif // __FILE_LOADER_H__
