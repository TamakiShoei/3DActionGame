#include <math.h>
#include "CameraManager.h"
#include "CollisionManager.h"
#include "Player.h"

void Player::Update()
{

	if (CheckHitKey(KEY_INPUT_LEFT) && animKind != MikuAnimKind::Skill)
	{
		degreeAngle.y -= 1.0f;
		UpdateFrontVector();
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) && animKind != MikuAnimKind::Skill)
	{
		degreeAngle.y += 1.0f;
		UpdateFrontVector();
	}

	VECTOR vector = VGet(0, 0, 0);

	if (CheckHitKey(KEY_INPUT_UP) && animKind != MikuAnimKind::Skill)
	{
		vector = frontVector;
		vector.y = 0.0f;

		if (animKind == MikuAnimKind::Idle)
		{
			animKind = MikuAnimKind::Run;
			animationFrame = 0;
		}
	}
	else if(CheckHitKey(KEY_INPUT_F))
	{
		animKind = MikuAnimKind::Skill;
	}
	else
	{
		// �ҋ@
		if (animKind == MikuAnimKind::Run ||
			animKind == MikuAnimKind::Skill)
		{
			animKind = MikuAnimKind::Idle;
			animationFrame = 0;
		}
	}

	// �ړ����������܂�����Aray���쐬����
	VECTOR ray = pos;
	VECTOR startPos;
	VECTOR endPos;
	VECTOR crossPos;
	// ray�̊J�n�ʒu => ���݂̍��W + �ړ��x�N�g�� + ��ւ̃I�t�Z�b�g(0, 1.0f, 0)
	ray = VAdd(ray, vector);
	ray = VAdd(ray, VGet(0, 1.0f, 0));
	startPos = ray;
	// end�̈ʒu => �J�n�ʒu���牺��1000
	ray = VSub(ray, VGet(0, 1000.0f, 0));
	endPos = ray;
	// CollisionManager��LineAndStage�Ŕ���
	// ������̏ꍇ => pos �Ɍ����ʒu����
	if (CollisionManager::Instance()->LineAndStage(startPos, endPos, crossPos) == true)
	{
		pos = crossPos;
	}

	UpdateCamera();
	UpdateAnimation();
}

void Player::Draw()
{
	DrawModel();

#if defined(DEBUG)
	DrawCollider();
#endif
}

void Player::InitCamera()
{
	cameraParam.targetPos = pos;
	cameraParam.offsetPos = VGet(0, 40.0f, 0);
	cameraParam.frontVector = frontVector;
	cameraParam.distance = 50.0f;
	cameraParam.yawAngle = degreeAngle.y;
	cameraParam.pitchAngle = -25.0f;
}

void Player::UpdateCamera()
{
	UpdateTpsCamera();
}

void Player::UpdateTpsCamera()
{
	/*
		Tps�J�����Ŗ��t���[���K�v�ȏ��
			�����_
			�I�u�W�F�N�g�̌����x�N�g��

			����]�ɂ������ŕK�v
			Y���p�x
			X���p�x
	*/
	cameraParam.targetPos = pos;
	cameraParam.frontVector = frontVector;
	cameraParam.yawAngle = degreeAngle.y;

	// ��]�o�[�W�����̊p�x�����p
	float speed = 1.0f;
	if (CheckHitKey(KEY_INPUT_T))
	{
		cameraParam.pitchAngle += speed;
	}
	else if (CheckHitKey(KEY_INPUT_V))
	{
		cameraParam.pitchAngle -= speed;
	}

	CameraManager::Instance()->UpdateCameraParameter(cameraParam);
}
