
#ifndef _YLH_DEFINE_H_
#define _YLH_DEFINE_H_

#include "ace/Basic_Types.h"

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
