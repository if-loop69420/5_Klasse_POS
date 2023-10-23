#ifndef AIRPORT_H
#define AIRPORT_H


class TEST_DLL_EXPORT Airport
{
public:
    // -- properties
    long     m_id;
    QString  m_name;
    QString  m_iata;
    float    m_longitude;
    float    m_latitude;
    // -- contructor, virtual destructor
    Airport() : m_id(0) { ; }
    virtual ~Airport() { ; }
};

//QX_REGISTER_PRIMARY_KEY(Airport, long)
QX_REGISTER_HPP_TEST(Airport, qx::trait::no_base_class_defined, 0);

typedef std::shared_ptr<Airport> airport_ptr;
typedef qx::QxCollection<QString, airport_ptr> list_airport;

#endif // AIRPORT_H
