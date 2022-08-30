/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"
#include "Breakout.h"
#include "Ball.h"
// ---------------------------------------------------------------------------------
Player::Player(Image* img) {
	sprite = new Sprite(img);
	velX = 0.0f;
	velY = 0.0f;
	ctrlLeft = true;
	ctrlRight = true;
}

// ---------------------------------------------------------------------------------

Player::~Player() {
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::Update() {
	
	//move o player para a esquerda
	if (ctrlLeft && window->KeyDown(VK_LEFT)) {
		velX = 200;
		Translate(-(velX * gameTime), 0);
	}

	//desloca o player para a direita
	if (ctrlRight && window->KeyDown(VK_RIGHT)) {
		velX = 200;
		Translate(velX * gameTime, 0);
	}

	//impede que a nave saia da tela
	if (x + sprite->Width() > window->Width())
		MoveTo(window->Width() - sprite->Width(), y)	//direita pegando a largura da tela - a largura da imagem do player
		;

	if (x < 0)
		MoveTo(0, y)									//para a esquerda pegando a coordenada 0 do eixo X
		;

}