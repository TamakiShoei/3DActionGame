#ifndef CAMERA_H_
#define CAMERA_H_

#include <DxLib.h>
#include "Common.h"
#include "Object.h"

class Camera
{
public:
	// コンストラクタ
	Camera() : 
		pos(VGet(0, 0, 0)),
		targetPos(VGet(0, 0, 1.0f)),
		parameter(),
		mode(CameraMode::CameraModeTps)
	{
	}

	CameraMode GetMode()
	{
		return mode;
	}

	// モード切替
	void ChangeMode(CameraMode next_mode)
	{
		mode = next_mode;
	}

	// パラメターの更新
	void UpdateParameter(UpdatedCameraParameter& init_parameter)
	{
		parameter = init_parameter;
	}

	// 更新
	void Update();

private:

	// TPS用カメラ座標の計算
	void CalculateTpsCameraPos(VECTOR& out_vector);

private:
	CameraMode mode;					// モード
	UpdatedCameraParameter parameter;	// パラメータ

	VECTOR pos;							// 座標
	VECTOR targetPos;					// 注視点
};

#endif
