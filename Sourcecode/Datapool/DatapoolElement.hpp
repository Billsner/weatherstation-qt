#ifndef DATAPOOLELEMENT_HPP
#define DATAPOOLELEMENT_HPP

#include "DatapoolDefinition.hpp"
#include <QLoggingCategory>
#include <QMutex>


class DatapoolElement
{
public:
    DatapoolElement();
    ~DatapoolElement();

    void setElement(unsigned int id, sElementDatapool &data);
    void setElementAction(unsigned int id, eElementAction elementaction, bool &ret);

    void getElement(unsigned int id, sElementDatapool &element);
    void getElementState(unsigned int id, eElementState &ret);
    void getElementAction(unsigned int id, eElementAction &ret);

    void isElementReceiverChangeValid(unsigned int id, unsigned int receiver, bool &ret);

    void loadElement(unsigned int id);
    void saveElement(unsigned int id);

private:
    unsigned int mElementID;
    int mDatasize;
    char *mpdata;
    unsigned int mReceiverChange;
    eElementState    meElementState;
    eElementAction   meElementAction;
    QLoggingCategory m_categrory;
    QMutex           m_mutex;
};

#endif // DATAPOOLELEMENT_H
