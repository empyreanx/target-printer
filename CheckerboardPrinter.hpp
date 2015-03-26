/*
    Copyright (c) 2013 James McLean

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#ifndef CHECKERBOARD_PRINTER_H
#define CHECKERBOARD_PRINTER_H

#include <QMainWindow>
#include <QPrinter>

namespace Ui {
    class CheckerboardPrinter;
}

class CheckerboardPrinter : public QMainWindow {
    Q_OBJECT
    
public:
    explicit CheckerboardPrinter(QWidget *parent = 0);
    ~CheckerboardPrinter();
    
private slots:
    void print(QPrinter* printer);

    void on_previewButton_clicked();

    void on_printButton_clicked();

private:
    Ui::CheckerboardPrinter *ui;
};

#endif // CHECKERBOARD_PRINTER_H
