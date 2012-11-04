#ifndef QATMODEM_GLOBAL_H
#define QATMODEM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QATMODEM_LIBRARY)
#  define QATMODEMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QATMODEMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QATMODEM_GLOBAL_H