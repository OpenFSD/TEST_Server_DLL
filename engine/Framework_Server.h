#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include "Server.h"
#include "Data.h"
#include "Input.h"
#include "Output.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"

namespace Server_Library
{
    class Framework_Server
    {
    public:
        Framework_Server();
        virtual ~Framework_Server();

        static void CreateHostingServer();
        static void Pop_Stack_OutputPraise();
        static void Push_Stack_InputPraise();

        static bool Get_Ack_InputAction_Capture();
        static class Server_Library::Server* Get_HostServer();
        static unsigned char Get_NumberOfCores();
        static bool GetState_Buffer_Input_ToWrite();
        static class WaitEnableWrite::WriteEnable* Get_WriteEnable_Stack_InputPraise();
        static class WaitEnableWrite::WriteEnable* Get_WriteEnable_Stack_OutputPraise();
        
        static void Set_Ack_InputAction_Capture(bool value);

        static __int16 Get_PraiseEventId();
        static void Set_PraiseEventId(__int16 value);
//===
        static float Get_Praise0_pitch();
        static float Get_Praise0_yaw();
        
        static void Set_Praise0_mousePos_X(__int16 value);
        static void Set_Praise0_mousePos_Y(__int16 value);
//===
    protected:

    private:
        static class Server* ptr_HostServer;
    };
}