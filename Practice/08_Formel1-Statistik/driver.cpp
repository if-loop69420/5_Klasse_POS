#include "driver.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_FORMULA_ONE(drivers)

namespace qx {
template <> void register_class(QxClass<drivers> & t)
{
    t.id(& drivers::d_id, "driverId");

    t.data(& drivers::d_forename, "forename");
    t.data(& drivers::d_surname, "surname");
    t.data(& drivers::d_dob, "dob");
    t.data(& drivers::d_nation, "nationality");
}}
