#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"

BaseScene* SceneManager::pScene;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	if (pScene != nullptr)
	{
		delete pScene;
	}
}

void SceneManager::Change(Kind scene)
{
	if (pScene != nullptr)
	{
		delete pScene;
	}

	switch (scene)
	{
	case SceneManager::TITLE:
		pScene = new TitleScene();
		break;

	case SceneManager::GAME:
		pScene = new GameScene();
		break;
	}
}

void SceneManager::Update()
{
	pScene->MainScene();
}

void SceneManager::Draw()
{
	pScene->Draw();
}