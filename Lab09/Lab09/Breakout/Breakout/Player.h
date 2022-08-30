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

#ifndef _BREAKOUT_PLAYER_H_
#define _BREAKOUT_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"          // tipos específicos da engine
#include "Object.h"
#include "Sprite.h"
// ---------------------------------------------------------------------------------
class Player : public Object {
private:
	Sprite* sprite;
	float velX;
	float velY;
	bool ctrlLeft;
	bool ctrlRight;
public:
	Player(Image* img);
	~Player();

	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------

inline void Player::Draw() {
	sprite->Draw(x, y, z);
}
// ---------------------------------------------------------------------------------

#endif