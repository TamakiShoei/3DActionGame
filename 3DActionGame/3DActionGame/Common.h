#ifndef COMMON_H_
#define COMMON_H_

#include <DxLib.h>

// 度数法 => 弧度法
#define DegToRad(deg) (DX_PI_F / 180.0f * deg)

// 3Dモデルの種類
enum ModelKind
{
	ModelKindNon = -1,
	Miku,
	Sphere,
	Island,
	MaxModelKind
};

// 初音ミクのアニメーションの種類
enum MikuAnimKind
{
	Idle,
	Run,
	Skill
};

// カメラモード
enum CameraMode
{
	CameraModeTps,			// Tpsカメラ
	MaxCameraMode,
};

// 更新用カメラパラメータ
struct UpdatedCameraParameter
{
	UpdatedCameraParameter() :
		pos(VGet(0, 0, 0)),
		offsetPos(VGet(0, 0, 0)),
		targetPos(VGet(0, 0, 0)),
		frontVector(VGet(0, 0, 0)),
		distance(0.0f),
		yawAngle(0.0f),
		pitchAngle(0.0f)
	{
	}

	VECTOR pos;			// カメラ座標
	VECTOR offsetPos;	// カメラ座標用オフセット
	VECTOR targetPos;	// 注視点
	VECTOR frontVector;	// ターゲットの進行方向(TPS用)
	float distance;		// カメラ距離	
	float yawAngle;		// ヨーの回転角度
	float pitchAngle;	// ピッチの回転角度
};

#endif
