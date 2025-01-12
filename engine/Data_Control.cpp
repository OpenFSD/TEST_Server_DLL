#include "Data_Control.h"

namespace Server_Library
{
    bool Data_Control::flag_isLoaded_Stack_InputPraise = false;
    bool Data_Control::flag_isLoaded_Stack_OutputPraise = false;

    Data_Control::Data_Control()
    {
        flag_isLoaded_Stack_InputPraise = bool(false);
        flag_isLoaded_Stack_OutputPraise = bool(false);
    }
    Data_Control::~Data_Control()
    {

    }

    void Data_Control::Pop_Stack_InputPraise(
        Server_Library::Input* ptr_Buffer_Input_core_Reference,
        std::vector<class Server_Library::Input*>* ptr_Stack_InputPraise
    )
    {
        ptr_Buffer_Input_core_Reference = ptr_Stack_InputPraise->front();
        ptr_Stack_InputPraise->erase(ptr_Stack_InputPraise->begin(), ptr_Stack_InputPraise->begin());
    }

    void Data_Control::Pop_Stack_OutputPraise(
        Server_Library::Output* ptr_Buffer_Output_Transmit,
        std::vector<class Server_Library::Output*>* ptr_Stack_OutputPraise
    )
    {
        ptr_Buffer_Output_Transmit = ptr_Stack_OutputPraise->front();
        ptr_Stack_OutputPraise->erase(ptr_Stack_OutputPraise->begin(), ptr_Stack_OutputPraise->begin());
    }

    void Data_Control::Push_Stack_InputPraise(
        std::vector<class Server_Library::Input*>* ptr_Stack_InputPraise,
        Server_Library::Input* ptr_Buffer_Input
    )
    {
        ptr_Stack_InputPraise->push_back(ptr_Buffer_Input);
    }

    void Data_Control::Push_Stack_OutputPraise(
        std::vector<class Server_Library::Output*>* ptr_Stack_OutputPraise,
        Server_Library::Output* ptr_Buffer_Output
    )
    {
        ptr_Stack_OutputPraise->push_back(ptr_Buffer_Output);
    }

    bool Data_Control::GetFlag_InputStackLoaded()
    {
        return flag_isLoaded_Stack_InputPraise;
    }
    bool Data_Control::GetFlag_OutputStackLoaded()
    {
        return flag_isLoaded_Stack_OutputPraise;
    }


    void Data_Control::SetFlag_InputStackLoaded(bool value)
    {
        flag_isLoaded_Stack_InputPraise = value;
    }
    void Data_Control::SetFlag_OutputStackLoaded(bool value)
    {
        flag_isLoaded_Stack_OutputPraise = value;
    }
}