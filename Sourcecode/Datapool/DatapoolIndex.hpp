#ifndef DATAPOOLINDEX_HPP
#define DATAPOOLINDEX_HPP

// enum for datapool --> check Datapool version in SaveDatapool.cpp
// if add datapoolid at the end increase minorversion
// iff add datapoolid at the end increase majorversion and set minor to 0
enum eDatapoolIndex
{
    DIDatapoolVersionString,
    DItime,
    DIdate,
    DIdataformatId,
    DIDataformatString,

    DIcount
};


#endif // DATAPOOLINDEX_HPP
