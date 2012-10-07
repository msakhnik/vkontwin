#include "QtGui/QApplication"
#include "QtGui/QBoxLayout"
#include "QtGui/QVBoxLayout"
#include "QtGui/QHBoxLayout"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    QWidget * centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    setWindowTitle("Main window");
    setSizeIncrement(400, 200);

    // Building our widgets
    _helloWidget = new HelloWidget(this);
    _button = new QPushButton(this);
    _button->setText("Add");
    _button->resize(75, 30);

    connect(_button, SIGNAL(clicked()), _helloWidget, SLOT(showNewLetter()));

    // Setting the content and disposition of our central Widget
    QVBoxLayout * layout = new QVBoxLayout();
    QHBoxLayout * layout_button = new QHBoxLayout();
    layout->addWidget(_helloWidget);
    layout->addLayout(layout_button);
    layout_button->addWidget(_button);
    layout_button->addStretch(10);
    centralWidget->setLayout(layout);
}



MainWindow::~MainWindow()
{
}