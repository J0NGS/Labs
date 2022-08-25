/**********************************************************************************
// Frogger (Código Fonte)
// 
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frogger.h"

// ---------------------------------------------------------------------------------

Frogger::Frogger()
{
    spriteFront = new Sprite("Resources/frog.png");
    spriteBack = new Sprite("Resources/frogBack.png");
    spriteLeft = new Sprite("Resources/frogLeft.png");
    spriteRight = new Sprite("Resources/frogRight.png");
    spriteController = new Sprite("Resources/frog.png");
    
    MoveTo(window->CenterX() - spriteFront->Width()/2.0f, 545.0f, Layer::FRONT);
    
    ctrlUp = true;
    ctrlDown = true;
    ctrlLeft = true;
    ctrlRight = true;
}

// ---------------------------------------------------------------------------------

Frogger::~Frogger()
{
    delete spriteController;
    delete spriteFront;
    delete spriteBack;
    delete spriteLeft;
    delete spriteRight;
}

// ---------------------------------------------------------------------------------

void Frogger::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        Translate(0.0f, -40.0f);
        ctrlUp = false;

    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }
    
    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        Translate(0.0f, 40.0f);
        ctrlDown = false;
        spriteBack->Draw(x, y, z);
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }

    // desloca sapo para esquerda
    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        Translate(-40.0f, 0.0f);
        ctrlLeft = false;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }
    

    // desloca sapo para direita
    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        Translate(40.0f, 0.0f);
        ctrlRight = false;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }
    
    // mantém sapo dentro da tela
    
    //eixo Y
    if (y < 65) // não sai embaixo da tela
        MoveTo(x, 65);

    if (y > 545)// não sai em cima da tela
        MoveTo(x, 545);
    //eixo X
    if (x > 760)// não sai a direita da tela
        MoveTo(760, y);

    if (x < 0)// não sai a esquerda da tela
        MoveTo(0, y);
}

// ---------------------------------------------------------------------------------
