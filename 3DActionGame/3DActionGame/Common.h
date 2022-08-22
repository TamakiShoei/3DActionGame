#ifndef COMMON_H_
#define COMMON_H_

#include <DxLib.h>

// �x���@ => �ʓx�@
#define DegToRad(deg) (DX_PI_F / 180.0f * deg)

// 3D���f���̎��
enum ModelKind
{
	ModelKindNon = -1,
	Miku,
	Sphere,
	Island,
	MaxModelKind
};

// �����~�N�̃A�j���[�V�����̎��
enum MikuAnimKind
{
	Idle,
	Run,
	Skill
};

// �J�������[�h
enum CameraMode
{
	CameraModeTps,			// Tps�J����
	MaxCameraMode,
};

// �X�V�p�J�����p�����[�^
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

	VECTOR pos;			// �J�������W
	VECTOR offsetPos;	// �J�������W�p�I�t�Z�b�g
	VECTOR targetPos;	// �����_
	VECTOR frontVector;	// �^�[�Q�b�g�̐i�s����(TPS�p)
	float distance;		// �J��������	
	float yawAngle;		// ���[�̉�]�p�x
	float pitchAngle;	// �s�b�`�̉�]�p�x
};

#endif
