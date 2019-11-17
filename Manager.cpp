#include "Manager.h"

Manager::Manager(HWND hWnd)
{
	triangle = new Triangle();
	box = new Box(.5);
	sky = new SkyDome(hWnd, 32, 32, 500, L"assets/terrain/cielito.jpg");
	terrain = new Terrain(hWnd, L"assets/terrain/arid.jpg", L"assets/terrain/desert.jpg", 1000, 1000);
	camera = new Camera();
	gamepad = new GamePad(1);
	arrow = new Model("assets/models/arrow/arrow.obj", L"assets/models/arrow/arrow_mat.png");
	bow = new Model("assets/models/Bow/Bow.obj", L"assets/models/Bow/textures/i_stex12a_0.png");
	bird = new Model("assets/models/bird/Bird.obj", L"assets/models/bird/BirdSS00.png");
	statue = new Model("assets/models/statues/estatua.obj", L"assets/models/statues/SavePoint.0.png");
	key = new Model("assets/models/BossKey2/model.obj", L"assets/models/BossKey2/0.png");
	sword = new Model("assets/models/sword/sword2.obj", L"assets/models/sword/SwordA.png");
	rock = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	rock2 = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	rock3 = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	rock4 = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	rock5 = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	rock6 = new Model("assets/models/rock/rock.obj", L"assets/models/rock/f_iwa_1.png");
	inter = new Model("assets/models/room/cuarto.obj", L"assets/models/room/generic.jpg");
	stair = new Model("assets/models/room/escalera.obj", L"assets/models/room/generic2.jpg");
	cow = new Model("assets/models/cow/cow.obj", L"assets/models/cow/cow_00_0.png");
	thing = new Model("assets/models/Chickie.obj", L"assets/models/Image09660880_0965E7B0.png");
	castle = new Model("assets/models/hat_toride_model.obj", L"assets/models/hat_toride_color2.png");
	castle2 = new Model("assets/models/hat_toride_model.obj", L"assets/models/hat_toride_color2.png");
	castle3 = new Model("assets/models/hat_toride_model.obj", L"assets/models/hat_toride_color2.png");
	mountain = new Billboard(hWnd, L"assets/billboards/rocas.png", 6, 6, position);
	welcome = new Billboard(hWnd, L"assets/billboards/welcome.png", 6, 6, position);
	water = new Water(L"assets/water/water.bmp");
	Log::log("Finish Loading");
}
Manager::~Manager()
{
	if (triangle)
		delete triangle;
	if (box)
		delete box;
	if (terrain)
		delete terrain;
	if (camera)
		delete camera;
	if (gamepad)
		delete gamepad;
	if (key)
		delete key;
	if (sword)
		delete sword;
	if (arrow)
		delete arrow;
	if (bow)
		delete bow;
	if (bird)
		delete bird;
	if (statue)
		delete statue;
	if (cow)
		delete cow;
	if (castle)
		delete castle;
	if (castle2)
		delete castle2;
	if (castle3)
		delete castle3;
	if (thing)
		delete thing;
	if (rock)
		delete rock;
	if (rock2)
		delete rock2;
	 if (rock3)
		delete rock3;
	 if (rock4)
		delete rock4;
	 if (rock5)
		delete rock5;
	 if (rock6)
		delete rock6;
	if (inter)
		delete inter;
	if (stair)
		delete stair;
	if (mountain)
		delete mountain;
	if (welcome)
		delete welcome;
	if (sky)
		delete sky;
	if (water)
		delete water;
}
void Manager::Render(HDC hDC)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6, 0.6, 0.6, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Para usar el control:
	VerifyGamepad();
	camera->MoveForward(lY);
	camera->StrafeRight(lX);
	//Para usar el teclado:
	camera->MoveForward(position.y);
	camera->StrafeRight(position.x);
	//Giro con control:
	camera->RotateX(rY);
	camera->RotateY(-rX);
	camera->SetAltitudPosition(terrain->Surface(camera->GetPosition().x, camera->GetPosition().z) + 2);
	camera->Update();

	//skydome
	glPushMatrix();
	glTranslatef(0, 5, 0);
	sky->Draw();
	glPopMatrix();

	//terreno
	glPushMatrix();
	terrain->Draw();
	glPopMatrix();

	//castillo
	glPushMatrix();
	glTranslated(60, 25, -100);
	glScaled(60, 60, 60);
	castle->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(60, 16, -100);
	glScaled(30, 30, 30);
	inter->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(60, 1, -120);
	glScaled(10, 10, 10);
	stair->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(60, 1, -120);
	glScaled(10, 10, 10);
	key->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 8, -5);
	glScaled(10, 10, 10);
	glRotated(45, 0, 1, 0);
	statue->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 15, -5);
	glScaled(2, 2, 2);
	bird->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 1, 1);
	glTranslated(50, 1, -100);
	glRotated(-120, 0, 0, 1);
	sword->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 1, 1);
	glTranslated(70, 1, -100);
	bow->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(15, 15, 15);
	glTranslated(0, 0, -3);
	rock->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(10, 10, 10);
	glTranslated(10, 1, 0);
	rock2->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(10, 10, 10);
	glTranslated(3, 1, 1);
	rock3->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(30, 30, 30);
	glTranslated(5, 0, 0);
	rock4->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(10, 10, 10);
	glTranslated(0, 1, -9);
	rock5->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(20, 20, 20);
	glTranslated(7, 1, -2);
	rock6->Draw();
	glPopMatrix();


	glPushMatrix();
	glScaled(1, 1, 1);
	glTranslated(60, 1.5, -120);
	water->Draw();
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(10, 10, -100);
	glScaled(40, 40, 40);
	castle2->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(110, 10, -100);
	glScaled(40, 40, 40);
	castle2->Draw();
	glPopMatrix();*/

	//mono
	glPushMatrix();
	glTranslated(0, 2, -5);
	glScaled(1, 1, 1);
	glRotated(45, 0, 1, 0);
	thing->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(2, 2, 2);
	glTranslated(0, 1, 0);
	cow->Draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 1, 1);
	glTranslated(70, 2, -100);
	arrow->Draw();
	glPopMatrix();
	/*glPushMatrix();
	glTranslated(10, 20, -10);
	welcome->Draw(camera->GetPosition());
	glPopMatrix();*/
	/*tank->Draw();*/
	/*water->Draw();*/
	/*glPushMatrix();
	glTranslated(0, 0, -500);
	mountain->Draw(camera->GetPosition());
	glPopMatrix();*/

	/*if (aPress) {
		terrain->Draw();
	}
	*/

	SwapBuffers(hDC);
}

void Manager::VerifyGamepad()
{
	if (gamepad->IsConnected()) {
		lX = gamepad->GetState().Gamepad.sThumbLX / 32767;
		lY = gamepad->GetState().Gamepad.sThumbLY / 32767;
		rX = gamepad->GetState().Gamepad.sThumbRX / 32767;
		rY = gamepad->GetState().Gamepad.sThumbRY / 32767;

		if ((gamepad->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0) {
			aPress = !aPress;
			gamepad->Vibrate(32767, 32767);
		}
		else {
			gamepad->Vibrate(0, 0);
		}
	}
}

