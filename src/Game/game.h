#pragma once

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include <ggponet.h>
#include <memory>
#include <array>

#include "../../include/containers.h"
#include "../../include/logger.h"
#include "../../include/game_player_data.h"

namespace game {

/*
const unsigned short MIN_HEAT = 0;
const unsigned short MAX_HEAT = <put value here>;
const unsigned short MIN_BURST = 0;
const unsigned short MAX_BURST = <put value here>;
const unsigned short MIN_HEALTH = <put value here>;
const unsigned short MAX_HEALTH = <put value here>;
const unsigned short MAX_BARRIER = <put value here>;
const unsigned short MIN_BARRIER = <put value here>;
const short MIN_NEGATIVE_PENALTY = 0;
const short MAX_NEGATIVE_PENALTY = <put value here> ;

For the burst and barrier values, i'm not 100% sure if they are signed or not. If they are, just remove "unsigned" next to them - Grim
(Feel Free to delete this comment when we confirm it)
*/

/*
enum gameinputs : unsigned short {
    Up = 
	Right = 
	Down = 
	Left = 
	Taunt = 
	A = 
	B = 
	C = 
	D =  
	Reset = 
	Pause = 
};
*/

/*
typedef enum HitboxTypes {
  

} HitboxTypes;
*/

/*
typedef struct SpriteInfo {
    

} SpriteInfo;
*/

/*
typedef enum PlayerDataAllowedNormals {
    ALLNORMALS = 

    NORMAL_2A = 
    NORMAL_4A = 
    NORMAL_5A = 
    NORMAL_6A = 
    NORMAL_2B = 
    NORMAL_4B = 
    NORMAL_5B = 
    NORMAL_6B = 
    NORMAL_1C = 
    NORMAL_2C = 
    NORMAL_3C = 
    NORMAL_4C = 
    NORMAL_5C = 
    NORMAL_6C = 
    NORMAL_1D =
    NORMAL_2D = 
    NORMAL_3D =
    NORMAL_4D =
    NORMAL_5D =
    NORMAL_6D =
    NORMAL_7D =
    NORMAL_8D =
    NORMAL_9D =
    NORMAL_J2A =
    NORMAL_J5A =
    NORMAL_J2B =
    NORMAL_J5B =
    NORMAL_J6B =
    NORMAL_J2C =
    NORMAL_J5C =
    NORMAL_J1D =
    NORMAL_J2D =
    NORMAL_J3D =
    NORMAL_J4D =
    NORMAL_J5D =
    NORMAL_J6D =
    NORMAL_J7D =
    NORMAL_J8D =
    NORMAL_J9D =

} PlayerDataAllowedNormals;
*/


/*
struct RandomNumberGenerator {
   
};
*/


typedef struct ClientSynchronizationRequest {

    unsigned short nPort;
    int nSelectedCharacter;

} ClientSynchronizationRequest;



typedef struct ServerSynchronizationResponse {

    unsigned short nPort;
    int nSelectedCharacter;
    //Reminder to make sure to put RNG structs in here

} ServerSynchronizationResponse;



typedef struct CharacterSelection {
    char* name;
    int value;
} CharacterSelection;

/*
static CharacterSelection CHARACTERS[] = {
    {"Charactername here", <hexadecimal # here>},

    repeat for every character
 
};
*/

typedef struct StageSelection {
    char* name;
    int value;
} StageSelection;

/*
static StageSelection STAGES[] = {
    {"Stage name", hexidecimal #},

    repeat for every character
};
*/

struct InputRewriteStruct {
    bool left;
    bool down;
    bool up;
    bool right;
    bool a;
    bool b;
    bool c;
    bool d;
    bool taunt;
};

/*
typedef struct GameMethods {


} GameMethods;
*/

typedef struct GGPOState {
  
    GGPOSession* ggpo;
    GGPOPlayer p1;
    GGPOPlayer p2;
    GGPOPlayer* localPlayer;
    GGPOPlayer* remotePlayer;
    GGPOPlayerHandle player_handles[2];
    GGPOSessionCallbacks cb;
    GGPOErrorCode lastResult;
    int localPlayerIndex;
    int characters[2];
    char bIsSynchronized;
    int nFramesAhead;

} GGPOState;



typedef struct SessionInitiationState {

    ClientSynchronizationRequest request;
    ServerSynchronizationResponse response;
    bool bHasRequest;
    bool bHasResponse;
    bool bIsHost;
   

} SessionInitializationState;


/*
typedef struct PlayData {
 

} PlayData;
*/

/*
typedef struct CharacterConstants {


} CharacterConstants;
*/

template <std::size_t T>
static uintptr_t FindAddress(uintptr_t base, std::array<unsigned int, T> const& offsets)
{
    if (offsets.size() == 0) {
        return base;
    }

    for (std::size_t i = 0; i < offsets.size(); ++i) {
        base = *(uintptr_t*)base;

        if (base == NULL) {
            return NULL;
        }

        base += offsets[i];
    }

    return base;
}

namespace pointer_offsets {
    static const std::array<unsigned int, 1> time = { 0xDA0CE8 };
    static const std::array<unsigned int, 1> hardTimeRef = { 0xDA0CEC };
    static const std::array<unsigned int, 1> XscreenScroll = { 0xDC2130 };
    static const std::array<unsigned int, 1> YscreenScroll = { 0xDC2134 };
	static const std::array<unsigned int, 1> universalEffects = { 0x59B0A4 };
	static const std::array<unsigned int, 1> universalEffects2 = { 0x59B0A8 };
	static const std::array<unsigned int, 1> universalEffectsUnknown1 = { 0x59B0B4 };
    static const std::array<unsigned int, 1> universalEffectsUnknown5 = { 0x5ABD94 };
    static const std::array<unsigned int, 1> universalEffectCounter = { 0x59B0C8 };

	// Note these aren't arrays, we only need a single offset here.
    static const unsigned int player1 = 0x819DF0;
    static const unsigned int player2 = 0xDC204C;
	
    namespace player_common {
        static const std::array<unsigned int, 1> health = { 0x9D4 };
        static const std::array<unsigned int, 1> xpos   = { 0x268 };
        static const std::array<unsigned int, 1> ypos = { 0x26C };
        static const std::array<unsigned int, 1> effect = { 0x22C };
        static const std::array<unsigned int, 1> heat = { 0x5AD4 };
        static const std::array<unsigned int, 1> barrier = { 0x5B04 };
        static const std::array<unsigned int, 1> danger = { 0x5B0C };
        static const std::array<unsigned int, 1> burst = { 0x5AE4 };
        static const std::array<unsigned int, 1> activeFlow = { 0x200D8 };
        static const std::array<unsigned int, 1> overdriveTime = { 0x1C0 };
        static const std::array<unsigned int, 1> damageScaling = { 0x1F0 };
        static const std::array<unsigned int, 1> objectLifetime = { 0x160 };
        static const std::array<unsigned int, 1> objectDestroyTime = { 0x16F8 };
        static const std::array<unsigned int, 1> sprite = { 0xD8 };
        // string version of `sprite`? ex. iz000_00.bmp Izayoi neutral sprite (hsrob 2020-10-19)
        // I now think this is unnecessary, restoring the `sprite` pointer value works well enough (I think - hsrob 2020-10-20)
    	static const std::array<unsigned int, 1> spriteState = { 0xD8 };
    }
}

extern std::unique_ptr<GameState> gGameState;

void InitGameStatePointers();

extern std::unique_ptr<std::array<unsigned char, 0x214C4 >> gP1Data;
extern std::unique_ptr<std::array<unsigned char, 0x214C4 >> gP2Data;


static SavedGameState SaveGameState()
{
    SavedGameState saved_game_state;
    
    if (gGameState) {
        saved_game_state.time = *gGameState->time;
        saved_game_state.XscreenScroll = *gGameState->XscreenScroll;
        saved_game_state.YscreenScroll = *gGameState->YscreenScroll;

    	saved_game_state.universalEffects = *gGameState->universalEffects;
        saved_game_state.universalEffects2 = *gGameState->universalEffects2;
        saved_game_state.universalEffectsUnknown1 = *gGameState->universalEffectsUnknown1;
        saved_game_state.universalEffectsUnknown5 = *gGameState->universalEffectsUnknown5;
        saved_game_state.universalEffectCounter = *gGameState->universalEffectCounter;
        
        saved_game_state.player1.health = *gGameState->player1.health;
        saved_game_state.player1.x_pos = *gGameState->player1.x_pos;
        saved_game_state.player1.y_pos = *gGameState->player1.y_pos;
		saved_game_state.player1.effect = *gGameState->player1.effect;
        saved_game_state.player1.heat = *gGameState->player1.heat;
        saved_game_state.player1.barrier = *gGameState->player1.barrier;
        saved_game_state.player1.danger = *gGameState->player1.danger;
        saved_game_state.player1.burst = *gGameState->player1.burst;
        saved_game_state.player1.activeFlow = *gGameState->player1.activeFlow;
        saved_game_state.player1.overdriveTime = *gGameState->player1.overdriveTime;
        saved_game_state.player1.damageScaling = *gGameState->player1.damageScaling;
        saved_game_state.player1.objectLifetime = *gGameState->player1.objectLifetime;
        saved_game_state.player1.objectDestroyTime = *gGameState->player1.objectDestroyTime;
        saved_game_state.player1.sprite = *gGameState->player1.sprite;
        saved_game_state.player1.spriteState = *gGameState->player1.spriteState;

        saved_game_state.player2.health = *gGameState->player2.health;
        saved_game_state.player2.x_pos = *gGameState->player2.x_pos;
        saved_game_state.player2.y_pos = *gGameState->player2.y_pos;
		saved_game_state.player2.effect = *gGameState->player2.effect;
        saved_game_state.player2.heat = *gGameState->player2.heat;
        saved_game_state.player2.barrier = *gGameState->player2.barrier;
        saved_game_state.player2.danger = *gGameState->player2.danger;
        saved_game_state.player2.burst = *gGameState->player2.burst;
        saved_game_state.player2.activeFlow = *gGameState->player2.activeFlow;
        saved_game_state.player2.overdriveTime = *gGameState->player2.overdriveTime;
        saved_game_state.player2.damageScaling = *gGameState->player2.damageScaling;
        saved_game_state.player2.objectLifetime = *gGameState->player2.objectLifetime;
        saved_game_state.player2.objectDestroyTime = *gGameState->player2.objectDestroyTime;
        saved_game_state.player2.sprite = *gGameState->player2.sprite;
        saved_game_state.player2.spriteState = *gGameState->player2.spriteState;

		// TODO: Load character specific values for each player (B 2020-10-19)
    }
	
    try
    {
        logGameState(saved_game_state, "Saving Game State...");
        auto base = (uintptr_t)Containers::gameProc.hBBCFGameModule;
    
		// Game
	    logString("Saving Game...");
	    uintptr_t* time_ref = (uintptr_t*)(base + pointer_offsets::time[0]);
	    uintptr_t* XscreenScroll_ref = (uintptr_t*)(base + pointer_offsets::XscreenScroll[0]);
	    uintptr_t* YscreenScroll_ref = (uintptr_t*)(base + pointer_offsets::YscreenScroll[0]);
	    logString("Calculated pointer offsets");
	    auto time_dref = *time_ref;
	    auto XscreenScroll_dref = *XscreenScroll_ref;
	    auto YscreenScroll_dref = *YscreenScroll_ref;
	    logString("Set drefs...");
	    std::memcpy(gGameState->time, (unsigned char*)(time_dref), sizeof(unsigned char*));
	    logString("Saved time");
	    std::memcpy(gGameState->XscreenScroll, (unsigned char*)(XscreenScroll_dref), sizeof(unsigned char*));
	    logString("Saved XscreenScroll");
	    std::memcpy(gGameState->YscreenScroll, (unsigned char*)(YscreenScroll_dref), sizeof(unsigned char*));
	    logString("Saved YscreenScroll");
		
		// Effects
	    logString("Saving Effects...");
	    auto universalEffects_ref = (uintptr_t*)(base + pointer_offsets::universalEffects[0]);
	    auto universalEffects2_ref = (uintptr_t*)(base + pointer_offsets::universalEffects2[0]);
	    auto universalEffectsUnknown1_ref = (uintptr_t*)(base + pointer_offsets::universalEffectsUnknown1[0]);
	    auto universalEffectsUnknown5_ref = (uintptr_t*)(base + pointer_offsets::universalEffectsUnknown5[0]);
	    auto universalEffectCounter_ref = (uintptr_t*)(base + pointer_offsets::universalEffectCounter[0]);
		
	    auto universalEffects_dref = *universalEffects_ref;
	    auto universalEffects2_dref = *universalEffects2_ref;
	    auto universalEffectsUnknown1_dref = *universalEffectsUnknown1_ref;
	    auto universalEffectsUnknown5_dref = *universalEffectsUnknown5_ref;
	    auto universalEffectCounter_dref = *universalEffectCounter_ref;
		
	    std::memcpy(gGameState->universalEffects, (unsigned char*)(universalEffects_dref), sizeof(unsigned char*));
	    std::memcpy(gGameState->universalEffects2, (unsigned char*)(universalEffects2_dref), sizeof(unsigned char*));
	    std::memcpy(gGameState->universalEffectsUnknown1, (unsigned char*)(universalEffectsUnknown1_dref), sizeof(unsigned char*));
	    std::memcpy(gGameState->universalEffectsUnknown5, (unsigned char*)(universalEffectsUnknown5_dref), sizeof(unsigned char*));
	    std::memcpy(gGameState->universalEffectCounter, (unsigned char*)(universalEffectCounter_dref), sizeof(unsigned char*));
	    logString("Saved Effects");
		
		// Players
	    logString("Saving Players...");
	    auto p1_ref= (uintptr_t*)(base + pointer_offsets::player1);
	    auto p1_dref = *p1_ref;
	    auto p2_ref= (uintptr_t*)(base + pointer_offsets::player2);
	    auto p2_dref = *p2_ref;
	    std::memcpy(gP1Data->data(), (unsigned char*)(p1_dref), 0x214C4);
	    std::memcpy(gP2Data->data(), (unsigned char*)(p2_dref), 0x214C4);
	    logString("Saved Players");
	    logString("Saved Game State");
    }
    catch (const std::exception& exc)
    {
        logString("--- ERROR ---");
        logString(exc.what());
    }
	
    return saved_game_state;
}

static void LoadGameState(SavedGameState const& saved_game_state)
{
    logGameState(saved_game_state, "Loading Game State...");
    if (gGameState) {
        *gGameState->time = saved_game_state.time;
        *gGameState->XscreenScroll = saved_game_state.XscreenScroll;
        *gGameState->YscreenScroll = saved_game_state.YscreenScroll;

        *gGameState->universalEffects = saved_game_state.universalEffects;
        *gGameState->universalEffects2 = saved_game_state.universalEffects2;
        *gGameState->universalEffectsUnknown1 = saved_game_state.universalEffectsUnknown1;
        *gGameState->universalEffectsUnknown5 = saved_game_state.universalEffectsUnknown5;
        *gGameState->universalEffectCounter = saved_game_state.universalEffectCounter;
    	
        *gGameState->player1.health = saved_game_state.player1.health;
        *gGameState->player1.x_pos = saved_game_state.player1.x_pos;
        *gGameState->player1.y_pos = saved_game_state.player1.y_pos;
		*gGameState->player1.effect = saved_game_state.player1.effect;
        *gGameState->player1.heat = saved_game_state.player1.heat;
        *gGameState->player1.barrier = saved_game_state.player1.barrier;
        *gGameState->player1.danger = saved_game_state.player1.danger;
        *gGameState->player1.burst = saved_game_state.player1.burst;
        *gGameState->player1.activeFlow = saved_game_state.player1.activeFlow;
        *gGameState->player1.overdriveTime = saved_game_state.player1.overdriveTime;
        *gGameState->player1.damageScaling = saved_game_state.player1.damageScaling;
        *gGameState->player1.objectLifetime = saved_game_state.player1.objectLifetime;
        *gGameState->player1.objectDestroyTime = saved_game_state.player1.objectDestroyTime;
        *gGameState->player1.sprite = saved_game_state.player1.sprite;
        *gGameState->player1.spriteState = saved_game_state.player1.spriteState;

        *gGameState->player2.health = saved_game_state.player2.health;
        *gGameState->player2.x_pos = saved_game_state.player2.x_pos;
        *gGameState->player2.y_pos = saved_game_state.player2.y_pos;
		*gGameState->player2.effect = saved_game_state.player2.effect;
        *gGameState->player2.heat = saved_game_state.player2.heat;
        *gGameState->player2.barrier = saved_game_state.player2.barrier;
        *gGameState->player2.danger = saved_game_state.player2.danger;
        *gGameState->player2.burst = saved_game_state.player2.burst;
        *gGameState->player2.activeFlow = saved_game_state.player2.activeFlow;
        *gGameState->player2.overdriveTime = saved_game_state.player2.overdriveTime;
        *gGameState->player2.damageScaling = saved_game_state.player2.damageScaling;
        *gGameState->player2.objectLifetime = saved_game_state.player2.objectLifetime;
        *gGameState->player2.objectDestroyTime = saved_game_state.player2.objectDestroyTime;
        *gGameState->player2.sprite = saved_game_state.player2.sprite;
        *gGameState->player2.spriteState = saved_game_state.player2.spriteState;
    }
    try
    {
	    auto base = (uintptr_t)Containers::gameProc.hBBCFGameModule;
		
	    // Game
	    logString("Loading Game...");
	    auto time_ref = (uintptr_t*)(base + pointer_offsets::time[0]);
	    auto XscreenScroll_ref = (uintptr_t*)(base + pointer_offsets::XscreenScroll[0]);
	    auto YscreenScroll_ref = (uintptr_t*)(base + pointer_offsets::YscreenScroll[0]);

	    auto time_dref = *time_ref;
	    auto XscreenScroll_dref = *XscreenScroll_ref;
	    auto YscreenScroll_dref = *YscreenScroll_ref;
	    
	    std::memcpy((unsigned char*)(time_dref), gGameState->time, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(XscreenScroll_dref), gGameState->XscreenScroll, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(YscreenScroll_dref), gGameState->YscreenScroll, sizeof(unsigned char*));
	    logString("Loaded Game");
		
	    // Effects
	    logString("Loading Effects...");
	    auto universalEffects_ref = (uintptr_t*)(base + pointer_offsets::universalEffects[0]);
	    auto universalEffects2_ref = (uintptr_t*)(base + pointer_offsets::universalEffects2[0]);
	    auto universalEffectsUnknown1_ref = (uintptr_t*)(base + pointer_offsets::universalEffectsUnknown1[0]);
	    auto universalEffectsUnknown5_ref = (uintptr_t*)(base + pointer_offsets::universalEffectsUnknown5[0]);
	    auto universalEffectCounter_ref = (uintptr_t*)(base + pointer_offsets::universalEffectCounter[0]);

	    auto universalEffects_dref = *universalEffects_ref;
	    auto universalEffects2_dref = *universalEffects2_ref;
	    auto universalEffectsUnknown1_dref = *universalEffectsUnknown1_ref;
	    auto universalEffectsUnknown5_dref = *universalEffectsUnknown5_ref;
	    auto universalEffectCounter_dref = *universalEffectCounter_ref;

	    std::memcpy((unsigned char*)(universalEffects_dref), gGameState->universalEffects, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(universalEffects2_dref), gGameState->universalEffects2, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(universalEffectsUnknown1_dref), gGameState->universalEffectsUnknown1, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(universalEffectsUnknown5_dref), gGameState->universalEffectsUnknown5, sizeof(unsigned char*));
	    std::memcpy((unsigned char*)(universalEffectCounter_dref), gGameState->universalEffectCounter, sizeof(unsigned char*));
	    logString("Loaded Effects");

	    logString("Loading Players...");
	    auto p1_dref = *(uintptr_t*)(base + pointer_offsets::player1);
	    auto p2_dref = *(uintptr_t*)(base + pointer_offsets::player2);
		
	    std::memcpy((unsigned char*)p1_dref, gP1Data->data(), 0x214C4);
	    std::memcpy((unsigned char*)p2_dref, gP2Data->data(), 0x214C4);
	    logString("Loaded Players");
	    logString("Loaded Game State");
    }
    catch (const std::exception& exc)
    {
        logString("--- ERROR ---");
        logString(exc.what());
    }
}

/*
struct GameObjectScriptingStruct {



};
*/

/*
typedef enum GameObjectID {

<List game objects and their IDs here>

} GameObjectID;
*/

/*
typedef enum GameObjectStateFlags {

<List game object state flags and their IDs here (i.e Blockstun)>

} GameObjectStateFlags;
*/

/*
typedef enum GameObjectGraphicalEffectsFlags {



} GameObjectGraphicalEffectsFlags;
*/

/*
typedef enum GameObjectAttackInformationFlags {



} GameObjectAttackInformationFlags;
*/

/*
typedef struct GameObjectAttackInformation {
	


} GameObjectAttackInformation;
*/

/*
struct GameObjectData {

};
*/


}