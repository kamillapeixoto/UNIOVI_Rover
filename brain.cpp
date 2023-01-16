#include "brain.h"

Brain::Brain()
{

}

void Brain::comands()
{

//Esa es la función central del Rover
    //Recibe los comandos del Rover en el formato XML y los envia a sus respectivos periféricos

    //Leer los comandos XML (del GUI o mando)
    // Esa línea sera substituida por una función de comunicacion TCP/IP (Mene):
    botones =
            "<RoverX>2048</RoverX>...\
             <RoverY>2048</RoverY>...\
            <CameraX>2048</CameraX>...\
            <CameraY>2048</CameraY>...\
            <J1Button>1</J1Button>...\
            <Switch_camera>1</Switch_camera>...\
            <ActuadorUP>1</ActuadorUP>...\
            <ActuadorDOWN>0</ActuadorDOWN>...\
            <MastilUP>1</MastilUP>...\
            <MastilDOWN>1</MastilDOWN>...\
            <AutoON>1</AutoON>...\
            <AutoOFF>1</AutoOFF>...\
            <LED>1</LED>...\
            <QR_Scanner>1</QR_Scanner>";



            moverCamara();
            moverMastil();
            moverActuador();

}

void Brain::moverCamara()
{

       //Movimiento horizontal
       int camXValue =  XmlGetInt(botones,"CameraX"); // Leer valor horizontal
       bool movePan  = 0; // = 1 para mover horizontalmente
       bool dirPan   = 0; // = 1 para mover para la derecha

       // Si el joystick no está en la posicion neutra, no se mueve
       movePan = (camXValue != neutralJS); // 2048 es la posición neutra del Joystick

        if (movePan)
        {
            dirPan = (camXValue > neutralJS); // Si movió para la derecha
        }


        //Movimiento vertical
        int camYValue =  XmlGetInt(botones,"CameraX"); // Leer valor vertical
        bool moveTilt = 0; // = 1 para mover verticalmente
        bool dirTilt  = 0; // = 1 para mover para arriba

        // Si el joystick no está en la posicion neutra
         moveTilt = (camYValue != neutralJS); // 2048 es la posición neutra del Joystick

         if (moveTilt)
         {
             dirTilt = (moveTilt > neutralJS); // Si movió para arriba
         }



        // Escribe los datos en una String
        fpgaCam = XmlCreateString("movePan",movePan) + XmlCreateString("dirPan",dirPan)+  XmlCreateString("moveTilt",moveTilt) + XmlCreateString("dirTilt",dirTilt);

        QTextStream qtOut(stdout);
        qtOut <<"Valor de Cam" << fpgaCam << "\n";

        //Enviar QString en un evento para FPGA (Phil)

}

void Brain::moverMastil()
{

    //Movimiento vertical
    int mastilUPValue    =  XmlGetInt(botones,"MastilUP"); // Leer boton para moverse arriba
    int mastilDOWNValue  =  XmlGetInt(botones,"MastilDOWN"); // Leer boton para moverse abajo
           // Boton pulsado ==  0

    bool moveStp = 0; // = 1 para mover el mastil
    bool dirStp  = 0; // = 1 para mover hasta arriba

    moveStp = !(mastilUPValue && mastilDOWNValue); // Si uno de los botones es pulsado

    if (moveStp)
    {
        dirStp = !mastilUPValue; // En caso de los dos botones seren pulsados al mismo tiempo, el mástil irá arriba.
    }

    // Escribe los datos en una String
    fpgaMastil = XmlCreateString("moveStp",moveStp) + XmlCreateString("dirStp",dirStp);

    QTextStream qtOut(stdout);
    qtOut <<"Valor del Mastil" << fpgaMastil << "\n";

     //Enviar QString en un evento para FPGA (Phil)

}

void Brain::moverActuador()
{
    //
    int ActuadorUPValue    =  XmlGetInt(botones,"ActuadorUP"); // Leer boton para moverse arriba
    int ActuadorDOWNValue  =  XmlGetInt(botones,"ActuadorDOWN"); // Leer boton para moverse abajo
           // Boton pulsado ==  0

    int Actuador = 1; // Dedo inferior avanza = 0, Reposo = 1, Dedo Superior avanza =2

    if ((ActuadorUPValue+ActuadorDOWNValue)!=1) // Si nada fue pulsado o si los dos botones fueran pulsados juntos
    {
        Actuador = 1; //Reposo
    } else if (!ActuadorUPValue) {
        Actuador = 2; // Dedo Superior avanza
    }else{
        Actuador = 0; //Dedo Inferior avanza
    }



    // Escribe los datos en una String
    esp32Atuador = XmlCreateString("Actuador", Actuador);

    QTextStream qtOut(stdout);
    qtOut <<"Valor del Actuador" << esp32Atuador << "\n";

     //Enviar QString via TCP/IP para ESP32 (David)
}

