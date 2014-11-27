
#include "YLH_Sock_Handler.h"
#include <sstream>  //testcode

#include "YLH_Server.h"
#include "YLH_Net_Manager.h"

static const int timer_id = -1;


YLH_Sock_Handler::YLH_Sock_Handler()
:m_owner_net_manager(NULL)
,m_port(0)
{
}

YLH_Sock_Handler::~YLH_Sock_Handler()
{
    m_owner_net_manager = NULL;
    m_port = 0;
}

YLH_Server* YLH_Sock_Handler::get_owner_server()
{
    if (NULL != m_owner_net_manager)
    {
        return m_owner_net_manager->get_owner_server();
    }

    return NULL;
}

void YLH_Sock_Handler::set_owner_net_manager(YLH_Net_Manager* owner_net_manager)
{
    m_owner_net_manager = owner_net_manager;
}

YLH_Net_Manager* YLH_Sock_Handler::get_owner_net_manager()
{
    return m_owner_net_manager;
}

void YLH_Sock_Handler::set_port(int port)
{
    m_port = port;
} 

int  YLH_Sock_Handler::get_port()
{
    return m_port;
}

int YLH_Sock_Handler::open( void * p/*= 0*/ )
{
    super::open(p);

    peer().enable(ACE_NONBLOCK);
    
    //reactor()->register_handler(this, ACE_Event_Handler::READ_MASK | WRITE_MASK | SIGNAL_MASK);
    reactor()->register_handler(SIGINT, this);
    return 0;
}

int YLH_Sock_Handler::handle_input( ACE_HANDLE fd /* = ACE_INVALID_HANDLE */ )
{
    printf("YLH_Sock_Handler::handle_input\n");

    static const size_t RECV_BUF_SIZE = 1024 * 4;

    static int  get_length = 0;

    // local receive buffer.
    char recvbuf[RECV_BUF_SIZE] = { 0 };

    // If has prev message then prepend to local receive buffer.

    // actually received size.
    int s_recv = 0;

    // read socket buffer as much as possible.

    // read data into local buffer from socket.

    //s_recv = this->peer().recv(recvbuf, RECV_BUF_SIZE);
    //if (-1 == s_recv)
    //{
    //    return -1;
    //}

    for (; (s_recv = this->peer().recv(recvbuf, RECV_BUF_SIZE)) > 0;)
    {
        printf("recv:%s\n", recvbuf);
        get_owner_server()->collect_msg(recvbuf, s_recv);
        return 0;
    }

    if (s_recv == 0)
    {
        //close socket
        return -1;
    }

    int last_err = ACE_OS::last_error();

    if (s_recv == -1 &&  last_err == EWOULDBLOCK) 
    {
        return 0;
    }
    return -1;
}

int YLH_Sock_Handler::handle_close( ACE_HANDLE /*= ACE_INVALID_HANDLE*/, ACE_Reactor_Mask /*= ACE_Event_Handler::ALL_EVENTS_MASK*/ )
{
    printf("YLH_Sock_Handler::handle_close\n");
    if (NULL != get_owner_net_manager())
    {
        get_owner_net_manager()->del_socket_handler(this);
    }
    return 0;
}
