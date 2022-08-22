#include <math.h>
#include "Camera.h"

void Camera::Update()
{
	CalculateTpsCameraPos(pos);
	pos = VAdd(pos, parameter.offsetPos);

	MATRIX pitch = MGetRotX(DegToRad(parameter.pitchAngle));
	MATRIX yow = MGetRotY(DegToRad(parameter.yawAngle));
	MATRIX mat = MMult(pitch, yow);
	VECTOR vector = VTransform(VGet(0, 0, -1.0f), mat);

	targetPos = VAdd(vector, pos);

	SetCameraPositionAndTarget_UpVecY(
		pos,			// ÉJÉÅÉâç¿ïW
		targetPos		// íçéãì_
	);
}

void Camera::CalculateTpsCameraPos(VECTOR& out_vector)
{
	out_vector = parameter.frontVector;

	out_vector = VScale(out_vector, -1.0f);

	float length = sqrtf(out_vector.x * out_vector.x + 
							out_vector.y * out_vector.y + 
								out_vector.z * out_vector.z);

	out_vector = VScale(out_vector, 1 / length);

	out_vector = VScale(out_vector, parameter.distance);

	out_vector = VAdd(out_vector, parameter.targetPos);
}
