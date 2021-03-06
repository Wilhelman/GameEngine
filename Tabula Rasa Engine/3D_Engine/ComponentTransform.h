#ifndef __COMPONENT_TRANSFORM_H__
#define __COMPONENT_TRANSFORM_H__

#include "MathGeoLib/MathGeoLib.h"
#include "Component.h"

class ComponentTransform : public Component
{
public:
	ComponentTransform(){}
	ComponentTransform(GameObject* embedded_game_object);
	ComponentTransform(GameObject* embedded_game_object, const float3& translation, const float3& scale, const Quat& rotation);
	~ComponentTransform();

	bool Save(JSON_Object* component_obj)const;
	bool Load(const JSON_Object* component_obj);

	void Setup(const float3& translation, const float3& scale, const Quat& rotation, bool importing = false);
	void SetupFromGlobalMatrix(float4x4 global_matrix);

	const float3& GetTranslation()const;
	const float3& GetScale()const;
	const Quat& GetRotation()const;

	void GetLocalPosition(float3* position, float3* scale, Quat* rot) const;

	float4x4 GetMatrix(); // Returns global (or local if have no parent)
	float4x4 GetLocal(); // Returns local

	void SetPosition(const float3 position);
	void SetScale(const float3 scale);
	void SetRotation(const Quat rot);

private:

	float3 position = float3::zero;
	float3 scale = float3::zero;
	Quat rotation = Quat::identity;

	float4x4 local_matrix;
	float4x4 global_matrix;

};

#endif // __COMPONENT_MATERIAL_H__