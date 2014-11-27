

#include "Game_Server.h"
#include "ace/OS_main.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
    Game_Server game_server;
    game_server.init();

    game_server.run();

    game_server.close();


    return 0;
};