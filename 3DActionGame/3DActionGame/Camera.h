#ifndef CAMERA_H_
#define CAMERA_H_

#include <DxLib.h>
#include "Common.h"
#include "Object.h"

class Camera
{
public:
	// �R���X�g���N�^
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

	// ���[�h�ؑ�
	void ChangeMode(CameraMode next_mode)
	{
		mode = next_mode;
	}

	// �p�����^�[�̍X�V
	void UpdateParameter(UpdatedCameraParameter& init_parameter)
	{
		parameter = init_parameter;
	}

	// �X�V
	void Update();

private:

	// TPS�p�J�������W�̌v�Z
	void CalculateTpsCameraPos(VECTOR& out_vector);

private:
	CameraMode mode;					// ���[�h
	UpdatedCameraParameter parameter;	// �p�����[�^

	VECTOR pos;							// ���W
	VECTOR targetPos;					// �����_
};

#endif
