#pragma once

#include "poly.h"
#include "canfly.h"
#include "canrun.h"

CPOLY_CLASS(Bird)
    CPOLY_IMPL(CanFly);
    CPOLY_IMPL(CanRun);
CPOLY_FIELD_BEGIN(Bird)
    char *name;
CPOLY_FIELD_END(Bird)



