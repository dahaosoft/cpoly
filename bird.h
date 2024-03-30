#pragma once

#include "poly.h"
#include "canfly.h"
#include "canrun.h"

CLASS(Bird)
    IMPL(CanFly);
    IMPL(CanRun);
FILES_BEGIN(Bird)
    char *name;
FILES_END(Bird)



