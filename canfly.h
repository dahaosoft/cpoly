#pragma once

struct CanFly 
{
    void (*fly)(void *arg);
    void (*flyOnWater)(void *arg);

    CPOLY_INTERFACE
};
