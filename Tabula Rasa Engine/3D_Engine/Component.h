#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "trDefs.h"
#include "ParsonJson/parson.h"

class GameObject;

class Component
{
public:

	enum component_type {
		COMPONENT_UNKNOWN,

		COMPONENT_TRANSFORM,
		COMPONENT_MESH,
		COMPONENT_MATERIAL,
		COMPONENT_CAMERA
	};

public:
	Component(){}
	Component(GameObject* embedded_go, component_type type);
	virtual ~Component() {}

	virtual bool Enable();
	virtual bool PreUpdate(float dt);
	virtual bool Update(float dt);
	virtual bool Disable();

	virtual bool Save(JSON_Object* component_obj)const;
	virtual bool Load(const JSON_Object* component_obj);

	UID GetUUID()const;
	GameObject* GetEmbeddedObject() const;
	bool IsActive()const;

	const component_type GetType()const;

protected:

	bool active = false;
	
	GameObject* embedded_go = nullptr;
	component_type type = component_type::COMPONENT_UNKNOWN;
	UID uuid = 0u;

};

#endif // __GAMEOBJECT_H__