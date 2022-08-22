#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	void MainScene();
	void Draw();

	void InitScene();
	void RunScene();
	void FinishScene();
		
private:

};

#endif