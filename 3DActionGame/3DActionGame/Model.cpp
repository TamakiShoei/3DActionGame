#include <math.h>
#include "Model.h"

extern int g_Handles[ModelKind::MaxModelKind];

void Model::Update()
{
	UpdateAnimation();
}

void Model::Draw()
{
	DrawModel();
}

void Model::UpdateAnimation()
{
	animationFrame++;
	float anim_total_frame = MV1GetAnimTotalTime(modelHandle, animKind);
	if (animationFrame >= anim_total_frame)
	{
		// ÉãÅ[Év
		animationFrame = 0;
	}
}

void Model::UpdateFrontVector()
{
	float rad = DegToRad(degreeAngle.y);
#if 0
	pos.x += sinf(rad) * -1.0f;
	pos.z += cosf(rad) * -1.0f;
#else
	VECTOR front = VGet(0, 0, -1.0f);

	frontVector.x = cos(rad) * front.x + sin(rad) * front.z;
	frontVector.y = 0.0f;
	frontVector.z = -sin(rad) * front.x + cos(rad) * front.z;
#endif
}

void Model::DrawModel()
{
	MV1DetachAnim(modelHandle, 0);
	MV1AttachAnim(modelHandle, animKind);
	MV1SetAttachAnimTime(modelHandle, 0, animationFrame);

	MV1SetPosition(modelHandle, pos);
	MV1SetScale(modelHandle, scale);
	VECTOR rad_angle = VGet(
		DegToRad(degreeAngle.x),
		DegToRad(degreeAngle.y),
		DegToRad(degreeAngle.z)
	);
	MV1SetRotationXYZ(modelHandle, rad_angle);

	MV1DrawModel(modelHandle);
}