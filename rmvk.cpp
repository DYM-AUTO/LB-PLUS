#include "rmvk.h"

String _response = "";
int ten = 1;

int sendPowerRmvk(int strPower)
{
  int setpower = strPower * 2.3;
  //Serial.println("%");
  //Serial.println(strPower);
 // Serial.println(setpower);
  if (strPower = 0) {
    sendATCommand("AT+VS=044", false);
    sendATCommand("AT+ON=0", false);
    ten = 0; 
    return 0;
  }
  else {
    if (ten = 0) {
      sendATCommand("AT+ON=1", false);
      ten = 1;
    }
    if (setpower < 40)
      sendATCommand("AT+VS=040", false);
    else {
      if (setpower < 100)
        sendATCommand("AT+VS=0" + String(setpower), false);
      else sendATCommand("AT+VS=" + String(setpower), false);
    }
  }


}


String sendATCommand(String cmd, bool waiting)                    // Функция отправки комманд модулю
{
  String _resp = "";                                              // Переменная для хранения результата
  Serial.println(cmd);                                            // Дублируем команду в монитор порта
  if (waiting) {                                                 // Если необходимо дождаться ответа...
    _resp = waitResponse();                                      // ... ждем, когда будет передан ответ
    Serial.println(_resp);                                        // Дублируем ответ в монитор порта
  }
  return _resp;                                                   // Возвращаем результат. Пусто, если проблема
}


String waitResponse()                                             // Функция ожидания ответа и возврата полученного результата
{
  String _resp = "";                                              // Переменная для хранения результата
  unsigned long _timeout = millis() + 1;                      // Переменная для отслеживания таймаута (10 секунд)
  do
  {

    if (millis() > _timeout )
    {
      Serial.println("Timeout...");
       break;
    }

    if (Serial.available())
    { _resp = Serial.readString();
      Serial.println(_resp);
       break;
    }
  }
  while (1) ;                                                     // Просто событие, которое не наступит

  return _resp;                                                   // ... возвращаем результат. Пусто, если проблема
}
