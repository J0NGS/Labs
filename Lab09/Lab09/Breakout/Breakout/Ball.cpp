/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Block.h"
#include "Resources.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Image* img) {
	sprite = new Sprite(img);
	velX = 0.0f;
	velY = 0.0f;
	ctrlSpace = true;
	speedController = 0;
}

// ---------------------------------------------------------------------------------

Ball::~Ball() {
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update() {
	// desloca a bola
	
	if (ctrlSpace && window->KeyDown(VK_SPACE)) {					
		velX = 200;
		velY = -350;												//atira a bola pra cima com o espaço
		speedController = velY;
		ctrlSpace = false;
	}
	else if (window->KeyUp(VK_SPACE))
		ctrlSpace = true;
	
	// mantem a bola na tela
	if (y < 0)
		velY = -velY;
	if (y > 540 - sprite->Height())
		velY = -velY;
	if (x < 0)
		velX = -velX;
	if (x > 960 - sprite->Width())
		velX = -velX; 

	//checando colisão com o player
	
	/*if (y > 500) {
		velY = -velY;
	}*/

	Translate(velX * gameTime, velY * gameTime);
	
		

	//Remove o objeto quando sair de cena
	if (y > window->Height())
		Breakout::scene->Remove();
}

