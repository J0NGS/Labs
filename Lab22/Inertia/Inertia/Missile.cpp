/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Missile.h"
#include "Inertia.h"
#include "Explosion.h"
#include "Ship.h"

// ------------------------------------------------------------------------------

Missile::Missile(Ship * ship)
{
    // cria sprite
    sprite = new Sprite("Resources/Missile.png");

    // bounding box
    BBox(new Point());

    // inicializa velocidade
    speed.RotateTo(ship->direction.Angle());
    speed.ScaleTo(12.0f);
    
    //inicializa vetores do rebound
    Rup.RotateTo(270);
    Rup.ScaleTo(22.0f);
    //
    Rdown.RotateTo(90);
    Rdown.ScaleTo(22.0f);
    //
    Rright.RotateTo(180);
    Rright.ScaleTo(22.0f);
    //
    Rleft.RotateTo(360);
    Rleft.ScaleTo(22.0f);

    // posi��o inicial do m�ssil
    MoveTo(ship->X() + 20 * cos(speed.Radians()), ship->Y() - 20 * sin(speed.Radians()));

    // rota��o do m�ssil
    RotateTo(ship->Rotation());
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // deslocamento padr�o
    float deltaT = 50 * gameTime;

    // move m�ssel usando o vetor
    Translate(speed.XComponent() * deltaT, -speed.YComponent() * deltaT);
    
    // destr�i m�ssil que sa� da tela
    if (X() > window->Width() || X() < 0 || Y() > window->Height() || Y() < 0)
    {
        if(Rebound){
        Inertia::audio->Play(EXPLOSION);
        Explosion * explo = new Explosion(Inertia::exploSet);
        explo->MoveTo(x, y);
        Inertia::scene->Add(explo, STATIC);
        Inertia::scene->Delete();
        }
        else {
            if (X() > window->Width()) {
                MoveTo(window->Width() - 2, Y());
                speed.Add(Rright);
            }
            if (X() < 0) {
                MoveTo(2, Y());
                speed.Add(Rleft);
            }
            if (Y() > window->Height()) {
                MoveTo(X(), window->Height() - 2);
                speed.Add(Rdown);
            }
            if (Y() < 0) {
                MoveTo(X(),2);
                speed.Add(Rup);
            }
            Rebound = true;
        }
    }
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
