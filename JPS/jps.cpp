#include "jps.h"
#include "ui_jps.h"

JPS::JPS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JPS)
{
    ui->setupUi(this);
    fPainter = new QPainter(this);
    space = new Map();

    std::ifstream input("space1.txt");
    input >> *space;
    input.close();

    type_draw = 0; // 0 = block
                   // 1 = start
                   // 2 = finish
}

JPS::~JPS()
{
    delete fPainter;
    delete space;
    delete ui;
}

void JPS::errorMessage(const std::string & m){
    QMessageBox::critical(this,
    "Error",
    m.data(),
    QMessageBox::Yes | QMessageBox::Default
    );
}

void JPS::on_pushButton_clicked()
{
    bool S = false;
    bool F = false;
    for(int i = 0; i < space->get_width(); i++){
        for(int j = 0; j < space->get_height(); j++){
            if('X' == space->get_value(i, j)){
                F = true;
            }
            if('S' == space->get_value(i, j)){
                S = true;
            }
        }
    }
    if((F != true) || (S != true)){
        errorMessage("Not find START || FINISH");
    }else{
        space->clear_path();
        Robot rob(space, ui->comboBox->itemText(ui->comboBox->currentIndex()).toStdString());
        Search fp(&rob);
        space->draw_path(fp.find());
        update();
    }
}

void JPS::paintEvent(QPaintEvent * event){

    int size = min(this->size().width(), this->size().height())/(max(space->get_width(), space->get_height())+1);
    fPainter->begin(this);
    fPainter->setBrush(QColor(255,255,255));
    fPainter->drawRect(350, 20, space->get_width()*size, space->get_height()*size);
    for(int i = 0; i <= space->get_height(); ++i){
        fPainter->drawLine(350, size*i+20, 350+space->get_width()*size, i*size+20);
    }
    for(int i = 0; i <= space->get_width(); ++i){
        fPainter->drawLine(size*i+350, 20, i*size+350, 20+space->get_height()*size);
    }
    for(int i = 0; i < space->get_width(); ++i){
        for(int j = 0; j < space->get_height(); ++j){
            if('#' == space->get_value(i, j)){
                fPainter->setBrush(QColor(50,50,50));
                fPainter->drawRect(size*i+350, size*j+20, size, size);
            }
            if('S' == space->get_value(i, j)){
                fPainter->setBrush(QColor(0,255,0));
                fPainter->drawRect(size*i+350, size*j+20, size, size);
            }
            if('X' == space->get_value(i, j)){
                fPainter->setBrush(QColor(255,0,0));
                fPainter->drawRect(size*i+350, size*j+20, size, size);
            }
            if('L' == space->get_value(i, j)){
                fPainter->setBrush(QColor(105,55,25));
                fPainter->drawRect(size*i+350, size*j+20, size, size);
            }
            if('?' == space->get_value(i, j)){
                fPainter->setBrush(QColor(255,255,0));
                fPainter->drawRect(size*i+350, size*j+20, size, size);
            }
        }
    }
    fPainter->end();
}


void JPS::on_pushButton_2_clicked()
{ 
    std::ifstream input(ui->lineEdit->text().toStdString());
    if(!input){
        errorMessage("Invalid file name");
    }else{
        space->Clean();
        input >> *space;
        input.close();
        update();
    }
}

void JPS::on_pushButton_3_clicked()
{
    ofstream file(ui->lineEdit_2->text().toStdString());
    file << *space;
    file.close();
}

void JPS::on_pushButton_4_clicked()
{
    int h = ui->lineEdit_4->text().toInt();
    int w = ui->lineEdit_3->text().toInt();
    if((h < 5) || (h > 150) || (w < 5) || (w > 150)){
        errorMessage("Invalid size of map");
    }else{
        space->set_height(ui->lineEdit_4->text().toInt());
        space->set_width(ui->lineEdit_3->text().toInt());
    }
    update();
}

void JPS::mousePressEvent(QMouseEvent * e){
    int x = e->pos().x();
    int y = e->pos().y();
    int size = min(this->size().width(), this->size().height())/(max(space->get_width(), space->get_height())+1);
    if((x < 350) || (x > 350+size*space->get_width())){
        return;
    }
    if((y < 20) || (y > 20+size*space->get_height())){
        return;
    }
    x -= 350;
    y -= 20;
    x /= size;
    y /= size;
    char draw = '#';
    if(1 == type_draw){
        draw = 'S';
    }
    if(2 == type_draw){
        draw = 'X';
    }
    if(space->get_value(x, y) == '.'){
            if('S' == draw){
                POINT t;
                t.x = x;
                t.y = y;
                for(int i = 0; i < space->get_width(); i++){
                    for(int j = 0; j < space->get_height(); j++){
                        if('S' == space->get_value(i, j)){
                            space->set_value(i, j, '.');
                        }
                    }
                }
                space->set_start(t);
            }
            if('X' == draw){
                POINT t;
                t.x = x;
                t.y = y;
                for(int i = 0; i < space->get_width(); i++){
                    for(int j = 0; j < space->get_height(); j++){
                        if('X' == space->get_value(i, j)){
                            space->set_value(i, j, '.');
                        }
                    }
                }
                space->set_finish(t);
            }
            space->set_value(x, y, draw);
    }else
    if(space->get_value(x, y) == draw){
        space->set_value(x, y, '.');
    }
    update();
}

void JPS::on_pushButton_5_clicked()
{
    space->clear_path();
    update();
}

void JPS::on_pushButton_6_clicked()
{
    type_draw = 0;
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
}

void JPS::on_pushButton_7_clicked()
{
    type_draw = 1;
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(true);
}

void JPS::on_pushButton_8_clicked()
{
    type_draw = 2;
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(false);
}

void JPS::on_pushButton_9_clicked()
{
    for(int i = 0; i < space->get_width(); i++){
        for(int j = 0; j < space->get_height(); j++){
            if(('X' != space->get_value(i, j)) && ('S' != space->get_value(i, j))){
                space->set_value(i, j, '.');
            }
        }
    }
    update();
}
