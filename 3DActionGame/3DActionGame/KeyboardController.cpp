#include "DxLib.h"
#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
	for (int i = 0; i < MaxKey; i++)
	{
		keyStates[i].IsPrevPushed = false;
		keyStates[i].IsCurrentPushed = false;
	}
}

void KeyboardController::Update()
{
	char buffer[256];

	if (GetHitKeyStateAll(buffer) != 0)
	{
		return;
	}

	for (int i = 0; i < MaxKey; i++)
	{
		keyStates[i].IsPrevPushed = keyStates[i].IsCurrentPushed;

	
		keyStates[i].IsCurrentPushed = buffer[i] != 0 ? true : false;
	}
}

bool KeyboardController::IsPushed(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (keyStates[key].IsPrevPushed == false &&
		keyStates[key].IsCurrentPushed == true)
	{
		return true;
	}

	return false;
}

bool KeyboardController::IsHeld(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (keyStates[key].IsPrevPushed == true &&
		keyStates[key].IsCurrentPushed == true)
	{
		return true;
	}

	return false;
}

bool KeyboardController::IsReleased(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (keyStates[key].IsPrevPushed == true &&
		keyStates[key].IsCurrentPushed == false)
	{
		return true;
	}

	return false;
}

