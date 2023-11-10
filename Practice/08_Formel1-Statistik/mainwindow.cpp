#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("/mnt/sda2/programming_projects/5_Klasse_POS/Practice/08_Formel1-Statistik/Formula1.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

    QSqlError daoError = qx::dao::fetch_all(this->driver_list);
    this->current_search = this->driver_list;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // Empty QList
    this->current_search = QList<drivers>();
    this->ui->driverCombobox->clear();
    std::copy_if(this->driver_list.begin(), this->driver_list.end(),
        std::back_inserter(this->current_search),
        [&](drivers d) {
            std::string re_string = (QString("^.*") + arg1 + QString(".*")).toStdString();
            std::regex re(re_string);
            std::string driver_name = (d.d_forename + QString(" ") + d.d_surname).toStdString();
            return std::regex_match(driver_name,re);
        }
    );

    std::for_each(this->current_search.begin(), this->current_search.end(), [&](drivers d){
        QString combined_name = d.d_forename + QString(" ") + d.d_surname;
        this->ui->driverCombobox->addItem(combined_name);
    });
}


void MainWindow::on_pushButton_clicked()
{
    // Empty QList
    this->current_search = QList<drivers>();
    this->ui->driverCombobox->clear();
    std::copy_if(this->driver_list.begin(), this->driver_list.end(),
        std::back_inserter(this->current_search),
        [&](drivers d) {
            std::string re_string = (QString("^.*") + this->ui->lineEdit->text() + QString(".*$")).toStdString();
            std::regex re(re_string);
            std::string driver_name = (d.d_forename + QString(" ") + d.d_surname).toStdString();
            return std::regex_match(driver_name,re);
        }
    );

    std::for_each(this->current_search.begin(), this->current_search.end(), [&](drivers d){
        QString combined_name = d.d_forename + QString(" ") + d.d_surname;
        this->ui->driverCombobox->addItem(combined_name);
    });
}


void MainWindow::on_driverCombobox_currentIndexChanged(int index)
{
}


void MainWindow::on_driverCombobox_activated(int index)
{
    auto item = this->driver_list.at(this->ui->driverCombobox->currentIndex());
    std::cout << item.d_surname.toStdString() << " " << item.d_forename.toStdString() << std::endl;
    qx::QxSqlQuery q = qx::QxSqlQuery("WHERE driver.d_forename=:forename AND driver.d_surname=:surname");
    q.bind(":forename", item.d_forename);
    q.bind(":surname", item.d_surname);

    drivers::list_drivers d_list;
    auto x = qx::dao::fetch_by_query(q, d_list);
}

