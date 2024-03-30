#include "fish.h"
#include <stdio.h>
static inline void fish_fly(void *arg)
{
    printf("fish is flying hah\n");
}
static inline void fish_flyOnWater(void *arg)
{
    printf("fish is fish_flyOnWater hah\n");
}
static inline void fish_run()
{
    printf("fish is running hah\n");
}

OVERRIDES_BEGIN(Fish)
    OVERRIDE(CanFly, fly, Fish, fish_fly),
    OVERRIDE(CanFly, flyOnWater, Fish, fish_flyOnWater),
OVERRIDES_END(Fish)
