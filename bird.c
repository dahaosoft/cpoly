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

OVERRIDES_BEGIN(Bird)
    OVERRIDE(CanFly, fly,        Bird, bird_fly),
    OVERRIDE(CanFly, flyOnWater, Bird, bird_flyOnWater),
    OVERRIDE(CanRun, run,        Bird, bird_run),
OVERRIDES_END(Bird) 
