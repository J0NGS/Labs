/**********************************************************************************
// Frogger (Arquivo de Cabe�alho)
// 
// Cria��o:     19 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_FROGGER_H_
#define _FROGGER_FROGGER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"             // tipos espec�ficos da engine
#include "Object.h"            // interface de object
#include "Sprite.h"            // interface de sprites

// ---------------------------------------------------------------------------------

class Frogger : public Object
{
private:
    //sprites para o frogger
    Sprite * spriteFront;
    Sprite * spriteLeft;
    Sprite * spriteRight;
    Sprite * spriteBack;
    Sprite * spriteController;

    //controles de tecla do frogger
    bool ctrlUp;
    bool ctrlDown;
    bool ctrlLeft;
    bool ctrlRight;


public:
    Frogger();
    ~Frogger();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline

inline void Frogger::Draw()
{
    spriteController->Draw(x,y,z);

    
    
    if (ctrlUp == false) {
        spriteController = spriteFront;
    }
    
    /*if (ctrlDown == true && ctrlLeft == true && ctrlRight == true) {
        spriteFront->Draw(x, y, z);
    }*/
    
    if (ctrlLeft == false) {
        spriteController = spriteLeft;
    }
    
    if (ctrlRight == false) {
        spriteController = spriteRight;
    }
    
    if (ctrlDown == false) {
        spriteController = spriteBack;
    } 
}
// ---------------------------------------------------------------------------------

#endif