#ifndef INTERPRETMOSMIXL_HPP
#define INTERPRETMOSMIXL_HPP

#include "Utils/logging.hpp"

class InterpretMOSMIXL
{
public:
    InterpretMOSMIXL();
    ~InterpretMOSMIXL();

    void startIntepretion(void);

private:
    void unzipFile(void);
    void openFile(void);

    Logging mLogging;

};

#endif // INTERPRETMOSMIXL_HPP
