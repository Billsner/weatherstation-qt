#ifndef DATAPOOLCONTROLL_HPP
#define DATAPOOLCONTROLL_HPP

#include "DatapoolIndex.hpp"
#include "DatapoolDefinition.hpp"
#include "DatapoolElement.hpp"
#include <QLoggingCategory>
#include <QMutex>

class DatapoolControll
{
public:
    DatapoolControll();
    ~DatapoolControll();

    static DatapoolControll *getInstance();

    void setElement(unsigned int id, sElementDatapool &data);
    void getElement(unsigned int id, sElementDatapool &element);

    void loadDatapool();
    void saveDatapool();

private:
    DatapoolElement mDatapoolElement[DIcount];
    QLoggingCategory m_categrory;
    QMutex m_mutex; //ToDo: Check if its better to have a Mutex in each element

};

#endif // DATAPOOLCONTROLL_HPP
