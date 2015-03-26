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

#include "CheckerboardPrinter.hpp"
#include "ui_CheckerboardPrinter.h"

#include <QPainter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>

CheckerboardPrinter::CheckerboardPrinter(QWidget *parent) : QMainWindow(parent), ui(new Ui::CheckerboardPrinter) {
    ui->setupUi(this);
}

CheckerboardPrinter::~CheckerboardPrinter() {
    delete ui;
}

void CheckerboardPrinter::print(QPrinter *printer) {
    //convert tile size from metric units to pixels
    int tileSize = ((float)ui->tileSize->value() * (float)printer->height()) / printer->heightMM();

    //compute margins
    int hMargin = (printer->width() - ui->columns->value() * tileSize) / 2;
    int vMargin = (printer->height() - ui->rows->value() * tileSize) / 2;

    QPainter painter;
    painter.begin(printer);

    for (int r = 0; r < ui->rows->value(); r++) {
        for (int c = 0; c < ui->columns->value(); c++) {
            QRect rect(hMargin + c*tileSize, vMargin + r*tileSize, tileSize, tileSize);

            if (r % 2 == 0) {
                if (c % 2 == 0) {
                    painter.fillRect(rect, Qt::black);
                } else {
                    painter.fillRect(rect, Qt::white);
                }
            } else {
                if (c % 2 == 0) {
                    painter.fillRect(rect, Qt::white);
                } else {
                    painter.fillRect(rect, Qt::black);
                }
            }
        }
    }

    painter.end();
}

void CheckerboardPrinter::on_previewButton_clicked() {
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
    preview.exec();
}

void CheckerboardPrinter::on_printButton_clicked() {
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer, this);

    if (dialog.exec() == QDialog::Accepted) {
        print(&printer);
    }
}
