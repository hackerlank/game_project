/*****************************************************************
* Copyright (c)2007，上海美峰数码科技有限公司
* All rights reserved.
* 
* 文件名称：define.h
* 文件标识：
* 摘    要：用来定义一些基本的数据类型和常数
* 
* 当前版本：1.0
* 作    者：lsj
* 完成日期：2007-12-26
*
******************************************************************/
#ifndef _YLH_DEFINE_H_
#define _YLH_DEFINE_H_

#include "ace/Basic_Types.h"

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>


typedef	 unsigned char    uint8_t;
typedef	 unsigned short   uint16_t;
typedef  unsigned int     uint32_t;

typedef  ACE_UINT64       EntityId;
typedef  uint32_t         RoleId; 

typedef  ACE_UINT64       uint64_t;
typedef  ACE_INT64        int64_t;


//testcode
#define  GAME_SERVER_ACCEPT_PORT    11110

#define  ROLE_SERVER_ACCEPT_PORT    11112
#define  ROLE_SERVER_CONNECT_PORT    11110

#endif  //_YLH_DEFINE_H_
