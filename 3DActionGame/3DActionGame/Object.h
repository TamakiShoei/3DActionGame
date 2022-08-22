#ifndef OBJECT_H_
#define OBJECT_H_

#include "Common.h"

class Object
{
public:
	Object(VECTOR init_pos) :
		pos(init_pos),
		scale(VGet(1.0f, 1.0f, 1.0f)),
		degreeAngle(VGet(0.0f, 0.0f, 0.0f))
	{
	}

	// 継承を使ったポリモーフィズムでは必須
	virtual ~Object()
	{
	}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	const VECTOR& GetPos()
	{
		return pos;
	}

protected:
	VECTOR pos;
	VECTOR scale;
	VECTOR degreeAngle;
};

#endif
