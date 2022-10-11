/**********************************************************************************
// Cars (Código Fonte)
//
// Criação:     14 Jul 2019
// Atualização: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Carros adversários
//
**********************************************************************************/

#include "Cars.h"

// ---------------------------------------------------------------------------------

Cars::Cars() 
{
    // cria sprite para o carro
    sprite = new Sprite("Resources/WhiteCar.png");

    // deslocamentos no eixo X e Y
    deltaX = 0;
    deltaY = 0;

    // velocidade inicial do carro
    speed = 100;

    // --- ajuste a posição inicial do carro ---
    MoveTo(window->CenterX(), 246);
    // --- ajuste a escala inicial do carro ---
    ScaleTo(0.1);
}

// ---------------------------------------------------------------------------------

Cars::~Cars()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Cars::Update()
{
    // deslocamento varia com a escala e a velocidade
    deltaY = speed * scale * gameTime;

    // desloca carro
    Translate(deltaX, deltaY);

    // --- aumente a escala de acordo com a distância percorrida ---
    /* carro começa na posição y : 246 e percorre até a posição y : 473
    * logo esse carro está se deslocando 227 pixeis, e sua escala tem que
    * aumentar em 0.9 -> 0.9/227 = 0.0039
    */  
    
    ScaleTo(scale + deltaY * 0.004);
    if (scale > 1.0)
        ScaleTo(1);     //mantem a escala em 1 caso pase de 1

    // verifica a distância do carro para o início da pista
    if (y - 246 >= 500)
    {
        // restaura posição e escala do início da pista
        ScaleTo(0.1f);
        MoveTo(window->CenterX(), 246);
    }
}

// -------------------------------------------------------------------------------

void Cars::Draw()
{
    // --- desenha carro usando a escala definida ---
    sprite->Draw(x, y, Layer::UPPER, scale);

}

// -------------------------------------------------------------------------------