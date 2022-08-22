#ifndef MODEL_H_
#define MODEL_H_

#include "Object.h"

/*
	3D���f��������̈ʒu�ɕ`�悷���ړI�Ƃ����N���X
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

	// �i�s�����̍X�V�֐�
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
