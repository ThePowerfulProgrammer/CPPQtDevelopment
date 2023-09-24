#ifndef VENDOR_H
#define VENDOR_H
#include <iostream>
#include <QString>


class Vendor
{
    public:
        Vendor();
        // default ctor

        void setDetails(QString name, QString email,bool isManufacturer);
        // assign member variables to values supplied in params

        bool isManufacturer();
        // PC: returns true if manufacturer else false

        QString getName();
        // PC: returns m_Name

        std::string toString();
        // PC: returns string representation of the values of it's data members

    protected:

    private:
        QString m_Name;
        QString m_Email;
        bool m_IsManufacturer;
};




Vendor::Vendor():
    m_Name(" "),
    m_Email(" "),
    m_IsManufacturer(false)
{
    // default ctor
}

void Vendor::setDetails(QString name, QString email, bool isManufacturer)
{
    m_Name = name;
    m_Email = email;
    m_IsManufacturer = isManufacturer;
}


bool Vendor::isManufacturer()
{
    return (m_IsManufacturer);
}


QString Vendor::getName()
{
    return m_Name;
}


std::string Vendor::toString()
{
    if (m_IsManufacturer != 0)
    {
        std::string strRepr = "Name: " + m_Name.toStdString() + " Email: " + m_Email.toStdString() + " Is Manufacturer:" + " True";
        return strRepr;
    }

    std::string strRepr = "Name: " + m_Name.toStdString() + " Email: " + m_Email.toStdString() + " Manufacturer:" + " False";
    return strRepr;
}

#endif // VENDOR_H
