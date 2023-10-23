#include "airport.h"
#include "precompiled.h"
#include <QxOrm_Impl.h>

QX_REGISTER_CPP_TEST(Airport)

namespace qx {
template <> void register_class(QxClass<Airport> & t)
{
    t.setName("Airport");
    t.id(& Airport::m_id, "id");

    t.data(& Airport::m_name, "name");
    t.data(& Airport::m_iata, "iata");
    t.data(& Airport::m_latitude, "latitude");
    t.data(& Airport::m_longitude, "longitude");
}}
