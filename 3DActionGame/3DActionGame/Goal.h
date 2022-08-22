#ifndef GOAL_H
#define GOAL_H

#include "Object.h"

class Goal : public Object
{
public:
	Goal(int init_handle, int init_radius, VECTOR init_pos) :
		Object(init_pos),
		handle(init_handle),
		radius(init_radius),
		degree(0)
	{
		MV1SetScale(handle, VGet(radius, radius, radius));
	}
	~Goal();

	void Update() override;
	void Draw() override;

private:
	int handle;
	int radius;
	int degree;
};

#endif