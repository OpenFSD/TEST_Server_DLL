#include "ListenRespond_Control.h"

namespace Server_Library
{
    bool ListenRespond_Control::state_IO_Thread = false;

    ListenRespond_Control::ListenRespond_Control()
    {
        state_IO_Thread = new bool(true);
    }
    ListenRespond_Control::~ListenRespond_Control()
    {

    }
    bool ListenRespond_Control::Get_State_IO_Thread()
    {
        return state_IO_Thread;
    }

    void ListenRespond_Control::SetFlag_IO_ThreadState(bool value)
    {
        state_IO_Thread = value;
    }
}