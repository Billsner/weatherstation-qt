#ifndef DATAPOOLINDEX_HPP
#define DATAPOOLINDEX_HPP

#include <stdint.h>
#include "QString"

// enum for datapool --> check Datapool version in SaveDatapool.cpp
// if add datapoolid at the end increase minorversion
// iff add datapoolid at the end increase majorversion and set minor to 0
static const uint32_t DatapoolMajorVersion = 2; //change as incompatible if datapoolid is add at start or in the middle
static const uint32_t DatapoolMinorVersion = 2; //change as compatible if datapoolid is add at the end

enum eDatapoolIndex
{
    DIDatapoolVersionString,
    DItime,    
    DIdate,
    DIdataformatId,
    DIDataformatString,
    DIWaetherDownloadDate,
    DIWeatherDownloadRequest,
    DITodayDate,
    DITodayTempMax,
    DITodayTempMin,
    DITodaySymbol,
    DITodayAnd1TempMax,
    DITodayAnd1TempMin,
    DITodayAnd1Symbol,
    DITodayAnd2TempMax,
    DITodayAnd2TempMin,
    DITodayAnd2Symbol,

    DIcount
};

static const QString defaultformate("dd.MM.yyyy");

#endif // DATAPOOLINDEX_HPP
