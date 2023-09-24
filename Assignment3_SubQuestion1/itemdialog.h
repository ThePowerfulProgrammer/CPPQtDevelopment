#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\item.h"
#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>




class ItemDialog : public QDialog {
public:
    static Item* addItem();
    static Item* changeItem(Item* item);

private:
    QLineEdit *barcode;
    QLineEdit *description;
    QSpinBox *stock;
    QDoubleSpinBox *price;

    ItemDialog(QWidget *parent = 0);
};

#endif // ITEMDIALOG_H


