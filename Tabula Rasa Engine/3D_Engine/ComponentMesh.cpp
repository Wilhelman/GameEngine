#include "ComponentMesh.h"

#include "trApp.h"
#include "trRenderer3D.h"
#include "trFileLoader.h"
#include "MeshImporter.h"
#include "GameObject.h"

#include "trOpenGL.h"

ComponentMesh::ComponentMesh(GameObject * embedded_game_object) : 
	Component(embedded_game_object, Component::component_type::COMPONENT_MESH)
{
}

ComponentMesh::ComponentMesh(GameObject * embedded_game_object, UID resource) : 
	Component(embedded_game_object, Component::component_type::COMPONENT_MESH)
{
	this->resource = resource;
}

ComponentMesh::~ComponentMesh()
{
	// TODO IF RESOURCE != 0 DO SOMETHING TO DOWN THE REFERENCES
}

bool ComponentMesh::Save(JSON_Object* component_obj) const
{
	//todo: get resource path etc
	//json_object_set_string(component_obj, "path", mesh->path.c_str());
	return true;
}

bool ComponentMesh::Load(const JSON_Object * component_obj)
{
	bool ret = true;

	// todo get resource path and set.

	//JSON_Value* value = json_object_get_value(component_obj, "path");
	//const char* file_path = json_value_get_string(value);
	//ret = App->file_loader->mesh_importer->FillMeshFromFilePath(&mesh, file_path);


	return ret;
}

bool ComponentMesh::SetResource(UID resource)
{
	// needed?
	//embedded_go->bounding_box = AABB(float3(0.f, 0.f, 0.f), float3(0.f, 0.f, 0.f));
	//embedded_go->bounding_box.Enclose((float3*)this->mesh->vertices, this->mesh->vertex_size / 3);

	this->resource = resource;
	return true;
}
