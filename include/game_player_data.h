#pragma once
#include <string>
typedef struct PlayerData {

    /*
    Here we will need to put in stuff related to characters, ranging
    from current heat to character specific stuff (i.e Susan seals)
    */

    int* health;
    int* x_pos;
    int* y_pos;
    int* effect;
    int* heat;
    int* barrier;
    int* danger;
    int* burst;
    int* activeFlow;
    int* overdriveTime;
    int* damageScaling;
    int* objectLifetime;
    int* objectDestroyTime;
    int* sprite;
    std::string* spriteState;

    //enum PlayerDataAllowedNormals allowedNormals;

} PlayerData;

typedef struct GameState
{
	//int nFramesToSkipRender;
	//int nFramesSkipped;
	//int lastSecondNumFramesSimulated;

	//GGPOState ggpoState;
	//SessionInitiationState sessionInitState;

	//Struct definitons for GameObjectData

	//Camera values

	int* time;
	int* XscreenScroll;
	int* YscreenScroll;

	int* universalEffects;
	int* universalEffects2;
    int* universalEffectsUnknown1;
    int* universalEffectsUnknown5;
	int* universalEffectCounter;

	PlayerData player1;
	PlayerData player2;

	//Will update this more as I get a clearer idea on what exactly we'll need
} GameState;

typedef struct SavedGameState {

    struct SavedPlayerData {
        int health;
        int x_pos;
        int y_pos;
		int effect;
        int heat;
        int barrier;
        int danger;
        int burst;
        int activeFlow;
        int overdriveTime;
        int damageScaling;
        int objectLifetime;
        int objectDestroyTime;
        int sprite;
    	// TODO: Confirm this isn't needed and remove (B 2020-10-21)
        std::string spriteState;
    };

    int time;
    int XscreenScroll;
    int YscreenScroll;

	int universalEffects;
	int universalEffects2;
    int universalEffectsUnknown1;
    int universalEffectsUnknown5;
	int universalEffectCounter;
	
    SavedPlayerData player1;
    SavedPlayerData player2;

} SavedGameState;