All in one file : cpoly.h

# 1. How to define a interface

``` C++
struct CanFly 
{
    void (*fly)(void *arg);
    void (*flyOnWater)(void *arg);

    CPOLY_INTERFACE  // CPOLY macro
};
```

