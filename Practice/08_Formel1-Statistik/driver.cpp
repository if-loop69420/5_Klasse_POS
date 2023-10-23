#include "driver.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_FORMULA_ONE(driver)

namespace qx {
template <> void register_class(QxClass<driver> & t)
{
    t.id(& driver::d_id, "driverId");

    t.data(& driver::d_forename, "forename");
    t.data(& driver::d_surname, "surname");
    t.data(& driver::d_dob, "dob");
    t.data(& driver::d_nation, "nationality");
}}
