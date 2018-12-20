#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "trModule.h"
#include "trDefs.h"
#include "MathGeoLib\MathGeoLib.h"
#include "ResourceAnimation.h"

#include <vector>
#include <map>
#include <list>

class GameObject;
class ComponentBone;

class trAnimation : public trModule
{
public:

	trAnimation();
	~trAnimation();

	// Called before render is available
	bool Awake(JSON_Object* config = nullptr);

	// Called before the first frame
	bool Start();
	bool CleanUp();
	bool Update(float dt);

	void SetAnimationGos(ResourceAnimation* res);

	void RecursiveGetAnimableGO(GameObject* go, ResourceAnimation::BoneTransformation* bone_transformation);
	void MoveAnimationForward(float t);

	float GetCurrentAnimationTime() const;
	void PlayAnimation();
	void PauseAnimation();
	void StopAnimation();

public:
	
	std::vector<GameObject*> animable_gos;
	std::map<GameObject*, ResourceAnimation::BoneTransformation*> animable_data_map;

	void DeformMesh(ComponentBone* component_bone);

private:

	float anim_timer = 0.0f;
	bool start_anim = false;
	float duration = 0.0f;

};

#endif // __ANIMATION_H__