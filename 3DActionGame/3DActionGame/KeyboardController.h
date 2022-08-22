#ifndef KEYBOARD_CONTROLLER_H_
#define KEYBOARD_CONTROLLER_H_

class KeyboardController
{
public:
	struct KeyState
	{
		// キー情報 => 押された or 押されていない
		bool IsPrevPushed;		// 1フレーム前のキー情報
		bool IsCurrentPushed;	// 今のフレームのキー情報
	};

	static const int MaxKey = 256;

	static KeyboardController* Instance()
	{
		static KeyboardController instance;
		return &instance;
	}

public:
	void Update();
	bool IsPushed(int key);
	bool IsHeld(int key);
	bool IsReleased(int key);

private:
	KeyboardController();

	KeyboardController(KeyboardController& instance) = delete;

private:
	KeyState keyStates[MaxKey];
};

#endif
