/**********************************************************************************
// Debris (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // objetos do jogo
#include "Animation.h"                      // anima��o de sprites
#include "Particles.h"                      // anima��o de sprites

#include <random>
using std::random_device;
using std::mt19937;
using Rnd = std::uniform_real_distribution<float>;
// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
    Particles * RockGen;                    // anima��o
    Animation* anim;
    TileSet* tileset;
    random_device rd;                       // gerador de n�mero aleat�rio
    mt19937 mt{ rd() };                     // gerador mersenne twister
    Rnd RandAngle{ 0.0f, 359.0f };          // �ngulo aleat�rio
    Rnd RandParticles{ 90.0f, 180.0f };      // �ngulo aleat�rio
    
public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualiza��o
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Debris::Draw()
{ RockGen->Draw(Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

#endif