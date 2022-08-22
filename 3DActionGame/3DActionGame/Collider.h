#ifndef COLLIDER_H_
#define COLLIDER_H_

#include <DxLib.h>

struct BoxCollider
{
	BoxCollider() :
		pos(VGet(0, 0, 0)),
		offset(VGet(0, 0, 0)),
		size(VGet(1.0f, 1.0f, 1.0f))
	{}

	BoxCollider(VECTOR init_size) :
		pos(VGet(0, 0, 0)),
		offset(VGet(0, 0, 0)),
		size(init_size)
	{}

	BoxCollider(VECTOR init_offset, VECTOR init_size) :
		pos(VGet(0, 0, 0)),
		offset(init_offset),
		size(init_size)
	{}

	VECTOR GetFinalPos()
	{
		return VAdd(pos, offset);
	}

	VECTOR GetHalfSize()
	{
		return VGet(size.x / 2.0f, size.y / 2.0f, size.z / 2.0f);
	}

	VECTOR pos;
	VECTOR offset;
	VECTOR size;
};

struct SphereCollider
{
	SphereCollider() :
		pos(VGet(0, 0, 0)),
		offset(VGet(0, 0, 0)),
		radius(1.0f)
	{}

	SphereCollider(float init_radius) :
		pos(VGet(0, 0, 0)),
		offset(VGet(0, 0, 0)),
		radius(init_radius)
	{}

	SphereCollider(VECTOR init_offset, float init_radius) :
		pos(VGet(0, 0, 0)),
		offset(init_offset),
		radius(init_radius)
	{}

	VECTOR GetFinalPos()
	{
		return VAdd(pos, offset);
	}

	VECTOR pos;
	VECTOR offset;
	float radius;
};

#endif
