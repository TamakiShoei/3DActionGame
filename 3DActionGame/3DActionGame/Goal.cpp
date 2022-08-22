#include "Goal.h"
#include <math.h>
#include "Common.h"

Goal::~Goal()
{
	DeleteGraph(handle);
}

void Goal::Update()
{
	degree += 2;
	pos.y = sin(DegToRad(degree)) * 10;
	if (degree >= 360)
	{
		degree = 0;
	}
}

void Goal::Draw()
{
	MV1SetDifColorScale(handle, GetColorF(1.0f, 1.0f, 0.0f, 1.0f));
	MV1SetPosition(handle, pos);
	MV1DrawModel(handle);
}

