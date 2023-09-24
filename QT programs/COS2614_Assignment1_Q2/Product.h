#ifndef PRODUCT_H
#define PRODUCT_H
#include "Vendor.h"

class Product
{
    public:
        Product(QString name, double price);
        // ctor sets member vars

        void setSupplier(QString name, QString email, bool isManufacturer);
        // PC: uses supplied params to call Vendor::setDetails(name,email,isManufacturer)

        QString getManufacturerName();
        // PC: returns m_Supplier is it exists else returns "Unknown"

        std::string toString(bool supplierDetails);
        // PreCon: supplierDetails
        // if True returns a string representation of both supplier(Vendor::toString()) and product else
        // returns string representation of only Product

    protected:

    private:
        QString m_Name;
        double m_Price;
        Vendor m_Supplier;

};




Product::Product(QString name,double price) :
    m_Name(name),
    m_Price(price),
    m_Supplier()
{
    // ctor 2 params
}

void Product::setSupplier(QString name, QString email, bool isManufacturer)
{
    m_Supplier.setDetails(name,email,isManufacturer);
}


QString Product::getManufacturerName()
{
    if (m_Supplier.getName() == " ")
    {
        return "Unknown";
    }
    else
    {
        return m_Supplier.getName();
    }
}


std::string Product::toString(bool supplierDetails)
{
    if (supplierDetails == true)
    {
        std::string strRepr = "Product Name: " + m_Name.toStdString() + " Price: " + QString::number(m_Price).toStdString() + " " + m_Supplier.toString();
        return strRepr;
    }
    std::string strRepr = "Product Name: " + m_Name.toStdString() + " Price: " + QString::number(m_Price).toStdString();
    return strRepr;
}

#endif // PRODUCT_H
