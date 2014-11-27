


//服务器网络模块


#ifndef _YLH_NET_MANAGER_H_
#define _YLH_NET_MANAGER_H_

#include "YLH_Acceptor.h"
#include "YLH_Connector.h"

class YLH_Server;

class YLH_Net_Manager : public ACE_Event_Handler
{
public:
    YLH_Net_Manager(YLH_Server* owner_server);

    //getter setter
    void                add_socket_handler(YLH_Sock_Handler *handler);
    YLH_Sock_Handler*   get_socket_handler(ACE_HANDLE handle);
    YLH_Sock_Handler*   get_socket_handler(int port);
    YLH_Sock_Handler*   get_socket_handler(YLH_Sock_Handler* handler);
    void                del_socket_handler(YLH_Sock_Handler* handler);

    
    YLH_Server*         get_owner_server();
    ACE_Reactor*        get_Reactor();


    void add_accept_info(YLH_Acceptor_Info& Accept_info);
    void add_connect_info(YLH_Connect_Info& connect_info);



    //virtual function
    virtual int handle_timeout (const ACE_Time_Value &current_time,
        const void *act = 0);

    //总接口， 包含监听端口和连接端口
    void open();

    void run();


    //testcode
    void send_test_buff();

private:
    void open_all_connect();

    //int Open_Accept(YLH_Acceptor_Info& acceptor_info);
    //void add_connnection_info(YLH_Connect_Info& connect_info);
    


   

//private:
//    int Open_Connect(YLH_Connect_Info& connect_info);

private:
    YLH_Server*     m_owner_server;
    ACE_Reactor*    m_Reactor;

    YLH_Acceptor*   m_acceptor;
    YLH_Connector*  m_connector;


    //已连接的socket
    std::map<ACE_HANDLE, YLH_Sock_Handler*>     m_handler_list;

    //请求连接配置信息
    std::vector<YLH_Connect_Info>       m_connection_config_list;   //配置信息

    //监听配置信息
    YLH_Acceptor_Info                   m_acceptor_info;
};



#endif  //_YLH_NET_MANAGER_H_