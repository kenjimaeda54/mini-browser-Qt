#ifndef MINI_BROWSER_H
#define MINI_BROWSER_H

#include <QMainWindow>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class Mini_browser; }
QT_END_NAMESPACE

class Mini_browser : public QMainWindow
{
    Q_OBJECT

public:
    Mini_browser(QWidget *parent = nullptr);
    ~Mini_browser();

private slots:
    void on_btn_search_clicked();

private:
    Ui::Mini_browser *ui;
};
#endif // MINI_BROWSER_H
