/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _INERTIA_MISSILE_H_
#define _INERTIA_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Ship.h" 

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
    Sprite * sprite;                            // sprite do m�ssil
    Vector   speed;                             // velocidade do m�ssil
    Vector   Rup;                               // vetor para rebater o missel
    Vector   Rdown;                             // vetor para rebater o missel
    Vector   Rleft;                             // vetor para rebater o missel
    Vector   Rright;                            // vetor para rebater o missel
    bool     Rebound;                           // variavel que controla se o missel foi rebatido

public:
    Missile(Ship * ship);                       // construtor
    ~Missile();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
}; 

// ------------------------------------------------------------------------------

#endif