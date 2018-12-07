#ifndef __BONE_IMPORTER_H__
#define __BONE_IMPORTER_H__

#include "Importer.h"
#include "trDefs.h"

class aiBone;
class ResourceBone;

class BoneImporter : public Importer
{
public:

	BoneImporter();
	~BoneImporter();

	bool Import(const char* file_path, std::string& output_file); // TODO SOLVE THIS

	bool Import(const char* path, const char* file_name, std::string& output_file, UID& uid_to_force);

	UID Import(const aiBone* new_bone, UID mesh, std::string& output) const;

	bool SaveBone(const ResourceBone* bone, std::string& output) const;

};

#endif // __BONE_IMPORTER_H__