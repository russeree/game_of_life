/***
 * Creator: Reese Russell
 * Class: Game of Life Config State
 * Desc: A current configuration state
 ***/

#ifndef GAME_OF_LIFE_CONFIG_STATE
#define GAME_OF_LIFE_CONFIG_STATE

class GolConfigState{
    protected:
        int status;
        int debug;
    public:
        GolConfigState();
        virtual ~GolConfigState();
    protected:
        int seed_method;
        int channels;
};
#endif
