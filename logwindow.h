#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QtWidgets/QPlainTextEdit>

class LogWindow : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit LogWindow(QWidget *parent = nullptr);
};

#endif // LOGWINDOW_H
