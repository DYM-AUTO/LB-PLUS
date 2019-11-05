//   Управление внешним силовым блоком с регулятором РМВ-К 
//    по протоколоу UART при помощи AT команд  by Mantis

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "user_config.h"
extern void serialLoopRmvk();
extern int sendPowerRmvk(int strPower);   
extern String sendATCommand(String cmd, bool waiting);       
extern String waitResponse();
