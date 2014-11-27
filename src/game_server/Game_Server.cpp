
#include "Game_Server.h"
#include "Sub_Thread.h"
#include "ace/Reactor.h"
#include "ace/Select_Reactor.h"
#include "ace/Reactor_Notification_Strategy.h"
#include "YLH_Net_Manager.h"

Game_Server::Game_Server()
{
    for (int i=0; i < 10; ++i)
    {
        Sub_Thread *new_thread = new Sub_Thread(get_Reactor());
        new_thread->thread_start();
        m_sub_thread_list.push_back(new_thread);
    }
    


    //new_thread->reactor()->register_handler(this, ACE_Event_Handler::READ_MASK | WRITE_MASK);


    //ACE_Time_Value send_buff_interval(5, 5*1000);
    //get_Reactor()->schedule_timer(this,
    //    reinterpret_cast<const void*>(SEND_BUFF_TIME_ID),
    //    send_buff_interval, send_buff_interval);
}

void Game_Server::collect_msg(char* recvbuf, int buff_size)
{
    for (std::vector<Sub_Thread*>::iterator iter = m_sub_thread_list.begin(); iter != m_sub_thread_list.end(); ++iter)
    {
        ACE_Message_Block* msg_block = new ACE_Message_Block(4*1024);
        msg_block->base(recvbuf, buff_size);
        (*iter)->putq(msg_block, NULL);

    }
}

void Game_Server::add_accept_config()
{

}

void Game_Server::add_connect_config()
{
    YLH_Connect_Info connector_info;
    connector_info.connect_port = (GAME_SERVER_ACCEPT_PORT);
    get_net_manager()->add_connect_info(connector_info);
}