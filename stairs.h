#ifndef STAIRS_H
#define STAIRS_H
#include "object.h"

class stairs : public Object
{
    public:
        stairs(int row, int col);
        virtual ~stairs() = default;
};

#endif // STAIRS_H
