#include "mini_browser.h"
#include "ui_mini_browser.h"


Mini_browser::Mini_browser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mini_browser)
{
    ui->setupUi(this);
    QWebEngineView  *view = new QWebEngineView;   //tem que ser apos a ui foi instanciada
    view->load( QUrl("https://github.com/kenjimaeda54") );
    ui->textBrowser->close();                    //preciso fechar o textBrowser so apos isto conseguira inicia
    ui->gridLayout->addWidget(view); //para adiconar qualquer widget em um layou no formato grid
}

Mini_browser::~Mini_browser()
{
    delete ui;
}


void Mini_browser::on_btn_search_clicked()
{
     if(ui->field_input->text().isEmpty()) return;
     QWebEngineView *view = new QWebEngineView;
     view->load( QUrl(ui->field_input->text()));
     ui->textBrowser->close();

     QWidget  *widget = ui->gridLayout->itemAt(1)->widget(); // gridLayout e uma colecao com os layout,estou pegando a primeira posicao e deletando,intemAt e uma funcao dos container
     delete widget;
     ui->gridLayout->addWidget(view);
}

