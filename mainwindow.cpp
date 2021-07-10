#include <QMetaEnum>
#include <QLabel>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "GadgetTest.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createForm();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createForm(){

    int idP2D = qRegisterMetaType<P2D>();
    qRegisterMetaType<Player>();
    int idPlayerType = qRegisterMetaType<PlayerType>();

    wdg = new QWidget;

    scrollArea = new QScrollArea;

    content_widget = new QWidget;

    form = new QFormLayout(content_widget);
    form->setVerticalSpacing(40);
    form->setLabelAlignment(Qt::AlignRight);

    Player myPlayer;

    QMetaObject metaobject = myPlayer.staticMetaObject;

    int count = metaobject.propertyCount();

    for (int i=0; i<count; ++i) {

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
            spinBox->setValue(myPlayer.getm_numberOfCoordinates());
            fieldName = new QLabel(name);
            form->addRow(fieldName, spinBox);
            coordFormFrame = new QFormLayout();
            coordFormFrame->setSpacing(10);

            // Deve ser atraves de uma PROPERTY READ ao inves do get???
            // Deve ser em tempo-real quando muda a propriedade anterior??
            for (int i=0; i < spinBox->value() ; i++ ) {
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

           form->addRow("coordinates", coordFormFrame);

        } else if (type == "bool") {
            checkBox = new QCheckBox;
            fieldName = new QLabel(name);
            form->addRow(fieldName, checkBox);

            // Não consegui dar o retrieve no ENUM
        } else if (metaproperty.typeId() == idPlayerType){


            comboBox = new QComboBox;
            comboBox->addItem("NO_TYPE");
            comboBox->addItem("TANK");
            comboBox->addItem("CHARACTER");
            comboBox->addItem("SHIP");
            fieldName = new QLabel(name);
            form->addRow(fieldName, comboBox) ;

        } else if (metaproperty.typeId() == idP2D){

        }

    }

    scrollArea->setWidget(content_widget);
    wdg->setLayout(new QVBoxLayout);
    wdg->layout()->addWidget(scrollArea);
    setCentralWidget(wdg);

}
