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
    public:
        enum GolConfigStateStatus {
            success = 0,
            failure = 1
        };
        enum SeedingMethods {
            load_from_image,
            new_drawing,
            previous_drawing
        };
    protected:
        int seed_method;
        int channels;
};
#endif
