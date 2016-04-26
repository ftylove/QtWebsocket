#ifndef MULTIINPUTDIALOG_H
#define MULTIINPUTDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

class MultiInputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MultiInputDialog(QWidget *parent = 0, const QString &_title = QString());

    void addRow(const QString &label, QLineEdit::EchoMode echo,
                 const QString &text = QString());
    QList<QLineEdit *> getFields() const;
    void setFields(const QList<QLineEdit *> &value);

    void exec();
signals:

public slots:
private:
    const QString title;
    QFormLayout *form;
    QList<QLineEdit*> fields;
};

#endif // MULTIINPUTDIALOG_H
