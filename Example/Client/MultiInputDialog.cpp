#include "MultiInputDialog.h"

MultiInputDialog::MultiInputDialog(QWidget *parent, const QString &_title) :
    QDialog(parent), title(_title)
{
    form = new QFormLayout(this);
    QDialog::resize(300,80);
}

QList<QLineEdit *> MultiInputDialog::getFields() const
{
    return fields;
}

void MultiInputDialog::setFields(const QList<QLineEdit *> &value)
{
    fields = value;
}

void MultiInputDialog::addRow(const QString &label,
                              QLineEdit::EchoMode echo,
                              const QString &text)
{
    QLineEdit *lineEdit = new QLineEdit(text, this);
    lineEdit->setEchoMode(echo);
    form->addRow(label, lineEdit);
    fields << lineEdit;
}

void MultiInputDialog::exec()
{
    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, this);
    form->addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), this, SLOT(close()));
    QObject::connect(&buttonBox, SIGNAL(accepted()), this, SIGNAL(accepted()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), this, SLOT(close()));

    QDialog::exec();
}
