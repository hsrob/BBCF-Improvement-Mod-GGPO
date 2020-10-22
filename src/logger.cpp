#include "../include/logger.h"
#include "../include/game_player_data.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <string>
#include <vector>

bool checkHookSuccess(PBYTE addr, const char* funcName)
{
	if (!addr)
	{
		LOG(2, "FAILED to hook %s\n", funcName);
		return false;

	}
	LOG(2, "Successfully hooked %s at 0x%p\n", funcName, addr);
	return true;
}

#ifndef RELEASE_VER

FILE* g_oFile;

inline void logger(const char* message, ...)
{
	if (!message) { return; }

	va_list args;
	va_start(args, message);
	vfprintf(g_oFile, ( std::to_string(*message) + "\n").c_str(), args);
	va_end(args);

	fflush(g_oFile);
}

void logGameState(SavedGameState gameState, std::string headerMsg)
{
	fprintf(g_oFile, ("--- " + headerMsg + " ---\n").c_str());
	fprintf(g_oFile, ("Round Time: " + std::to_string(gameState.time) + "\n").c_str());
	fprintf(g_oFile, ("XscreenScroll: " + std::to_string(gameState.XscreenScroll) + "\n").c_str());
	fprintf(g_oFile, ("YscreenScroll: " + std::to_string(gameState.YscreenScroll) + "\n").c_str());

	fprintf(g_oFile, ("universalEffects: " + std::to_string(gameState.universalEffects) + "\n").c_str());
	fprintf(g_oFile, ("universalEffects2: " + std::to_string(gameState.universalEffects2) + "\n").c_str());
	fprintf(g_oFile, ("universalEffectsUnknown1: " + std::to_string(gameState.universalEffectsUnknown1) + "\n").c_str());
	fprintf(g_oFile, ("universalEffectsUnknown5: " + std::to_string(gameState.universalEffectsUnknown5) + "\n").c_str());
	fprintf(g_oFile, ("universalEffectCounter: " + std::to_string(gameState.universalEffectCounter) + "\n").c_str());
	
	std::vector<SavedGameState::SavedPlayerData> players = { gameState.player1, gameState.player2 };

	for (int i = 0; i <= 1; i++) {
		std::string p = "P" + std::to_string(i + 1);
		fprintf(g_oFile, (p + " health: " + std::to_string(players[i].health) + "\n").c_str());
		fprintf(g_oFile, (p + " x_pos: " + std::to_string(players[i].x_pos) + "\n").c_str());
		fprintf(g_oFile, (p + " y_pos: " + std::to_string(players[i].y_pos) + "\n").c_str());
		fprintf(g_oFile, (p + " effect: " + std::to_string(players[i].effect) + "\n").c_str());
		fprintf(g_oFile, (p + " heat: " + std::to_string(players[i].heat) + "\n").c_str());
		fprintf(g_oFile, (p + " barrier: " + std::to_string(players[i].barrier) + "\n").c_str());
		fprintf(g_oFile, (p + " danger: " + std::to_string(players[i].danger) + "\n").c_str());
		fprintf(g_oFile, (p + " burst: " + std::to_string(players[i].burst) + "\n").c_str());
		fprintf(g_oFile, (p + " activeFlow: " + std::to_string(players[i].activeFlow) + "\n").c_str());
		fprintf(g_oFile, (p + " overdriveTime: " + std::to_string(players[i].overdriveTime) + "\n").c_str());
		fprintf(g_oFile, (p + " damageScaling: " + std::to_string(players[i].damageScaling) + "\n").c_str());
		fprintf(g_oFile, (p + " objectLifetime: " + std::to_string(players[i].objectLifetime) + "\n").c_str());
		fprintf(g_oFile, (p + " objectDestroyTime: " + std::to_string(players[i].objectDestroyTime) + "\n").c_str());
		fprintf(g_oFile, (p + " y_pos: " + std::to_string(players[i].y_pos) + "\n").c_str());
		fprintf(g_oFile, (p + " sprite: " + std::to_string(players[i].sprite) + "\n").c_str());
	}
	
	fflush(g_oFile);
}


char* getFullDate()
{
	time_t timer;
	char* buffer = (char *)malloc(sizeof(char)* 26);
	if (!buffer)
	{
		return NULL;
	}
	struct tm* tm_info;

	time(&timer);
	tm_info = localtime(&timer);

	strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
	return buffer;
}

void openLogger()
{
	g_oFile = fopen("DEBUG.txt", "w");
	char* time = getFullDate();
	LOG(1, "\n\n\n\n");

	if (time)
	{
		LOG(1, "BBCF_FIX START - %s\n", time);
		free(time);
	}
	else
	{
		LOG(1, "BBCF_FIX START - {Couldn't get the current time}\n");
	}
	LOG(1, "/////////////////////////////////////\n");
	LOG(1, "/////////////////////////////////////\n\n");
}

void closeLogger()
{
	char* time = getFullDate();
	if (time)
	{
		LOG(1, "BBCF_FIX STOP - %s\n", time);
		free(time);
	}
	else
	{
		LOG(1, "BBCF_FIX STOP - {Couldn't get the current time}\n");
	}
	if (g_oFile)
		fclose(g_oFile);
}

void logSettingsIni()
{
	LOG(1, "settings.ini config:\n");
	LOG(1, "\t- ToggleButton: %s\n", Settings::settingsIni.togglebutton.c_str());
	LOG(1, "\t- NotificationPopups: %d\n", Settings::settingsIni.notificationpopups);
	LOG(1, "\t- RenderingWidth: %d\n", Settings::settingsIni.renderwidth);
	LOG(1, "\t- RenderingHeight: %d\n", Settings::settingsIni.renderheight);
	LOG(1, "\t- Viewport: %d\n", Settings::settingsIni.viewport);
	LOG(1, "\t- AntiAliasing: %d\n", Settings::settingsIni.antialiasing);
	LOG(1, "\t- V-Sync: %d\n", Settings::settingsIni.vsync);
	LOG(1, "\t- MenuSize: %d\n", Settings::settingsIni.menusize);
	LOG(1, "\t- Regionlock: %d\n", Settings::settingsIni.regionlock);
	LOG(1, "\t- CpuUsageFix: %d\n", Settings::settingsIni.cpuusagefix);
	LOG(1, "\t- CheckUpdates: %d\n", Settings::settingsIni.checkupdates);
}

void logD3DPParams(D3DPRESENT_PARAMETERS* pPresentationParameters, bool isOriginalSettings)
{
	if (isOriginalSettings)
	{
		LOG(1, "Original D3D PresentationParameters:\n");
	}
	else
	{
		LOG(1, "Modified D3D PresentationParameters:\n");
	}
	LOG(1, "\t- BackBufferWidth: %u\n", pPresentationParameters->BackBufferWidth);
	LOG(1, "\t- BackBufferHeight: %u\n", pPresentationParameters->BackBufferHeight);
	LOG(1, "\t- BackBufferFormat: %u\n", pPresentationParameters->BackBufferFormat);
	LOG(1, "\t- BackBufferCount: %u\n", pPresentationParameters->BackBufferCount);
	LOG(1, "\t- SwapEffect: %u\n", pPresentationParameters->SwapEffect);
	LOG(1, "\t- MultiSampleType: %u\n", pPresentationParameters->MultiSampleType);
	LOG(1, "\t- MultiSampleQuality: %d\n", pPresentationParameters->MultiSampleQuality);
	LOG(1, "\t- EnableAutoDepthStencil: %d\n", pPresentationParameters->EnableAutoDepthStencil);
	LOG(1, "\t- FullScreen_RefreshRateInHz: %u\n", pPresentationParameters->FullScreen_RefreshRateInHz);
	LOG(1, "\t- hDeviceWindow: 0x%p\n", pPresentationParameters->hDeviceWindow);
	LOG(1, "\t- Windowed: %d\n", pPresentationParameters->Windowed);
	LOG(1, "\t- Flags: %d\n", pPresentationParameters->Flags);
	LOG(1, "\t- PresentationInterval: %u\n", pPresentationParameters->PresentationInterval);
}

#else

void openLogger()
{
}
void closeLogger()
{
}
void logSettingsIni()
{
}
void logD3DPParams(D3DPRESENT_PARAMETERS* pPresentationParameters, bool isOriginalSettings)
{
}

#endif