#include "QtGui/QMainWindow"
#include "QtGui"
#include "HelloWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    HelloWidget * _helloWidget;
    QPushButton * _button;
    //main layout
    QVBoxLayout * _layout;
    //layout for search
    QHBoxLayout * _layout_frame;
    QHBoxLayout * _layout_frame_age;
    QHBoxLayout * _layout_frame_location;
    //layout for images
    
    //main images layout
    QHBoxLayout * _layout_images;
    //founded images
    QHBoxLayout * _layout_founded_image;
    //you last photo
    QHBoxLayout * _layout_you_last_photo;
    
    
    QHBoxLayout * _layout_button;
    QGroupBox * _groupBox_search;
    QLabel * _age_from;
    QLabel * _location_city;

    
private:
    void _SetLayout();
};