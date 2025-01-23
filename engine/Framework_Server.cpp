#include "Framework_Server.h"
#include <cstddef>

namespace Server_Library
{
	class Server* Framework_Server::ptr_HostServer;

	Framework_Server::Framework_Server()
	{
		
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::Create_Hosting_Server()
	{
		ptr_HostServer = new class Server_Library::Server();
		while (ptr_HostServer == NULL) { /* wait untill created */ }
		ptr_HostServer->Get_Execute()->Initialise();
		ptr_HostServer->Get_Execute()->Initialise_Libraries();
		ptr_HostServer->Get_Execute()->Initialise_Threads();
	}

	void Framework_Server::Pop_Stack_OutputPraise()
	{
		Server_Library::Output* ptr_Buffer_Back_Output = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OutputBackDouble();
		std::vector<class Server_Library::Output*>* ptr_Stack_OutputPraise = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_Server_OutputPraise();
		Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Pop_Stack_Server_OutputPraise(
			ptr_Buffer_Back_Output,
			ptr_Stack_OutputPraise
		);
	}

	void Framework_Server::Push_Stack_InputPraise()
	{
		std::vector<class Server_Library::Input*>* ptr_Stack_InputPraise = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_Server_InputPraise();
		Server_Library::Input* ptr_Buffer_Back_Input = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble();
		Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Push_Stack_Server_InputPraise(
			ptr_Stack_InputPraise,
			ptr_Buffer_Back_Input
		);
	}

	__int16 Framework_Server::Get_coreId_To_Launch()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_coreId_To_Launch();
	}

	class Server_Library::Server* Framework_Server::Get_HostServer()
	{
		return ptr_HostServer;
	}

	int Framework_Server::Get_Length_Stack_Server_InputPraise()
	{
		return sizeof(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_Server_InputPraise());
	}

	bool Framework_Server::GetState_Buffer_Input_ToWrite()
	{
		return false;
	}

	unsigned char Framework_Server::Get_NumberOfCores()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores();
	}
	
	WaitEnableWrite::Framework_WriteEnable* Framework_Server::Get_WriteEnable_Stack_Server_InputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise();
	}

	WaitEnableWrite::Framework_WriteEnable* Framework_Server::Get_WriteEnable_Stack_Server_OutputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise();
	}

	__int16 Framework_Server::Get_PraiseEventId()
	{
		Server_Library::Input* inputSet = (Server_Library::Input*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		return inputSet->GetPraiseEventId();
	}
	float Framework_Server::Get_Praise0_pitch()
	{
		Server_Library::Praise0_Output* outputSubset = (Server_Library::Praise0_Output*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset->GetPitch();
	}

	float Framework_Server::Get_Praise0_yaw()
	{
		Server_Library::Praise0_Output* outputSubset = (Server_Library::Praise0_Output*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset->GetYaw();
	}


	void Framework_Server::Set_PraiseEventId(__int16 value)
	{
		Server_Library::Input* inputSet = (Server_Library::Input*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		inputSet->SetPraiseEventId(value);
	}

	void Framework_Server::Set_Praise0_mousePos_X(__int16 value)
	{
		Server_Library::Praise0_Input* inputSubset = (Server_Library::Praise0_Input*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset->Set_mouse_X(value);
	}

	void Framework_Server::Set_Praise0_mousePos_Y(__int16 value)
	{
		Server_Library::Praise0_Input* inputSubset = (Server_Library::Praise0_Input*)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset->Set_mouse_Y(value);
	}

}