#ifndef PLAYER_H_
#define PLAYER_H_

#include "Model.h"

/*
	Modelクラスにキーコントロール機能を追加
*/
class Player : public Model
{
public:
	Player(int handle, VECTOR init_pos) :
		Model(handle, init_pos),
		cameraParam()
	{
		UpdateFrontVector();
		InitCamera();
	}

	~Player() override
	{
	}

	void Update() override;
	void Draw() override;

private:
	void InitCamera();
	void UpdateCamera();

	void UpdateTpsCamera();

private:
	UpdatedCameraParameter cameraParam;
};

#endif
