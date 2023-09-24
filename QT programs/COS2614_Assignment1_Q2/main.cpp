#include <QString>
#include <iostream>
#include "Product.h"
#include <string.h>

/*
Implement it as a console application, where the product and supplier details are entered from the
keyboard. Display the results of getManufacturerName() and toString()(for both true
and false parameter values) on the console

Problems:
    QTextStream cannot input boolean values via console
    std::cin >> bool (WRONG)
    std::cin >> std::boolalpha >> bool ; (RIGHT)
*/

int main()
{
    // Working program :)

    std::string productName;
    double productPrice;


    // Product details
    std::cout << "Enter product Name: ";
    std::cin >> productName;

    std::cout << "Enter product price: eg(19.99): ";
    std::cin >> productPrice;

    // Conversion
    QString productNameQStr = QString::fromStdString(productName);

    Product product(productNameQStr, productPrice);

    std::string vNameStr;
    std::string vEmailStr;
    bool isM;


    // Supplier details
    std::cout << "Enter Vendor Name: ";
    std::cin >> vNameStr;

    std::cout << "Enter Vendor email: ";
    std::cin >> vEmailStr;

    std::cout << "Enter if Vendor is Manufacturer(true/false): ";
    std::cin >> std::boolalpha >> isM;

    // Conversion
    QString vNameQStr = QString::fromStdString(vNameStr);
    QString vEmailQStr = QString::fromStdString(vEmailStr);

    product.setSupplier(vNameQStr, vEmailQStr,isM);

    std::cout << std::endl;
    std::cout << product.getManufacturerName().toStdString() << std::endl << std::endl;
    std::cout << product.toString(true) << std::endl << std::endl;
    std::cout << product.toString(false) << std::endl << std::endl;

    return 0;
}
