#ifndef CAMERA_MANAGER_H_
#define CAMERA_MANAGER_H_

#include "Common.h"
#include "Camera.h"

class CameraManager
{
public:
	static CameraManager* Instance()
	{
		static CameraManager instance;
		return &instance;
	}

	// Near‚ÆFar‚ÌXV
	static void SetNearAndFar(float n, float f)
	{
		SetCameraNearFar(n, f);
	}

public:
	void Update();

	void UpdateCameraParameter(UpdatedCameraParameter& param)
	{
		camera.UpdateParameter(param);
	}

private:
	CameraManager() :
		camera()
	{
	}

	CameraManager(CameraManager& instance) = delete;

private:
	Camera camera;	
};

#endif
