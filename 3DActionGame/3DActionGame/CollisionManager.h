#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_

#include "Common.h"
#include "Collider.h"

class CollisionManager
{
public:
	static bool BoxAndBox(BoxCollider& collider01, BoxCollider& collider02);
	static bool SphereAndSphere(SphereCollider& collider01, SphereCollider& collider02);

	static CollisionManager* Instance()
	{
		static CollisionManager instance;
		return &instance;
	}

public:
	bool LineAndStage(const VECTOR& start, const VECTOR& end, VECTOR& cross_pos);

	
	bool EntryStageCollision(ModelKind kind, int x_div, int y_div, int z_div);

private:
	CollisionManager() :
		stageCollisionModel(ModelKind::ModelKindNon)
	{
	}

	CollisionManager(CollisionManager& instance) = delete;

private:
	ModelKind stageCollisionModel;
};

#endif
