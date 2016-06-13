/***
 * Creator: Reese Russell
 * Class: Game of Life Config State
 * Desc: A current configuration state
 ***/

#ifndef GAME_OF_LIFE_CONFIG_STATE
#define GAME_OF_LIFE_CONFIG_STATE

namespace enumGolConfigStateStatus{
    enum GolConfigStateStatus{
        success,
        failure
    };
}

class GolConfigState{
    protected:
        int status;
        int debug;
    public:
        GolConfigState();
        GolConfigState(int debug_lvl);
        virtual ~GolConfigState();
    public:
        enum golConfigStateStatus {
            success = 0,
            failure = 1
        };
    protected:
        int seed_method;
        int channels;
};
#endif
