#ifndef BRAIN_H
#define BRAIN_H

#include <QObject>

#include <QFile> // necesario apenas para los testes
#include<QTextStream>

#include<MyXmlFunctions.h>

class Brain
{


private:
   QString tagCameraX = "CameraX"; // Necesario?

   QString fpgaMastil,  fpgaCam, esp32Atuador;

   QString botones; // Los datos XML enviados por el Mando y/o GUI
   const int neutralJS = 2048; // posición neutra del Joystick

public:
    Brain();

    //explicit Brain(QObject *parent = nullptr);

    void comands();

    // Para el futuro esas funciones poden retornar un dígito de verificación de errores
    void moverCamara();
    void moverMastil();
    void moverActuador();
};

#endif // BRAIN_H
