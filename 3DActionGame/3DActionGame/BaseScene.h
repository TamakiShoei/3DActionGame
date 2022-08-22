#ifndef BASE_SCENE_H
#define BASE_SCENE_H

class BaseScene
{
public:

	BaseScene();
	virtual ~BaseScene();

	virtual void MainScene() = 0;
	virtual void Draw() = 0;

protected:
	virtual void InitScene() = 0;
	virtual void RunScene() = 0;
	virtual void FinishScene() = 0;

	enum StepKind
	{
		INIT,
		RUN,
		FINISH
	};

protected:
	StepKind current_step;
};

#endif