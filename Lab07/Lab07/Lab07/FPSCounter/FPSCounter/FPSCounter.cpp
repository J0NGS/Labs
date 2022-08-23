/**********************************************************************************
// FPSCounter
//
// Cria��o:     04 Mai 2014
// Atualiza��o: 10 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Ilustra utiliza��o da classe Timer e Game para controlar
//              a taxa de atualiza��o e desenho de quadros em um jogo.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include "Timer.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class FPSCounter : public Game
{
private:

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void FPSCounter::Init()
{
}

// ------------------------------------------------------------------------------

void FPSCounter::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();
}

// ------------------------------------------------------------------------------

void FPSCounter::Draw()
{
}

// ------------------------------------------------------------------------------

void FPSCounter::Finalize()
{
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//Criando Timer
	Timer TimerCounter;
	TimerCounter.Start();   //come�a a contagem do tempo 

	// cria engine
	Engine* engine = new Engine();

	// configura a janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("FPSCounter");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	//Para a contagem do tempo
	float TimePassed = TimerCounter.Elapsed();
	
	//Exibindo tempo que se passou na tela
	stringstream TimeText;	// Classe stringstream converte tudo para o tipo string 
	TimeText << "Tempo passado : " << TimePassed << std::endl;
	OutputDebugString(TimeText.str().c_str());	/*Fun��o de depura��o do visual studio para jogar o texto na tela,
												o tipo str() � invalido paraa fun��o OutPut, ent�o se chama o metodo c_str() para converter*/



	// configura dispositivo gr�fico
	//engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new FPSCounter());

	// destr�i a engine  
	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

