#ifndef __MATERIAL_IMPORTER_H__
#define __MATERIAL_IMPORTER_H__

#include "Importer.h"
#include "trDefs.h"
#include <string>

class ResourceTexture;

class MaterialImporter : public Importer
{
public:

	MaterialImporter();
	~MaterialImporter();

	bool Import(const char* file_path, std::string& output_file); // TODO SOLVE THIS

	bool Import(const char* path, const char* file_name, std::string& output_file, UID& uid_to_force);

	UID LoadImageFromPath(const char* path, UID uid_to_force = 0u);

	void DeleteTextureBuffer(ResourceTexture* tex);


};

#endif // __MATERIAL_IMPORTER_H__
