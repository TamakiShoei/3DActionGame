#ifndef MODEL_H_
#define MODEL_H_

#include "Object.h"

/*
	3Dモデルを所定の位置に描画するを目的としたクラス
*/
class Model : public Object
{
public:
	Model(int handle, VECTOR init_pos) :
		Object(init_pos),
		modelHandle(handle),
		animationFrame(0),
		animKind(MikuAnimKind::Idle),
		frontVector(VGet(0, 0, 0))
	{
		MV1AttachAnim(modelHandle, 0);
	}

	void Update() override;
	void Draw() override;

protected:
	void UpdateAnimation();

	// 進行方向の更新関数
	void UpdateFrontVector();

	void DrawModel();

#if defined(DEBUG)
	void DrawCollider();
#endif

protected:
	int modelHandle;
	int animationFrame;
	int animKind;
	VECTOR frontVector;
};

#endif
