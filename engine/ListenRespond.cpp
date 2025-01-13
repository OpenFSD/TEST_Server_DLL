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
        switch (Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->GetFlag_IO_ThreadState())
        {
            case true://in
            {
            //for loop stack size
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Concurrent_Thread_Start(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_Control_Of_LaunchConcurrency(),
                    coreId,
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_GlobalForLaunchConcurrency()
                );
            //end loop
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
                break;
            }
            case false://out
            {
                if (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
                {
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Write_Start(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_WriteEnable_Control(),
                        coreId,
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_GlobalForWriteControl()
                    );

                    //TODO

                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Write_End(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_WriteEnable_Control(),
                        coreId,
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_GlobalForWriteControl()
                    );
                }
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
                break;
            }
        }
    }

    class ListenRespond_Control* ListenRespond::Get_ListenRespond_Control()
    {
        return ptr_ListenRespond_Control;
    }
}
