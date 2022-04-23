# Mini browser
Criar um mini browser para praticar o conceito de text browser


## Motivacao 
Aperfeicoar conhecimento em Qt e aplciar conceitos de text browser


## Feature
- Precisei da dependência do webengine para funcionar o projeto
- [Pacman](https://archlinux.org/packages/extra/x86_64/qt5-webengine/)
- sudo apt install qtwebengine5-dev ==> derivados debian
- Precisa declarar a dependência no arquivo .pro
- Tambem instanciei no cabeçalho do arquivo .h o QWebEngineView
- Logica e simples instancie a classe QwebEngineView para carregar as url
- Precisa sempre fechar o textBrowser para garantir que a pagina sempre vai carregar em uma nova widget de text browser
- Apos fechar podemos  adicionar no gridlayout o widget que foi instanciado 
- Para adicionar a url de forma dinâmica usei o input do label edit



``` c++
//.pro
QT       += core gui   webenginewidgets


//================
//.h
#ifndef MINI_BROWSER_H
#define MINI_BROWSER_H

#include <QMainWindow>
#include <QWebEngineView>



//===========
//.cpp
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






```
