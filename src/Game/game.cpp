#include "game.h"

namespace game {

using CharData = std::array<unsigned char, 0x214C4 >;
using ObjData = std::array<unsigned char, 0x214C4 >;
/// <summary>
/// Global Game State
/// </summary>
std::unique_ptr<GameState> gGameState;
std::unique_ptr<CharData> gP1Data;
std::unique_ptr<CharData> gP2Data;

/// <summary>
/// Gets the pointer data pointers in BBCF's memory, so we can access and write to them later for
/// saving and loading state
/// </summary>
///
/// <param name="base">The pointer address to the player object (note: NOT BBCF's base address)</param>
/// <param name="player_data">The player data object to write the addresses into</param>
/// <param name="player">String representation of what player this is for logging purposes e.g. "player 1" or "player 2"</param>
static void GetPlayerPointers(uintptr_t base, PlayerData& player_data, std::string const& player)
{
    auto get_address_or_log = [](std::string const& name, uintptr_t base, auto offsets) {
        uintptr_t addr = FindAddress(base, offsets);

        if (!addr) {
            LOG(2, ("Could not find address for " + name).c_str());
        }

        return addr;
    };

    player_data.health = (int*)get_address_or_log(
        player + " health",
        base,
        pointer_offsets::player_common::health
    );

    player_data.x_pos = (int*)get_address_or_log(
        player + " xpos",
        base,
        pointer_offsets::player_common::xpos
    );

    player_data.y_pos = (int*)get_address_or_log(
        player + " ypos",
        base,
        pointer_offsets::player_common::ypos
    );

	player_data.effect = (int*)get_address_or_log(
        player + " effect",
        base,
        pointer_offsets::player_common::effect
    );
	
	player_data.heat = (int*)get_address_or_log(
        player + " heat",
        base,
        pointer_offsets::player_common::heat
    );
	
	player_data.barrier = (int*)get_address_or_log(
        player + " barrier",
        base,
        pointer_offsets::player_common::barrier
    );
	
	player_data.danger = (int*)get_address_or_log(
        player + " danger",
        base,
        pointer_offsets::player_common::danger
    );
	
	player_data.burst = (int*)get_address_or_log(
        player + " burst",
        base,
        pointer_offsets::player_common::burst
    );
	
	player_data.activeFlow = (int*)get_address_or_log(
        player + " activeFlow",
        base,
        pointer_offsets::player_common::activeFlow
    );
	
	player_data.overdriveTime = (int*)get_address_or_log(
        player + " overdriveTime",
        base,
        pointer_offsets::player_common::overdriveTime
    );
	
	player_data.damageScaling = (int*)get_address_or_log(
        player + " damageScaling",
        base,
        pointer_offsets::player_common::damageScaling
    );
	
	player_data.objectLifetime = (int*)get_address_or_log(
        player + " objectLifetime",
        base,
        pointer_offsets::player_common::objectLifetime
    );
	
	player_data.objectDestroyTime = (int*)get_address_or_log(
        player + " objectDestroyTime",
        base,
        pointer_offsets::player_common::objectDestroyTime
    );
	
	player_data.sprite = (int*)get_address_or_log(
        player + " sprite",
        base,
        pointer_offsets::player_common::sprite
    );

	// TODO: Pretty sure we don't need this (B 2020-10-22)
	player_data.spriteState = (std::string*)get_address_or_log(
        player + " spriteState",
        base,
        pointer_offsets::player_common::spriteState
    );
}

void InitGameStatePointers()
{
    gGameState = std::make_unique<GameState>();
    gP1Data = std::make_unique<CharData>();
    gP2Data = std::make_unique<CharData>();

    auto get_address_or_log = [](std::string const& name, uintptr_t base, auto offsets) {
        uintptr_t addr = FindAddress(base, offsets);

        if (!addr) {
            LOG(2, ("Could not find address for " + name).c_str());
        }

        return addr;
    };

    uintptr_t base = (uintptr_t)Containers::gameProc.hBBCFGameModule;

	// TODO: Replace with get_address_or_log (lol how did i forget)?
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );  //(int*)(base + pointer_offsets::time);
    gGameState->time = (int*)get_address_or_log(
        "time",
        base,
        pointer_offsets::time
    );
	
    gGameState->XscreenScroll = (int*)(base + pointer_offsets::XscreenScroll);
    gGameState->YscreenScroll = (int*)(base + pointer_offsets::YscreenScroll);

	gGameState->universalEffects = (int*)(base + pointer_offsets::universalEffects);
    gGameState->universalEffects2 = (int*)(base + pointer_offsets::universalEffects2);
    gGameState->universalEffectsUnknown1 = (int*)(base + pointer_offsets::universalEffectsUnknown1);
    gGameState->universalEffectsUnknown5 = (int*)(base + pointer_offsets::universalEffectsUnknown5);
    gGameState->universalEffectCounter = (int*)(base + pointer_offsets::universalEffectCounter);


	
    GetPlayerPointers(base + pointer_offsets::player1, gGameState->player1, "Player 1");
    GetPlayerPointers(base + pointer_offsets::player2, gGameState->player2, "Player 2");
}

}

//Hold off on working on this page for now