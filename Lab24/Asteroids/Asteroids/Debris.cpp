/**********************************************************************************
// Debris (C�digo Fonte)
//
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    //anim = new Animation(Asteroids::debriSet, 0.060f, false);
    Generator rockgen;
    rockgen.imgFile = "Resources/Particle.png"; // arquivo de imagem
    rockgen.angle = RandAngle(mt);            // dire��o das estrelas
    rockgen.spread = 359;                     // espalhamento em graus
    rockgen.lifetime = 1.0f;                   // tempo de vida (em segundos)
    rockgen.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
    rockgen.percentToDim = 0.5f;              // desaparece ap�s 60% da vida
    rockgen.minSpeed = 40.0f;                // velocidade m�nima das part�culas
    rockgen.maxSpeed = 100.0f;                // velocidade m�xima das part�culas
    rockgen.color.r = 1.0f;                   // cor aleat�ria para part�cula
    rockgen.color.g = 1.0f;                   // cor aleat�ria para part�cula
    rockgen.color.b = 1.0f;                   // cor aleat�ria para part�cula
    rockgen.color.a = 1.0f;                   // transpar�ncia da part�cula
    
    RockGen = new Particles(rockgen);
    RockGen->Generate(posX, posY, RandParticles(mt));
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
    delete RockGen;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
    RockGen->Update(gameTime);
    
    if (RockGen->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------