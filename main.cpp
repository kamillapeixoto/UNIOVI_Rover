#include <QCoreApplication>
#include <brain.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  Brain principal;
  principal.comands();


    return a.exec();


}

/*
 * TIMER - CADA TS EXECUTA TODOS LOS IFS
 *
 * <?xml version="1.0" encoding="UTF-8"?>
 *
<Mando>
    <RoverX>2048</RoverX>
    <RoverY>2048</RoverY>                       <MotorL>vel</MotorL>   <MotorR>vel</MotorR>  PELYO
    <InterruptorUp>bool</InterruptorUp>
    <InterruptorDown>bool</InterruptorDown>        <Actuador>0(inferior)-2(reposo)-3(superior)</Actuador> DAVID
    <ActuatorUp>1</ActuatorUp>
    <ActuatorDown>1</ActuatorDown>                  <moveStp>1</moveStp> <dirStp>1</dirStp> PHIL
    <J1Button>1</J1Button>  ***************************************
    <CameraX>2048</CameraX>
    <CameraY>2048</CameraY>                     <moveTilt>0</moveTilt> <dirTilt>0</dirTilt> <movePan>1</movePan> <dirPan>0</dirPan> PHIL
    <ManualActuator>1</ManualActuator>************************************
    <AutoActuator>1</AutoActuator>*************************
    <LED>1</LED>                                Activar salida PIN BBB
    <QR_Scanner>1</QR_Scanner>******************************************
    <Switch_camera>1</Switch_camera>            Cambiar cámara      Enviar imagen a mando y GUI
</Mando>

 *
 */
