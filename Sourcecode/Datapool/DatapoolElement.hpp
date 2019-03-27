#ifndef DATAPOOLELEMENT_HPP
#define DATAPOOLELEMENT_HPP

#include "DatapoolDefinition.hpp"
#include "Utils/Logging.hpp"
#include <QMutex>
#include <stdint.h>


class DatapoolElement
{
public:
    DatapoolElement();
    ~DatapoolElement();

    void setElement(uint32_t id, sElementDatapool &data);
    void setElementAction(uint32_t id, eElementAction elementaction, bool &ret);

    void getElement(uint32_t id, sElementDatapool &element);
    void getElementState(uint32_t id, eElementState &ret);
    void getElementAction(uint32_t id, eElementAction &ret);

    void isElementReceiverChangeValid(uint32_t id, uint32_t receiver, bool &ret);

    void loadElement(uint32_t id);
    void saveElement(uint32_t id);

private:
    uint32_t mElementID;
    uint32_t mDatasize;
    uint8_t *mpdata;
    uint32_t mReceiverChange;
    eElementState    meElementState;
    eElementAction   meElementAction;
    Logging mLogging;
    QMutex           m_mutex;
};

#endif // DATAPOOLELEMENT_H
