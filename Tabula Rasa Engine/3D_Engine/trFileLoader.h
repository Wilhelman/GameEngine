#ifndef __FILE_LOADER_H__
#define __FILE_LOADER_H__

#include "trModule.h"
#include "trDefs.h"
#include <list>
#include "MathGeoLib\MathGeoLib.h"

#include "Assimp/include/cimport.h"

class Mesh;

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

private:

	Mesh* mesh_data = nullptr;
	
	std::vector<float*> scene_vertices;
	uint scene_num_vertex = 0;


};

#endif // __FILE_LOADER_H__
