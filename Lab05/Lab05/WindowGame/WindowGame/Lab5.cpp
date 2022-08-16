/**********************************************************************************
// Lab 05
//
// Criação:     11 Ago 2022
// Atualização: 
// Compilador:  Visual C++ 2019
//
// Descrição:   Resolução do lab 05.
//              
//              
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;


class Lab5 : public Game {

private:
	int X1, X2;
	int Y1, Y2;
	int velX1, velX2;
	int velY1, velY2;
	HDC hdc;
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
	void TestCollision(int X1, int X2, int Y1, int Y2);

};

void Lab5::Init() {
	hdc = GetDC(window->Id());
	//inicializando coordenadas
	X1 = 10;
	Y1 = 10;
	X2 = 100;
	Y2 = 100;
	
	//inicializando velocidade
	velX1 = 5;
	velY1 = 5;
	velX2 = 5;
	velY2 = 5;

}

void Lab5::Update() {
	// update para mover a linha	
	
	X1 += velX1;
	Y1 += velY1;
	X2 += velX2;
	Y2 += velY2;
	// teste de colisão
	TestCollision(X1, X2, Y1, Y2);
	// movendo ponteiro para posical inicial da linha
	MoveToEx(hdc, X1, Y1, NULL);
}


void Lab5::Draw() {
	//desenhar a linha
	LineTo(hdc, X2, Y2);
}

void Lab5::Finalize() {
	ReleaseDC(window->Id(), hdc);
}

void Lab5::TestCollision(int X1, int X2, int Y1, int Y2) {
	if (X1 > window->Width())
		velX1 = -velX1;


	if (Y1 > window->Height())
		velY1 = -velY1;

	if (X1 < 0)
		velX1 = -velX1;

	if (Y1 < 0)
		velY1 = -velY1;

	if (X2 > window->Width())
		velX2 = -velX2;


	if (Y2 > window->Height())
		velY2 = -velY2;

	if (X2 < 0)
		velX2 = -velX2;

	if (Y2 < 0)
		velY2 = -velY2;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new Lab5());
}

// ----------------------------------------------------------------------------