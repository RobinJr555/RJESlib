#include "console.h"

//命令池 维护一个静态命令结构体指针用于存储命令消息
static PtrConsoleCommandTypeDef s_arrCommandPoolBuff[MAX_COMMAND_NUMBER];
static unsigned char buff_len = 0; //已用的命令池个数


EnumConsoleErrorCode registerConsloeCmd(const PtrConsoleCommandTypeDef ptrConsolecmd)
{
	//入参检测
	if(NULL == ptrConsolecmd) return CONSOLE_UNKNOW_ERROR;
	if(MAX_COMMAND_NUMBER <= buff_len) return CONSOLE_BUFF_FULL;
	
	s_arrCommandPoolBuff[buff_len++] = ptrConsolecmd;
	return CONSOLE_NOMAL;
}

unsigned char getConsoleCmdCount(void)
{
	return buff_len;
}

