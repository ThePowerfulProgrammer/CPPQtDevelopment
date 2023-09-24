#include "itemdialog.h"
#include <QFormLayout>
#include <QPushButton>



ItemDialog::ItemDialog(QWidget *parent) : QDialog(parent) {
    barcode = new QLineEdit(this);
    description = new QLineEdit(this);
    stock = new QSpinBox(this);
    stock->setValue(0);
    stock->setSingleStep(1);
    stock->setMaximum(100);
    price = new QDoubleSpinBox(this);
    price->setValue(0.0);
    price->setMaximum(20000);
    price->setSingleStep(1.0);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow("Barcode", barcode);
    layout->addRow("Description", description);
    layout->addRow("Stock", stock);
    layout->addRow("Price", price);

    QPushButton *okButton = new QPushButton("OK", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    // use built in signals and slots
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    setLayout(layout);
}

Item* ItemDialog::addItem()
{
    ItemDialog dialog; // create our Widget
    dialog.setWindowTitle("Create Iterm");
    if (dialog.exec() == QDialog::Accepted)
    {
        return new Item(dialog.barcode->text(), dialog.description->text(), dialog.stock->value(), dialog.price->value());
    }
    return 0;
}

Item* ItemDialog::changeItem(Item* item)
{
    if(item == 0)
    {
        return 0;
    }

    ItemDialog dialog; // create our Widget
    dialog.setWindowTitle("Change Iterm");
    dialog.barcode->setText(item->getBarcode());
    dialog.description->setText(item->getDescription());
    dialog.stock->setValue(item->getStock());
    dialog.price->setValue(item->getPrice());

    if (dialog.exec() == QDialog::Accepted)
    {
        return new Item(dialog.barcode->text(),dialog.description->text(),dialog.price->value(),dialog.stock->value());
    }

    return 0;
}



