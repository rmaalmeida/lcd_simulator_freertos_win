// LCD Simulator example for FreeRTOS running under windows / MSVC

#ifndef LCD_H
	#define LCD_H
	void lcdInit(void);
	void lcdPrint(void);
	void lcdChar(char data);
	void lcdStr(char data[]);
	void lcdCommand(unsigned char cmd);
#endif
