// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//Librerias
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <MMSystem.h>
#include <time.h>

using namespace std;

//Atributos enemigo
int enemyHP = 200;
string enemyName = "Jorge";
bool enemyIsAlive = true;
int enemyDMG;

//Atributos enemigo 2
int enemy2HP = 150;
string enemy2Name = "Carmen";
bool enemy2IsAlive = true;
int enemy2DMG;

//Atributos del personaje
int heroHP = 90;
int heroDMG;
string heroName;
bool heroIsAlive = true;

//Otros
string respuesta;
int enemyRand;
int espada = 50;
int magia = 35;
int punetazo = 40;
int tipoDMG;
int tipoDMG2;
int espadautilizable = 3;




void empezarElJuego() {
    cout << "El enemigo" << enemyName << " y " << enemy2Name << "ha aparecido\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre de tu heroe es " << heroName << "\n";
}

bool heroAlive() {
    if (heroHP <= 0) {
        cout << "GameOver";
        heroHP = 0;
        heroIsAlive = false;
        PlaySound(TEXT("Game_over_sonido.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return false;

    }
    else {
        return true;
    }
    }

void ataqueEnemy() {

    enemyDMG = 10 + rand() % (10 - 20);
    heroHP = heroHP - enemyDMG;
    cout << "El enemigo " << enemyName << " te ha atacado y te ha hecho " << enemyDMG << " de daño\n";
    cout << "Ahora tu vida ahora es de " << heroHP << "\n";
}


void ataqueEnemy2() {
    enemy2DMG = 10 + rand() % (10 - 20);
    heroHP = heroHP - enemy2DMG;
    cout << "El enemigo " << enemy2Name << " te ha atacado y te ha hecho " << enemy2DMG << " de daño\n";
    cout << "Ahora tu vida ahora es de " << heroHP << "\n";
}

void escogerDMG() {
    cout << "[1] Espada (Se puede utilizar " << espadautilizable << " veces)\n";
    cout << "[2] Magia\n";
    cout << "[3] Punetazo \n";
    cin >> tipoDMG;
    switch (tipoDMG) {
    case  1:
        if (espadautilizable == 0) {
            cout << "Este ataque no se puede utilizar mas, que ataque quieres escoger\n";
            cout << "[2] Magia\n";
            cout << "[3] Punetazo \n";
            cin >> tipoDMG2;
            espadautilizable = 0;
            if (tipoDMG2 == 2) {
                heroDMG = magia;
            }
            else if (tipoDMG2 == 3) {
                heroDMG = punetazo;
            }
        }
        heroDMG = espada;
        espadautilizable = espadautilizable - 1;

        break;
    case  2:
        heroDMG = magia;
        break;
    case  3:
        heroDMG = punetazo;
    }
    cout << "El DMG de tu personaje es " << heroDMG << "\n";

}
int main() {

   

    empezarElJuego();
    cout << "Cual quieres que sea tu tipo de DMG?\n";
    srand(time(NULL));



    while ((enemyIsAlive) || (enemy2IsAlive) && ((heroIsAlive))) {

        escogerDMG();


        cout << "A que enemigo quieres atacar (Jorge) o (Carmen)?";
        cin >> respuesta;
        if ((enemyIsAlive) || (enemy2IsAlive)) {
            if (respuesta == "Jorge") {
                enemyHP = enemyHP - heroDMG;

                if (enemyHP <= 0) {
                    cout << "Has humillado a " << enemyName << "\n";
                    enemyHP = 0;
                    enemyIsAlive = false;

                }
                else {
                    cout << "EL enemigo " << enemyName << " ahora tiene " << enemyHP << "HP\n";
                }
            }

            else if (respuesta == "Carmen") {
                enemy2HP = enemy2HP - heroDMG;

                if (enemy2HP <= 0) {
                    cout << "Has humillado a " << enemy2Name << "\n";
                    enemy2HP = 0;
                    enemy2IsAlive = false;

                }
                else {
                    cout << "EL enemigo " << enemy2Name << " ahora tiene " << enemy2HP << "\n";
                }
            }
        }
        if (enemyIsAlive && enemy2IsAlive) {
            enemyRand = rand() % 2;
            switch (enemyRand) {
            case (0):

                ataqueEnemy2();
                break;
            case (1):
                ataqueEnemy();
                break;
            }
            }else if (enemyIsAlive = false) {
                ataqueEnemy2();
            
            }
            else if (enemy2IsAlive = false)
            ataqueEnemy();
        heroAlive();
        }
    }

