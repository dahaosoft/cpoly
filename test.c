#include "bird.h"
#include "fish.h"

#include <stdint.h>
#include <stdio.h>

void fly1(struct CanFly *canfly, void *args)
{
    struct Bird *bird = DYNAMIC_CAST(canfly, Bird, CanFly);
    if (bird)
    {
        printf("bird NAME is %s\n", bird->name);
    }
    else
    {
        struct Fish *fish = DYNAMIC_CAST(canfly, Fish, CanFly);
        printf("fish name is %s , age is %d\n", fish->name, fish->age);
    }
    canfly->fly(args);
}

void fly2(struct CanFly *canfly, void *args)
{
    if (CPOLY_IS_CLASS(canfly, Bird))
    {
        struct Bird *bird = DYNAMIC_CAST(canfly, Bird, CanFly);
        printf("bird name is %s\n", bird->name);
    }
    else
    {
        struct Fish *fish = DYNAMIC_CAST(canfly, Fish, CanFly);
        printf("fish name is %s , age is %d\n", fish->name, fish->age);
    }
    canfly->flyOnWater(args);
}

void run1(struct CanRun *canrun, void *args)
{
    struct Bird *bird = DYNAMIC_CAST(canrun, Bird, CanRun);
    printf("bird name is %s\n", bird->name);
    canrun->run();
}


int main(int argc, char **argv)
{
    CPOLY_DEF_OBJ(Bird, bird1);
    CPOLY_NEW_OBJ(Bird, bird_ptr);
    bird_ptr->name = "[Bird A]";
    bird1.name = "麻雀";

    CPOLY_DEF_OBJ(Fish, fish1);
    fish1.name = "鲤鱼";
    fish1.age = 100;

    struct CanFly *canFly = CPOLY_CAST_UP(CanFly, bird_ptr);
    struct CanRun *canRun = CPOLY_CAST_UP(CanRun, bird_ptr);

    fly1(canFly, &bird1);
    fly2(canFly, &bird1);
    run1(canRun, &bird1);

    struct CanFly *canFly2 = CPOLY_CAST_UP(CanFly, &fish1);
    // struct CanRun *canRun2 = CPOLY_CAST_UP(CanRun, &fish1);

    fly1(canFly2, &bird1);
    fly2(canFly2, &bird1);
    // run1(canRun2, &bird1);
}