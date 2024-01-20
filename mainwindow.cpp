#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <QMessageBox>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cerrno>
#include <cstdio>


using namespace std;

// In hex
char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}
// Dec to x
int dectox_int(int a, int p, char *s)
{
    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = dectox_int(num, p, s);
    s[k++] = digit(rest);
    return k;
}
// Dec to x
void dectox_double(double a, int p, char *s)
{
    int iter = 0;
    int k = 0;
    double a1 = a;
    do {
        a1 = a1 * p;
        int num = (int)(a1);
        s[k++] = digit(num);
        a1 -= (int)a1;
        iter++;
    } while (a1 > 0.00000001 && iter < 10);
    s[k] = '\0';
}

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Rand_clicked()
{
    srand(time(NULL));
    rand();
    int n = rand()%(atoi(ui->maxRand->text().toLatin1().data()));
    ui->lineEdit->setText(QString::number(n));
}

// Dec to bin
void MainWindow::on_pushButton_clicked()
{
    QRegularExpression regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");

    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "10"){
                float a;
                int p;
                char s[80] = { 0 };
                a = atof(ui->lineEdit->text().toLatin1().data());
                if(a<0){
                    a = abs(a);
                }
                p = 2;
                int k = dectox_int((int)a, p, s);
                s[k++] = ',';
                dectox_double((double)a - (int)a, p, &s[k]);
                ui->lineEdit_2->setText(s);
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }

    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}
// Dec to octal
void MainWindow::on_pushButton_2_clicked()
{
    QRegularExpression regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "10"){
                float a;
                int p;
                char s[80] = { 0 };
                a = atof(ui->lineEdit->text().toLatin1().data());
                if(a<0){
                    a = abs(a);
                }
                p = 8;
                int k = dectox_int((int)a, p, s);
                s[k++] = ',';
                dectox_double((double)a - (int)a, p, &s[k]);
                ui->lineEdit_3->setText(s);
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }
    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}
// Dec to hex
void MainWindow::on_pushButton_3_clicked()
{
    QRegularExpression regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "10"){
                float a;
                int p;
                char s[80] = { 0 };
                a = atof(ui->lineEdit->text().toLatin1().data());
                if(a<0){
                    a = abs(a);
                }
                p = 16;
                int k = dectox_int((int)a, p, s);
                s[k++] = ',';
                dectox_double((double)a - (int)a, p, &s[k]);
                ui->lineEdit_4->setText(s);
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }
    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}

unsigned long my_stoul (std::string const& str, size_t *idx = 0, int base = 16) {
    char *endp;
    unsigned long value = strtoul(str.c_str(), &endp, base);
    if (endp == str.c_str()) {
        throw std::invalid_argument("my_stoul");
    }

    if (value == ULONG_MAX && errno == ERANGE) {
        throw std::out_of_range("my_stoul");
    }
    if (idx) {
        *idx = endp - str.c_str();
    }
    return value;
}

const char* ConvertDoubleToString(double value){
    std::stringstream ss ;
    ss << value;
    const char* str = ss.str().c_str();
    return str;
}
// Hex to Dec
void MainWindow::on_pushButton_4_clicked()
{
    QRegularExpression regex("^[A-F0-9.]+$");
    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "16"){
                string a, b ;
                string n(ui->lineEdit->text().toLatin1().data());

                size_t p = n. find ( '.' ) ;
                // From the beginig to point
                a = n. substr (0,p) ;
                // From point to the end
                b = n. substr (p+ 1) ;

                double r = my_stoul(a,NULL ,16)+my_stoul( b,NULL,16)/pow(16,b.size());
                const char* s = ConvertDoubleToString(r);
                ui->lineEdit_5->setText(s);
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }
    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}
// Bin to Dec
double binaryToDecimal(string binary, int len)
{
    size_t point = binary.find('.');

    if (point == string::npos)
        point = len;

    double intDecimal = 0, fracDecimal = 0, twos = 1;

    // Int bin to dec
    for (int i = point-1; i>=0; --i)
    {

        intDecimal += (binary[i] - '0') * twos;
        twos *= 2;
    }

    // Bin double to dec
    twos = 2;
    for (int i = point+1; i < len; ++i)
    {
        fracDecimal += (binary[i] - '0') / twos;
        twos *= 2.0;
    }

    return intDecimal + fracDecimal;
}
// Bin to dec button
void MainWindow::on_pushButton_5_clicked()
{
    QRegularExpression regex("^[0-1.]+$");
    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "2"){
                string n(ui->lineEdit->text().toLatin1().data());
                double d = binaryToDecimal(n,n.length());
                QString s = ConvertDoubleToString(d);
                ui->lineEdit_6->setText(s);
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }
    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}
// Octal to Dec button
void MainWindow::on_pushButton_6_clicked()
{
    QRegularExpression regex("^[0-7.]+$");
    if(ui->lineEdit->text().contains(regex)){
        if(ui->lineEdit->text() == ""){
            QMessageBox::critical(this,"Error", "Line edit is empty");
        }
        else{
            if(ui->comboBox->currentText() == "8"){
                const char *text = ui->lineEdit->text().toLatin1().data();
                unsigned int integer_part, fraction_part, len1, len2;
                double result;
                sscanf(text,"%o.%n%o%n", &integer_part, &len1, &fraction_part, &len2);
                result = fraction_part * 1.0 / (1<<(len2-len1)*3);
                result += integer_part;
                ui->lineEdit_7->setText(ConvertDoubleToString(result));
            }
            else{
                QMessageBox::critical(this,"Error", "It is a wrong system");
            }
        }
    }
    else{
        QMessageBox::critical(this,"Error", "Wrong symbol");
    }
}
// Clear button
void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
}


