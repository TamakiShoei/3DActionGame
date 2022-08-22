#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{

}

void TitleScene::MainScene()
{
	switch (current_step)
	{
	case BaseScene::INIT:
		InitScene();
		break;
	case BaseScene::RUN:
		RunScene();
		break;
	case BaseScene::FINISH:
		FinishScene();
		break;
	}
}

void TitleScene::InitScene()
{

}

void TitleScene::RunScene()
{

}

void TitleScene::FinishScene()
{

}

void TitleScene::Draw()
{

}

