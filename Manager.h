#pragma once

#include <windows.h>
#include "Triangle.h"
#include "Box.h"
#include "Terrain.h"
#include "Camera.h"
#include "GamePad.h"
#include "Model.h"
#include "Log.h"
#include "Billboard.h"
#include "Water.h"
#include"SkyDome.h"
class Manager
{
private:
	double lX{ 0 };
	double lY{ 0 };
	double rX{ 0 };
	double rY{ 0 };
	bool aPress{ true };
	SkyDome* sky{ NULL };
	Triangle* triangle{ NULL };
	Box* box{ NULL };
	Terrain* terrain{ NULL };
	Camera* camera{ NULL };
	GamePad* gamepad{ NULL };
	Model* cow{ NULL };
	Model* castle{ NULL };
	Model* castle2{ NULL };
	Model* castle3{ NULL };
	Model* thing{ NULL };
	Model* arrow{ NULL };
	Model* bow{ NULL };
	Model* bird{ NULL };
	Model* statue{ NULL };
	Model* key{ NULL };
	Model* sword{ NULL };
	Model* inter{ NULL };
	Model* rock{ NULL };
	Model* rock2{ NULL };
	Model* rock3{ NULL };
	Model* rock4{ NULL };
	Model* rock5{ NULL };
	Model* rock6{ NULL };
	Model* stair{ NULL };
	Billboard* mountain{ NULL };
	Billboard* welcome{ NULL };
	Water* water{ NULL };
public:
	Vector3 position{ Vector3() };
	Manager(HWND hWnd);
	~Manager();

	void Render(HDC hDC);
	void VerifyGamepad();
};

