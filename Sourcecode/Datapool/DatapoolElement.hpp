#ifndef DATAPOOLELEMENT_HPP
#define DATAPOOLELEMENT_HPP

#include "DatapoolDefinition.hpp"
#include <QLoggingCategory>


class DatapoolElement
{
public:
    DatapoolElement();
    ~DatapoolElement();

    eElementState setElement(unsigned int id, sElementDatapool &data);
    bool setElementAction(unsigned int id, eElementAction elementaction);

    eElementState getElement(unsigned int id, sElementDatapool &element);
    eElementState getElementState(unsigned int id);
    eElementAction getElementAction(unsigned int id);

    bool isElementReceiverChangeValid(unsigned int id, unsigned int receiver);

    bool loadElement(unsigned int id);
    bool saveElement(unsigned int id);

private:
    unsigned int mElementID;
    int mDatasize;
    char *mpdata;
    unsigned int mReceiverChange;
    eElementState    meElementState;
    eElementAction   meElementAction;
    QLoggingCategory m_categrory;
};

#endif // DATAPOOLELEMENT_H
