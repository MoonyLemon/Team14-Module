#ifndef D_KV10Z7_APP_MENU_PORT_H_
#define D_KV10Z7_APP_MENU_PORT_H_

#include "inc_stdlib.h"
#include "hitsic_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define HITSIC_USE_APP_MENU (1U)

#if defined(HITSIC_USE_APP_MENU) && (HITSIC_USE_APP_MENU > 0)

/**
 * @brief : 菜单调试输出开关
 * 编译选项为release时无效。
 */
#define HITSIC_MENU_PRINT_ENABLE (1u)
#define HITSIC_MENU_PRINT_VERBOSE_ENABLE (1u)
#define HITSIC_MENU_PRINT_WARNING_ENABLE (1u)

/**
 * @brief : 菜单调试输出语句定义。
 * 编译选项为release时始终为空。
 */
#if defined(DEBUG) && defined(HITSIC_MENU_PRINT_ENABLE) && (HITSIC_MENU_PRINT_ENABLE != 0u)
#define HITSIC_MENU_PRINTF(...) (printf(__VA_ARGS__))
#else
#define HITSIC_MENU_PRINTF(...)
#endif // ! DEBUG

/** @brief : 根菜单最大容量 */
#define HITSIC_MENU_ROOT_SIZE 35 //maxium size of Root Menu

/*! @name 启用自带的按键处理 */
/*@{*/
/** @brief : 是否使用菜单自带的按键事件管理 */
#define HITSIC_MENU_USE_BUTTON (1U)
/*@}*/

#if defined(HITSIC_MENU_USE_BUTTON) && (HITSIC_MENU_USE_BUTTON > 0)

/** @brief : 菜单使用的五向按键初始化。每组数据前两个是GPIO和Pin，其余数据为0。 */
#define HITSIC_MENU_BUTTON_5DIR_BSP_INIT  \
    {                                     \
        {                                 \
            RTEPIN_BOARD_BUTTON_OK_GPIO,  \
            RTEPIN_BOARD_BUTTON_OK_PIN,   \
            kPORT_InterruptOrDMADisabled, \
            0,                            \
            BUTTON_STAT_NONE,             \
            NULL,                         \
        },                                \
        {                                 \
            RTEPIN_BOARD_BUTTON_UP_GPIO,  \
            RTEPIN_BOARD_BUTTON_UP_PIN,   \
            kPORT_InterruptOrDMADisabled, \
            0,                            \
            BUTTON_STAT_NONE,             \
            NULL,                         \
        },                                \
        {                                 \
            RTEPIN_BOARD_BUTTON_DN_GPIO,  \
            RTEPIN_BOARD_BUTTON_DN_PIN,   \
            kPORT_InterruptOrDMADisabled, \
            0,                            \
            BUTTON_STAT_NONE,             \
            NULL,                         \
        },                                \
        {                                 \
            RTEPIN_BOARD_BUTTON_LF_GPIO,  \
            RTEPIN_BOARD_BUTTON_LF_PIN,   \
            kPORT_InterruptOrDMADisabled, \
            0,                            \
            BUTTON_STAT_NONE,             \
            NULL,                         \
        },                                \
        {                                 \
            RTEPIN_BOARD_BUTTON_RT_GPIO,  \
            RTEPIN_BOARD_BUTTON_RT_PIN,   \
            kPORT_InterruptOrDMADisabled, \
            0,                            \
            BUTTON_STAT_NONE,             \
            NULL,                         \
        },                                \
    }

#endif // ! HITSIC_MENU_USE_BUTTON

/**
 * @brief : 菜单消息调用所使用的中断信息。
 * 可以使用任何当前工程中未使用的中断。注意中断号和中断服务函数
 * 必须对应。优先级不可过高。
 */
#define HITSIC_MENU_SERVICE_IRQHandler (Reserved25_IRQHandler)
#define HITSIC_MENU_SERVICE_IRQn (Reserved25_IRQn)
#define HITSIC_MENU_SERVICE_IRQPrio (10u)

/**
 * @brief 屏幕打印接口
 */
#define HITSIC_MENU_DISPLAY_PRINT(row, col, str) (DISP_SSD1306_Print_F6x8(row, col, str))
//#define HITSIC_MENU_DISPLAY_PRINTF(row, col, fmt, ...) (OLED_Printf(row, col, fmt, __VA_ARGS__))
// #define HITSIC_MENU_DISPLAY_PRINTF(row,col,fmt,...)		\
    // 	{													\
    // 		char* buf = malloc(24*sizeof(char));			\
    // 		vsnprintf(buf,24,fmt,__VA_ARGS__);				\
    // 		HITSIC_MENU_DISPLAY_PRINT(row,col,buf);			\
    // 		free(buf);										\
    // 	}

/*! @name 启用非易失性存储支持 */
/*@{*/
/*! @brief 是否启用非易失性存储支持。目前仅支持块级存储接口。将于未来添加文件存储接口 */
#define HITSIC_MENU_USE_NVM (1U)
/*@}*/

#if defined(HITSIC_MENU_USE_NVM) && (HITSIC_MENU_USE_NVM > 0)

#include "drv_ftfx_flash.h"

/**
 * ********** NVM存储变量定义 **********
 */

//gl = global
//rg = region
//addr = address
//sect = sector
/**
 * @brief : 每个扇区包含的字节数
 */
#define HITSIC_MENU_NVM_SECTOR_SIZE (flash_sectorSize)
/**
 * @brief : 全局存储 Global Storage
 */
#define HITSIC_MENU_NVM_GLOBAL_SECT_CNT (2u)	///< 全局存储区占用的扇区数
#define HITSIC_MENU_NVM_GLOBAL_SECT_OFFSET (2u) ///< 全局存储区扇区偏移
/**
 * @brief : 局部存储 Region Storage
 */
#define HITSIC_MENU_NVM_REGION_CNT (3u) 					///< 局部存储区的数量
#define HITSIC_MENU_NVM_REGION_SECT_CNT  (4u)				///< 每个局部存储区占用的扇区数

#define HITSIC_MENU_NVM_AddressRead(addr, buf, byteCnt)		FLASH_AddressRead(addr, buf, byteCnt)	///< 读指定地址。必须返回表示操作是否成功的值。
#define HITSIC_MENU_NVM_SectorRead(sect, buf)		FLASH_SectorRead(sect, buf)						///< 读指定扇区。sect为扇区号，buf为缓存区。必须返回表示操作是否成功的值。
#define HITSIC_MENU_NVM_SectorWrite(sect, buf)		FLASH_SectorWrite(sect, buf)					///< 写指定扇区。sect为扇区号，buf为缓存区。必须返回表示操作是否成功的值。
#define HITSIC_MENU_NVM_RETVAL_SUCCESS				kStatus_FTFx_Success							///< flash接口操作成功的返回值。如果返回值不等一此值则表示操作失败，MENU_NVM接口将向上层报告错误（kStatus_Fail）。

#endif // ! HITSIC_MENU_USE_NVM

#endif // ! HITSIC_USE_APP_MENU

#ifdef __cplusplus
}
#endif

#endif // ! D_KV10Z7_APP_MENU_PORT_H_

