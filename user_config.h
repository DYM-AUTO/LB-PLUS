#ifndef _user_config_h_
#define _user_config_h_

// ТЭН
#define		heater			16
// Если PWM_CH6 включен весь процесс ректификации или дистилляции - убрать комментарий следующей строки
//#define		Sign_of_Work
// GPIO для I2C
#define		pSDA			4
#define		pSCL			5
// GPIO для DS18B20
#define		DS_Pin			0
// Количество используемых датчиков температуры DS18B20 (максимум 8)
// Не трогать, программа сама определит количество подключенных датчиков
#define		DS_Cnt			8
// Количество выходных линий ШИМ
#define		PWM_Cnt			9
// Количество входных линий АЦП
#define		ADC_Cnt			4
// Соответствие каналов ADC
#define		AN0				0
#define		AN1				1
#define		AN2				2
#define		AN3				3
#define		thresholdAN0	2000
#define		thresholdAN1	8000
#define		thresholdAN2	2000
#define		thresholdAN3	2000
// Используем TFT дисплей или нет
#define		TFT_Display
// ТачСкрин
#define		intTouch		2
// GPIO для TFT
#define		TFT_DC_Lib		15
#define		TFT_CS_Lib		-1
#define		TFT_RES_Lib		-1
// Выбор линий CS для TFT, Touch и SD Card; Buzzer & Out_pwm
#define		TFT_RES_PRG	0
#define		SD_CS		7
#define		TFT_CS		15
#define		TOUCH_CS	12
#define		BUZ_VOL		13
#define		BUZ_OUT		14
#define		SIREN_OUT	1       // Активная пищалка с внутренним генератором
#define		PWM_CH1		11      // Клапан на головы
#define		PWM_CH2		10      // Клапан на тело
#define		PWM_CH3		9       // Клапан на воду
#define		PWM_CH4		8       // Клапан в ПБ
#define		PWM_CH5		2       // Управление 0 - 10 вольт
#define		PWM_CH6		3       // Дополнительная группа на дополнительные ТЭНы
#define		PWM_CH7		4       // ШИМ для х.з. пока чего
#define		PWM_CH8		5       // ШИМ для формирования напряжения + 15 вольт
#define		PWM_CH9		6       // Импульс повышающего напряжения на клапана
// Если клапан нормально закрыты ставим false
// Если клапан нормально открытый ставим true
#define		PWM_CH1_Invert	false
#define		PWM_CH2_Invert	false
#define		PWM_CH3_Invert	false
#define		PWM_CH4_Invert	false
// Дальше 5 строк не трогаем
#define		PWM_CH5_Invert	false
#define		PWM_CH6_Invert	false
#define		PWM_CH7_Invert	false
#define		PWM_CH8_Invert	false
#define		PWM_CH9_Invert	false
// Периодичность вывода температурного графика в секундах на экран
#define		Display_out_temp	15
// Периодичность записи лог.файла на SD
#define		SD_out_temp	10
// Какой используем датчик давления
//#define		Pressure_BMP085
#define		Pressure_BMP180
//#define		Pressure_BMP280
//#define		Pressure_BME280
// Вывод отладочной информации в UART
//#define		Debug_en

//DYM AUTO
#define   DYM_BUZ_ACT //если пищалка активная на плате на выходе 14
#define   DYM_PR //если установлена плата клапанов DYM_AUTO
#define   PWM2_CH1   1
#define   PWM2_CH2   2
#define   PWM2_CH3   3
#define   PWM2_CH4   4
#define   PWM2_CH5   5
#define   PWM2_CH6   6
#define   PWM2_CH7   7
#define   PWM2_CH8   8
#define   PWM2_CH9   9
#define   PWM2_CH10   10
#define   PWM2_CH11  11
#define   PWM2_CH12  12
#define   PWM2_CH13  13
#define   PWM2_CH14  14
#define   PWM2_CH15  15
#define   PWM2_CH16  16


#endif
