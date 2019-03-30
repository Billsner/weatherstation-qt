#ifndef DATAPOOLDEFINITION_HPP
#define DATAPOOLDEFINITION_HPP

#include <stdint.h>

enum eElementState
{
    ESInt           = 0,
    ESNothing       = 1,
    ESValidChanged  = 2,
    ESValidSaved    = 3,
    ESValidLoad     = 4,
    ESRequest       = 5,

    ESError         = 100
};

enum eElementAction
{
    EANothing       = 0,
    EASendOnChange  = 1,
    EASendCyclic    = 2
};

enum eElementDataType
{
    EDTunknown  = 0,
    EDTint      = 1,
    EDTarray    = 2
};

struct sElementDatapool
{
    uint32_t id;
    uint32_t datasize;
    uint8_t *data;
    eElementState DataState;
    eElementAction DateAction;
};

#endif // DATAPOOLDEFINITION_HPP
