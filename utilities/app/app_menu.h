/**
 * Copyright 2018 - 2019 HITSIC
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * @file 	:	app_menu.h
 * @author  :	Chekhov Mark/马奇科(qq:905497173)
 * @version :	v0.1.0-beta.1
 * @date 	:	v0.1.0-beta.1 2019.10.28
 * 
 * @note    :   依赖库：drv_ftfx_flash、drv_button、drv_disp_ssd1306
                依赖库必须先初始化。
 * @note 	:	预发布版本，代码不完整，仅供学习。
 */

#pragma once
#ifndef _APP_MENU_H_
#define _APP_MENU_H_
#include "stdafx.h"

#include "app_menu_def.h"
#include "app_menu_button.h"
#include "app_menu_nvm.h"
#include "app_menu_type.h"

/*! @addtogroup app_menu */
/*! @{ */

/*! @file */

/** @brief : 软件版本 */
#define APP_MENU_VERSION (HITSIC_MAKE_VERSION(0u, 1u, 0u))

/**
 * @brief : 函数调用宏定义。
 * 这些定义主要是为了简化代码。
 */

#ifdef __cplusplus
extern "C"
{
#endif



	/**************************************
 ************ 菜单顶层操作接口 **********
 **************************************/

	/**
	  * @brief : 菜单全局初始化。
	  * 该函数会初始化必要的变量，创建根菜单和其他最基本的菜单列表和菜单项。
	  *
	  * @param  {void} undefined :
	  */
	void MENU_Init(void);

	/**
	 * @brief : 初始化各菜单列表和菜单项。
	 * 注意：该函数在外部定义，不需初始化最基本的菜单列表和菜单项。该函数需要用户手动调用。
	 * TODO: 究竟手动调用还是自动调用？或者干脆不定义这个函数，让用户自己去写？
	 *
	 * @param  {void} undefined :
	 */
	void MENU_DataSetUp(void);

	/**
	 * @brief : 打印屏幕。
	 * 该函数是整个菜单的屏幕打印入口，将自动根据菜单的状态打印屏幕。
	 *
	 * @param  {void} undefined :
	 */
	void MENU_PrintDisp(void);

	/**
	 * @brief : 响应按键操作。
	 * 该函数是整个菜单的按键响应入口，将自动根据菜单的状态调用按键响应函数。
	 * 该函数不会更新屏幕显示。
	 *
	 * @param  {void} undefined :
	 */
	void MENU_KeyOp(menu_keyOp_t * const _op);

	/**
	 * @brief : 保存整个菜单到NVM。
	 *
	 * @param  {int32_t} _region :
	 */
	void MENU_Data_NvmSave(int32_t _region);

	/**
	 * @brief : 从NVM读取整个菜单。
	 *
	 * @param  {int32_t} _region : 所选择的局部存储区。
	 */
	void MENU_Data_NvmRead(int32_t _region);

	/**
	 * @brief : 将一个局部存储区的数据拷贝到另一个局部存储区。
	 *
	 * @param  {int32_t} _srcRegion : 源存储序号。
	 * @param  {int32_t} _dstRegion : 目的存储区序号。
	 */
	void MENU_Data_NvmCopy(int32_t _srcRegion, int32_t _dstRegion);
	void MENU_Data_NvmCopy_boxed(void);

	/**
	 * @brief : 读取NVM状态标志。
	 *
	 * @return {int32_t}        : 返回读取到的状态标志。
	 */
	int32_t MENU_GetNvmStatus(void);

	/**
	 * @brief : 设置NVM状态标志。
	 *
	 * @param  {int32_t} _status : 要设置的状态标志。
	 */
	void MENU_SetNvmStatus(int32_t _status);

#ifdef __cplusplus
}
#endif

/*! @} */

#endif // ! _APP_MENU_H_
