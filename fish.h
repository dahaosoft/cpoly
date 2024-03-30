#pragma once

#include "poly.h"
#include "canfly.h"
#include "canrun.h"

CPOLY_CLASS(Fish)
    CPOLY_IMPL(CanFly);
CPOLY_FIELD_BEGIN(Fish)
    char *name;
    int age;
CPOLY_FIELD_END(Fish)
