//   Система автоматики винокура.
//   Проект центра открытого проектирования у Счастливчика https://LuckyCenter.ru
//   Версия 2.0 Release Candidate 19

#include "device_view.h"
#include "pid_config.h"
#include "adc.h"
#include "sd_card.h"
#include "display.h"
#include "sensors.h"
#include "heater.h"
#include "tft.h"
#include "setting.h"
#include "reflux_mode.h"
#include "distillation_mode.h"
#include "mashing_mode.h"
#include "pid_config.h"
#include "brewing_mode.h"
#include "misc.h"
#include "rmvk.h" //dym_

/* This code is for executing the interrupt in ESP8266.
   The main purpose is to solve the ISR not in RAM isssue.

  ISR Function : The interrupt pin [GPIO5 ] once changes state from HIGH to LOW
  ISR reads the value on GPIO4 and changes the state of the BUILTIN led based on the value read
*/



void loop() {

  HTTP.handleClient();
  switch (processMode.allow) {
    case 0: tftMenuLoop(); break;
    case 1: distillationLoop(); break;
    case 2: refluxLoop(); break;
    case 3: mashingLoop(); break;
    case 4: pidSetLoop(); break;
    //case 5: brewingLoop(); break;
    case 6: deviceViewLoop(); break;
  }

  if (processMode.allow < 3 || processMode.allow == 6) {
    adcLoop();
    stepApLoop();
  }
  //  if (powerType <= 1) heaterLoop();
  //  else { comHeaterLoop(); wifiHeaterLoop(); }
  switch (powerType) {
    case 1: { //Serial.println("TTR SELECT!")
        heaterLoop(); break;
      }// работает по режиму ТТР
    case 2: { //Serial.println("DIMMER SELECT!");
        comHeaterLoop(); wifiHeaterLoop(); break;
      } // работает по режиму плавной регулировки блока ЛБ и индукции
    case 3: {//RMVK ну и наконец выбор режима для регулятора Вольки
        //Serial.println("RMVK SELECT!")
        serialLoopRmvk();
        ; break;
      }
  } //switch

  sensorLoop();
  displayLoop();
  logfileLoop();

  yield();
}
