#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QFormLayout>
#include <QScrollArea>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QMetaObject>
#include "GadgetTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createForm();
public slots:
private slots:



    void on_spinBoxValueChanged (int arg1);

private:
    Ui::MainWindow *ui;

    QLabel *fieldName;

    QWidget *wdg;

    QWidget *content_widget;


    QScrollArea *scrollArea;
    QFormLayout *form;
    QFormLayout *coordinatesForm;
    QFormLayout *coordFormFrame;

    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox;

    QSpinBox *x, *y;

    QFrame *frame;
    QCheckBox *checkBox;


};

#endif // MAINWINDOW_H
