#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	void MainScene();
	void Draw();
	
	void InitScene();
	void RunScene();
	void FinishScene();

private:
};

#endif 
