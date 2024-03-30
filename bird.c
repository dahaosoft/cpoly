#include "bird.h"
#include <stdio.h>
static inline void bird_fly(void *arg)
{
    printf("bird is flying hah\n");
}
static inline void bird_flyOnWater(void *arg)
{
    printf("bird is bird_flyOnWater hah\n");
}
static inline void bird_run()
{
    printf("bird is running hah\n");
}

CPOLY_OVERRIDES_BEGIN(Bird)
    CPOLY_OVERRIDE(CanFly, fly,        Bird, bird_fly),
    CPOLY_OVERRIDE(CanFly, flyOnWater, Bird, bird_flyOnWater),
    CPOLY_OVERRIDE(CanRun, run,        Bird, bird_run),
CPOLY_OVERRIDES_END(Bird) 
