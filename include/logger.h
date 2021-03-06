#pragma once
#include "stdafx.h"
#include "../src/Game/game.h";
#include <vector>
//#define RELEASE_VER

#ifndef RELEASE_VER
#define LOG(_level, _str, ...) { \
if (DEBUG_LEVEL >= _level) { logger(_str, __VA_ARGS__); }}
#else
#define LOG(_level, _str, ...) {}
#endif

inline void logger(const char* message, ...);
void logGameState(uintptr_t* time, uintptr_t* p1, uintptr_t* p2, uintptr_t* XScreenScroll, uintptr_t* YScreenScroll, uintptr_t* p1Effect, uintptr_t* p2Effect);
void logPlayerPointers(uintptr_t base, game::PlayerData& player_data, std::string const& player);
void openLogger();
void closeLogger();
//free it after usage!!
char* getFullDate();
void logSettingsIni();
bool checkHookSuccess(PBYTE addr, const char* funcName);
void logD3DPParams(D3DPRESENT_PARAMETERS* pPresentationParameters, bool isOriginalSettings = true);