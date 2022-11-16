/**********************************************************************************
// Debris (Código Fonte)
//
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
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
    rockgen.angle = RandAngle(mt);            // direção das estrelas
    rockgen.spread = 359;                     // espalhamento em graus
    rockgen.lifetime = 1.0f;                   // tempo de vida (em segundos)
    rockgen.frequency = 0.000f;               // tempo entre geração de novas partículas
    rockgen.percentToDim = 0.5f;              // desaparece após 60% da vida
    rockgen.minSpeed = 40.0f;                // velocidade mínima das partículas
    rockgen.maxSpeed = 100.0f;                // velocidade máxima das partículas
    rockgen.color.r = 1.0f;                   // cor aleatória para partícula
    rockgen.color.g = 1.0f;                   // cor aleatória para partícula
    rockgen.color.b = 1.0f;                   // cor aleatória para partícula
    rockgen.color.a = 1.0f;                   // transparência da partícula
    
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