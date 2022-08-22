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
		// 待機
		if (animKind == MikuAnimKind::Run ||
			animKind == MikuAnimKind::Skill)
		{
			animKind = MikuAnimKind::Idle;
			animationFrame = 0;
		}
	}

	// 移動方向が決まったら、rayを作成する
	VECTOR ray = pos;
	VECTOR startPos;
	VECTOR endPos;
	VECTOR crossPos;
	// rayの開始位置 => 現在の座標 + 移動ベクトル + 上へのオフセット(0, 1.0f, 0)
	ray = VAdd(ray, vector);
	ray = VAdd(ray, VGet(0, 1.0f, 0));
	startPos = ray;
	// endの位置 => 開始位置から下に1000
	ray = VSub(ray, VGet(0, 1000.0f, 0));
	endPos = ray;
	// CollisionManagerのLineAndStageで判定
	// 当たりの場合 => pos に交差位置を代入
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
		Tpsカメラで毎フレーム必要な情報
			注視点
			オブジェクトの向きベクトル

			※回転による実装で必要
			Y軸角度
			X軸角度
	*/
	cameraParam.targetPos = pos;
	cameraParam.frontVector = frontVector;
	cameraParam.yawAngle = degreeAngle.y;

	// 回転バージョンの角度調整用
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
