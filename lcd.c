/*-----------------------------------------------------------*/
// LCD Simulator for FreeRTOS demo running on win32 MSVC

char lcdData[2][17] = { "                ",
					              "                " };
int charPos = 0;
int line = 0;

void lcdInit(void) {
	//hide cursor
	//printf("\e[?25l");

	charPos = 0;
	line = 0;
	for (int i = 0; i < 16; i++)
	{
		lcdData[0][i] = ' ';
		lcdData[1][i] = ' ';
	}
}

void lcdPrint(void) {
  //clear screen on MSVC
	printf("%s", "\033[2J\033[1;1H");
	//system("cls");
	printf("+----------------+\n|");
	printf(lcdData[0]);
	printf("|\n|");

	printf(lcdData[1]);
	printf("|\n");
	printf("+----------------+");
}

void lcdChar(char data) {

	if (charPos < 16) {
		lcdData[line][charPos] = data;
		charPos++;
	}
	lcdPrint();
}

void lcdStr(char data[]) {

	while (*data) {
		lcdChar(*data);
		data++;
	}
}

void lcdCommand(unsigned char cmd) {
	if ((cmd & 0xf0) == 0x80) {
		line = 0;
		charPos = cmd & 0x0f;
	}
	if ((cmd & 0xf0) == 0xC0) {
		line = 1;
		charPos = cmd & 0x0f;
	}
	if (cmd == 0x01) {
		lcdInit();
	}
}
/*-----------------------------------------------------------*/
