#include <QMetaEnum>
#include <QLabel>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "GadgetTest.h"

using namespace gadget;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<P2D>();
    qRegisterMetaType<Player>();
    qRegisterMetaType<PlayerType>();

    createForm();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createForm(){

    wdg = new QWidget(this);

    scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    content_widget = new QWidget;

    Player myPlayer;

    form = new QFormLayout(content_widget);
    form->setVerticalSpacing(40);
    form->setLabelAlignment(Qt::AlignRight);

    QMetaObject metaobject = myPlayer.staticMetaObject;
    int count = metaobject.propertyCount();

    for (int i=0; i < count; ++i) {

        QMetaProperty metaproperty = metaobject.property(i);
        const char *name = metaproperty.name();
        QString type = metaproperty.typeName();

        if (type == "float"){
            doubleSpinBox = new QDoubleSpinBox;
            fieldName = new QLabel(name);
            form->addRow(fieldName, doubleSpinBox);
        } else if (type == "ushort") {
            spinBox = new QSpinBox;
            fieldName = new QLabel(name);
            form->addRow(fieldName, spinBox);
        } else if (type == "uchar") {
            spinBox = new QSpinBox;

            fieldName = new QLabel(name);
            form->addRow(fieldName, spinBox);

            coordFormFrame = new QFormLayout();
            coordFormFrame->setSpacing(10);

            QObject::connect(spinBox, &QSpinBox::valueChanged, this, &MainWindow::on_spinBoxValueChanged);

            QVariant var = metaproperty.readOnGadget(&myPlayer);
            spinBox->setValue(var.toInt());
            spinBox->setMinimum(1);

            form->addRow("coordinates", coordFormFrame);

        } else if (type == "bool") {
            checkBox = new QCheckBox;
            fieldName = new QLabel(name);
            form->addRow(fieldName, checkBox);

        } else if (metaproperty.isEnumType()){

            comboBox = new QComboBox;
            QMetaEnum metaEnum = metaproperty.enumerator();

            for (int i= 0;i < sizeof(metaEnum.keyCount()) ; i++) {
                comboBox->addItem(metaEnum.key(i));

            }
            fieldName = new QLabel(name);
            form->addRow(fieldName, comboBox) ;

        }

    }

    scrollArea->setWidget(content_widget);
    wdg->setLayout(new QVBoxLayout);
    wdg->layout()->addWidget(scrollArea);
    setCentralWidget(wdg);

}

void MainWindow::on_spinBoxValueChanged(int arg1){

    for (int i = coordFormFrame->rowCount(); i <= arg1 ; i++ ) {
        x = new QSpinBox;
        y = new QSpinBox;

        coordinatesForm = new QFormLayout;
        coordinatesForm->setVerticalSpacing(10);
        coordinatesForm->addRow("  x  ", x);
        coordinatesForm->addRow("  y  ", y);
        QString coordStr = "coordinate";
        coordStr.append(QString::number(i+1));

        coordFormFrame->addRow(coordStr, coordinatesForm);
    }

    while (coordFormFrame->rowCount() != arg1){
        coordFormFrame->removeRow(coordFormFrame->rowCount()-1);
    }

}

#include "moc_GadgetTest.cpp"
