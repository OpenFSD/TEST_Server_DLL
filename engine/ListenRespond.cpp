#include "ListenRespond.h"
#include <cstddef>

namespace Server_Library
{
    class ListenRespond_Control* ListenRespond::ptr_ListenRespond_Control = NULL;

    ListenRespond::ListenRespond()
    {
        ptr_ListenRespond_Control = NULL;
    }

    ListenRespond::~ListenRespond()
    {
        delete ptr_ListenRespond_Control;
    }

    void ListenRespond::Initialise_Control()
    {
        ptr_ListenRespond_Control = new class Server_Library::ListenRespond_Control();
        while (ptr_ListenRespond_Control == NULL) { /* wait untill class constructed */ }
    }

    void ListenRespond::Thread_IO_ListenDistribute(unsigned char coreId, unsigned char number_Implemented_Cores)
    {
        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(coreId);
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(number_Implemented_Cores) != false)
        {
            // wait untill ALL threads initalised in preperation of system init.
        }
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(number_Implemented_Cores) == false)
        {
            switch (Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->Get_State_IO_Thread())
            {
            case true:
            {
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_Start(coreId);
                while (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded())
                {
                    switch (ConcurrentQue::Framework_ConcurrentQue::Get_State_LaunchBit())
                    {
                    case true:
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Push_Stack_Server_InputPraise(
                            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_Server_InputPraise(),
                            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble()
                        );
                        break;

                    case false:
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Pop_Stack_Server_InputPraise(
                            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(
                                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch()
                            ),
                            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_Server_InputPraise()
                        );
                        ConcurrentQue::Framework_ConcurrentQue::Request_Wait_Launch_ConcurrentThread(
                            Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch()
                        );
                        break;
                    }
                }
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_End(coreId);
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
                break;
            }
            case false:
            {
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_Start(coreId);
                while(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
                {
                    //TODO
                }
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_End(coreId);
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
                break;
            }
            }
        }
    }

    class ListenRespond_Control* ListenRespond::Get_ListenRespond_Control()
    {
        return ptr_ListenRespond_Control;
    }
}
