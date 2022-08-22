#include <math.h>
#include <vector>
#include "DxLib.h"
#include "Common.h"
#include "CollisionManager.h"
#include "CameraManager.h"
#include "Player.h"
#include "Camera.h"
#include "KeyboardController.h"
#include "Goal.h"

int g_Handles[MaxModelKind];

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(1200, 800, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	ModelKind loadModels[] =
	{
		ModelKind::Miku,
		ModelKind::Sphere,
		ModelKind::Island
	};

	const char* loadFileName[] =
	{
		"Res/Miku/Miku.mv1",
		"Res/NormalSphere.mv1",
		"Res/Island/Island.mv1"
	};

	for (int i = 0; i < sizeof(loadModels) / sizeof(ModelKind); i++)
	{
		g_Handles[loadModels[i]] = MV1LoadModel(loadFileName[i]);
		if (g_Handles[loadModels[i]] < 0)
		{
			DxLib_End();
			return 0;
		}
	}

	if (CollisionManager::Instance()->EntryStageCollision(ModelKind::Island, 10, 10, 10) == false)
	{
		DxLib_End();
		return 0;
	}

	std::vector<Object*> objects;
	objects.push_back(new Player(g_Handles[ModelKind::Miku], VGet(0, 0, 0)));
	objects.push_back(new Goal(g_Handles[ModelKind::Sphere], 10, VGet(0, 0, 0)));
	objects.push_back(new Model(g_Handles[ModelKind::Island], VGet(0, 0, 0)));

	// 固定カメラの初期化
	UpdatedCameraParameter param;
	param.pos = VGet(10.0f, 10.0f, 0);
	param.targetPos = VAdd(param.pos, VGet(0.0f, 0.0f, 1.0f));
	CameraManager::Instance()->UpdateCameraParameter(param);

	CameraManager::SetNearAndFar(1.0f, 100000.0f);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		KeyboardController::Instance()->Update();

		for (Object* object : objects)
		{
			object->Update();
		}

		CameraManager::Instance()->Update();

		ClearDrawScreen();

		for (Object* object : objects)
		{
			object->Draw();
		}

		ScreenFlip();
	}

	for (Object* object : objects)
	{
		delete object;
	}

	for (int i = 0; i < ModelKind::MaxModelKind; i++)
	{
		MV1DeleteModel(g_Handles[i]);
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
