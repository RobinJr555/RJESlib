/**@file  	   console.h
* @brief       控制台组件头文件
* @details     包含控制台的配置参数、回调函数等
* @author      robinjr<robinjie555@163.com>
* @date        2020-7-27
* @version     V1.0
* @copyright   Copyright (c) 2013-2020  robinjr
**********************************************************************************
* @attention
* 编程语言：C(C99）
* 编程规范：参考华为C语言编程规范（2011）
* 硬件平台:平台无关 \n
* SDK版本：
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2020/07/27  <td>1.0      <td>robinjr   <td>创建初始版本
* </table>
*
**********************************************************************************
*/
#ifndef INCLUDE_BASE_CONSOLE_H
#define INCLUDE_BASE_CONSOLE_H

/*<!-- 配置conifg */
#define MAX_COMMAND_NUMBER 16 //< 最大命令个数
#default MAX_CONMMAND_LENGTH 64 //<命令的最大长度（字节）

/*结束配置-->*/

typedef void (*ptrCmdFunc)(u8 argc, char* argv[]);
typedef char (*ptrConsoleReadFunc)(char *);
typedef void (*ptrConsoleWriteFunc)(const char);

/**@struct ShellCommandTypeDef
* @brief 控制台命令结构体
*/

typedef struct tag_CONSOLE_COMMAND_TYPE_DEF
{
    const char *cmd;                                            //< shell命令名称
    ptrCmdFunc func;   	                                    	//< shell命令函数
    const char *desc;                                           //< shell命令描述
}ConsoleCommandTypeDef,*PtrConsoleCommandTypeDef;

typedef struct tag_CONSOLE_HANDLE_TYPE_DEF
{
	char buffer[MAX_CONMMAND_LENGTH];                      /**< shell命令缓冲 */
	
	
}ConsoleHandleTypeDef,*PtrConsoleHandleTypeDef;
/**@enum enumConsoleErrorCode
* @brief 错误码
*/
typedef enum tag_CONSOLE_ERROR_CODE
{
	CONSOLE_NOMAL = 0,
	CONSOLE_BUFF_FULL,
	CONSOLE_UNKNOW_ERROR,
}EnumConsoleErrorCode

/*<!-- Interface */

/**@brief 向命令池中注册控制命令
* @param[in]  ptrConsolecmd      需要注册的命令指针
* @return  函数执行结果
* - CONSOLE_NOMAL      		注册成功
* - CONSOLE_BUFF_FULL       注册池满
	CONSOLE_UNKNOW_ERROR	未知错误
*/
EnumConsoleErrorCode registerConsloeCmd(const PtrConsoleCommandTypeDef ptrConsolecmd);

/**@brief 获取当前的命令个数
* @return  当前的命令个数
*/
unsigned char getConsoleCmdCount(void);

#define CONSOLE_CMD(cmd,desc)              						\
	void ConsoleFunc##cmd(u8 argc, char* argv[]);				\
    static const char consoleCmd##cmd[] = #cmd;            		\
    static const char consoleDesc##cmd[] = #desc;           	\
    static const ConsoleCommandTypeDef consoleCommand##cmd ={	\
        consoleCmd##cmd,                   						\
        consoleDesc##cmd,                   					\
        &func     												\
    };                               							\         					
	static void ConsoleFunc##cmd(u8 argc, char* argv[])
	
	
#define REGISTER_CMD(cmd)	\
	registerConsloeCmd(&consoleCommand##cmd);





#endif
