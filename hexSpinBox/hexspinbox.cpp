#include <QtGui>

#include "hexspinbox.h"


HexSpinBox::HexSpinBox(QWidget *parent) : QSpinBox(parent)
{
    setRange(1,99);
    validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}


QValidator::State HexSpinBox::validate(QString &text, int &pos) const
{
    return validator->validate(text, pos);
}


QString HexSpinBox::textFromValue(int value) const
{
    return QString::number(value, 16).toUpper();
}

int HexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}
