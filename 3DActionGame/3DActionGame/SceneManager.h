#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "BaseScene.h"

class SceneManager
{
public:
	enum Kind
	{
		TITLE,
		GAME,
	};

	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}

	void Change(Kind scene);
	void Update();
	void Draw();

private:
	SceneManager();
	~SceneManager();

private:

	static BaseScene* pScene;
};

#endif