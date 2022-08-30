/**********************************************************************************
// D3DBreakout (Código Fonte)
// 
// Criação:     26 Mar 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exercício sobre uso da classe Scene para gerenciar objetos
//
**********************************************************************************/

#include "Engine.h"
#include "Breakout.h"
#include "Resources.h"
#include "Player.h"
#include "Block.h"
#include "Ball.h"

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene * Breakout::scene = nullptr;

// ------------------------------------------------------------------------------

void Breakout::Init()
{
    // cena do jogo
    scene = new Scene();

    // carrega background
    backg = new Sprite("Resources/Background.jpg");

    // carregar imagens
    tile1 = new Image("Resources/Tile1.png");
    tile2 = new Image("Resources/Tile2.png");
    tile3 = new Image("Resources/Tile3.png");
    tile4 = new Image("Resources/Tile4.png");
    tile5 = new Image("Resources/Tile5.png");
    playerPng = new Image("Resources/Player.png");
    ballPng = new Image("Resources/Ball.png");
    
    // -----------------------------------------
    // posição dos blocos

    float line1 = 50.0f;
    float line2 = 80.0f;
    float line3 = 110.0f;
    float line4 = 140.0f;
    float line5 = 170.0f;

    // -----------------------------------------
    // linha 1 de blocos    

    Block * block;
    block = new Block(tile1);
    block->MoveTo(window->CenterX() - 350.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() - 270.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() - 190.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() - 110.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() - 30.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() + 50.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() + 130.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() + 210.0f, line1);
    scene->Add(block);

    block = new Block(tile1);
    block->MoveTo(window->CenterX() + 290.0f, line1);
    scene->Add(block);

    // -----------------------------------------
    // linha 2 de blocos    

    block = new Block(tile2);
    block->MoveTo(window->CenterX() - 350.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() - 270.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() - 190.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() - 110.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() - 30.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() + 50.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() + 130.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() + 210.0f, line2);
    scene->Add(block);

    block = new Block(tile2);
    block->MoveTo(window->CenterX() + 290.0f, line2);
    scene->Add(block);

    // -----------------------------------------
    // linha 3 de blocos    

    block = new Block(tile3);
    block->MoveTo(window->CenterX() - 350.0f, line3);
    scene->Add(block); 
    
    block = new Block(tile3);
    block->MoveTo(window->CenterX() - 270.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() - 190.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() - 110.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() - 30.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() + 50.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() + 130.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() + 210.0f, line3);
    scene->Add(block);

    block = new Block(tile3);
    block->MoveTo(window->CenterX() + 290.0f, line3);
    scene->Add(block);

    // -----------------------------------------
    // linha 4 de blocos    

    block = new Block(tile4);
    block->MoveTo(window->CenterX() - 350.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() - 270.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() - 190.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() - 110.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() - 30.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() + 50.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() + 130.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() + 210.0f, line4);
    scene->Add(block);

    block = new Block(tile4);
    block->MoveTo(window->CenterX() + 290.0f, line4);
    scene->Add(block);

    // -----------------------------------------
    // linha 5 de blocos    

    block = new Block(tile5);
    block->MoveTo(window->CenterX() - 350.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() - 270.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() - 190.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() - 110.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() - 30.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() + 50.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() + 130.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() + 210.0f, line5);
    scene->Add(block);

    block = new Block(tile5);
    block->MoveTo(window->CenterX() + 290.0f, line5);
    scene->Add(block);

    // -----------------------------------------
    // player

    Player* player;                                                                                                     //Ponteiro para player
    player = new Player(playerPng);                                                                                     //Construtor de player
    player->MoveTo(window->CenterX() - (playerPng->Width()/2), window->CenterY() * 2 - playerPng->Height() - 10);       //centralizando o player na parte inferior do eixo y e centralizado no eixo x
    scene->Add(player);                                                                                                 //adicionando o player na cena
    // -----------------------------------------

    // bola

    Ball* ball;
    ball = new Ball(ballPng);
    ball->MoveTo(window->CenterX(), window->CenterY() * 2 - playerPng->Height() - 20);
    scene->Add(ball);
}

// ------------------------------------------------------------------------------

void Breakout::Update()
{
    
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objetos da cena
    scene->Update();
   
} 

// ------------------------------------------------------------------------------

void Breakout::Draw()
{
    // desenha cena
    backg->Draw(0.0f, 0.0f, Layer::BACK);
    scene->Draw();
} 

// ------------------------------------------------------------------------------

void Breakout::Finalize()
{
    // apaga sprite
    delete backg;

    // apaga imagens
    delete tile1;
    delete tile2;
    delete tile3;
    delete tile4;
    delete tile5;

    delete scene;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura a janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Breakout");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);
    
    // inicia jogo
    int status = engine->Start(new Breakout());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

