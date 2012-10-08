#include "QtGui/QApplication"
#include "QtGui"
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

    _layout = new QVBoxLayout();
    _layout_button = new QHBoxLayout();
    _layout_frame = new QHBoxLayout();
    _layout_frame_age = new QHBoxLayout();
    _layout_frame_location = new QHBoxLayout();
    _groupBox_search = new QGroupBox(tr("Search"));
    _age_from = new QLabel("From");
    _location_city = new QLabel("Select City");
    _layout_images = new QHBoxLayout();
    _layout_you_last_photo = new QHBoxLayout();
    _layout_founded_image = new QHBoxLayout();
    // Setting the content and disposition of our central Widget
    _SetLayout();
    centralWidget->setLayout(_layout);
}

void MainWindow::_SetLayout()
{
    _layout->addWidget(_helloWidget);
    _layout->addWidget(_groupBox_search);

    //--------------------------------------------------------------------------
    //Top layout block 
    _groupBox_search->setLayout(_layout_frame);
    _groupBox_search->setStyleSheet("QGroupBox{ border: 1px solid #d5d5d5;" "border-radius: 3px;" "margin-bottom: 10px; }");
    _layout_frame->addLayout(_layout_frame_age);
    _layout_frame->addLayout(_layout_frame_location);
    _layout_frame_age->addWidget(_age_from);
    _layout_frame_location->addWidget(_location_city);

    //--------------------------------------------------------------------------
    //Middle layout block 
    _layout->addLayout(_layout_images);
    _layout_images->addLayout(_layout_founded_image);
    _layout_images->addLayout(_layout_you_last_photo);
    
    //--------------------------------------------------------------------------
    //Bottom layout block 
    _layout->addLayout(_layout_button);
    _layout_button->setAlignment(Qt::AlignRight);
    _layout_button->addWidget(_button);
    _layout_button->addStretch(10);
}

MainWindow::~MainWindow()
{
    delete _layout;
    delete _layout_button;
    delete _layout_frame;
    delete _layout_frame_age;
    delete _layout_frame_location;
    delete _groupBox_search;
    delete _button;
    delete _helloWidget;
    delete _age_from;
    delete _layout_images;
    delete _layout_you_last_photo;
    delete _layout_founded_image;
}