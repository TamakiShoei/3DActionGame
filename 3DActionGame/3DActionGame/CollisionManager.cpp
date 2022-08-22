#include <math.h>
#include "CollisionManager.h"

extern int g_Handles[ModelKind::MaxModelKind];

bool CollisionManager::BoxAndBox(BoxCollider& collider01, BoxCollider& collider02)
{
	VECTOR final_pos01 = collider01.GetFinalPos();
	VECTOR final_pos02 = collider02.GetFinalPos();
	VECTOR length = VSub(final_pos01, final_pos02);
	length = VGet(fabsf(length.x), fabsf(length.y), fabsf(length.z));

	VECTOR half_size01 = collider01.GetHalfSize();
	VECTOR half_size02 = collider02.GetHalfSize();

	VECTOR size = VAdd(half_size01, half_size02);

	if (length.x <= size.x &&
		length.y <= size.y &&
		length.z <= size.z)
	{
		return true;
	}

	return false;
}

bool CollisionManager::SphereAndSphere(SphereCollider& collider01, SphereCollider& collider02)
{
	VECTOR final_pos01 = collider01.GetFinalPos();
	VECTOR final_pos02 = collider02.GetFinalPos();
	VECTOR length = VSub(final_pos01, final_pos02);

	float distance = sqrtf(length.x * length.x + length.y * length.y + length.z * length.z);
	float total_radius = collider01.radius + collider02.radius;

	if (distance <= total_radius)
	{
		return true;
	}

	return false;
}

bool CollisionManager::LineAndStage(const VECTOR& start, const VECTOR& end, VECTOR& cross_pos)
{
	if (stageCollisionModel == ModelKind::ModelKindNon)
	{
		return false;
	}

	// ステージとrayの当たり判定(MV1CollCheck_Lineを使用)
	MV1_COLL_RESULT_POLY result;
	result = MV1CollCheck_Line(g_Handles[stageCollisionModel], -1, start, end);

	// 当たってるかチェック
	if (result.HitFlag == 1)
	{
		// 当たった場所をcorss_posに保存
		cross_pos = result.HitPosition;

		return true;
	}

	return false;
}

bool CollisionManager::EntryStageCollision(ModelKind kind, int x_div, int y_div, int z_div)
{
	if (kind <= ModelKind::ModelKindNon ||
		kind >= ModelKind::MaxModelKind)
	{
		return false;
	}

	stageCollisionModel = kind;

	int result = 0;
	result = MV1SetupCollInfo(g_Handles[kind], -1, x_div, y_div, z_div);

	if (result == 0)
	{
		return true;
	}
	return false;
}
