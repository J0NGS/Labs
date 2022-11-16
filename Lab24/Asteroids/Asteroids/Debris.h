/**********************************************************************************
// Debris (Arquivo de Cabeçalho)
// 
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                          // tipos específicos da engine
#include "Object.h"                         // objetos do jogo
#include "Animation.h"                      // animação de sprites
#include "Particles.h"                      // animação de sprites

#include <random>
using std::random_device;
using std::mt19937;
using Rnd = std::uniform_real_distribution<float>;
// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
    Particles * RockGen;                    // animação
    Animation* anim;
    TileSet* tileset;
    random_device rd;                       // gerador de número aleatório
    mt19937 mt{ rd() };                     // gerador mersenne twister
    Rnd RandAngle{ 0.0f, 359.0f };          // ângulo aleatório
    Rnd RandParticles{ 90.0f, 180.0f };      // ângulo aleatório
    
public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualização
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Debris::Draw()
{ RockGen->Draw(Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

#endif