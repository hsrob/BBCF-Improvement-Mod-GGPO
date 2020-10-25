#include "../../include/SteamApiWrapper/SteamControllerWrapper.h"
#include "../../include/utils.h"
#include "../../include/SteamApiWrapper/SteamFriendsWrapper.h"

SteamControllerWrapper::SteamControllerWrapper(ISteamController** pSteamController)
{
	LOG(7, "SteamUserWrapper\n");
	LOG(7, "\t- before: *pSteamController: 0x%p, thispointer: 0x%p\n", *pSteamController, this);

	m_SteamController = *pSteamController;
	void* thisAddress = this;
	WriteToMemory((uintptr_t)pSteamController, (char*)&thisAddress, 4); //basically *pSteamController = this;

	LOG(7, "\t- after: *pSteamController: 0x%p, m_SteamUser: 0x%p\n", *pSteamController, m_SteamController);
}

SteamControllerWrapper::~SteamControllerWrapper()
{
}

bool SteamControllerWrapper::Init()
{
	LOG(7, "Init\n");
	return m_SteamController->Init();
}

bool SteamControllerWrapper::Shutdown()
{
	LOG(7, "Shutdown\n");
	return m_SteamController->Shutdown();
}

void SteamControllerWrapper::RunFrame()
{
	LOG(7, "RunFrame\n");
	return m_SteamController->RunFrame();
}

int SteamControllerWrapper::GetConnectedControllers(ControllerHandle_t* handlesOut)
{
	LOG(7, "GetConnectedControllers\n");
	return m_SteamController->GetConnectedControllers(handlesOut);
}

bool SteamControllerWrapper::ShowBindingPanel(ControllerHandle_t controllerHandle)
{
	LOG(7, "ShowBindingPanel\n");
	return m_SteamController->ShowBindingPanel(controllerHandle);
}

ControllerActionSetHandle_t SteamControllerWrapper::GetActionSetHandle(const char* pszActionSetName)
{
	LOG(7, "GetActionSetHandle\n");
	return m_SteamController->GetActionSetHandle(pszActionSetName);
}

// TODO: More implementation (B 2020-10-24)
