#pragma once

#include "poly.h"
#include "canfly.h"
#include "canrun.h"

CLASS(Fish)
    IMPL(CanFly);
FILES_BEGIN(Fish)
    char *name;
    int age;
FILES_END(Fish)
