#include "buzzer.h"

void initBuzzer(uint16_t duration)
{
  tickerSet.attach_ms(duration, deinitBuzzer);


#if defined DYM_BUZ_ACT //если объявлена пищалка платы DYM активная то включаем ее на определенный период (duration) высоким уровнем
  {
    pwm.setPWM(BUZ_OUT, 4096, 0);
  }
#else
  setPWM(BUZ_OUT, 0, 2048);
#endif
  // включить канал для сирены
  csOn(SIREN_OUT);
}

void deinitBuzzer()
{
  tickerSet.detach();
  setPWM(BUZ_OUT, 0, 4096);
  // выключить канал для сирены
  csOff(SIREN_OUT);

}
