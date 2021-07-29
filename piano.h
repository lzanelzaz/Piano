#ifndef PIANO_H
#define PIANO_H

#include <QtWidgets>
#include <QtMultimedia>

class Piano : public QWidget
{
    Q_OBJECT

public:
    Piano(int height, int width);

    QPushButton* createWhiteButton(const QString& str, int height, int width);
    QPushButton* createBlackButton(const QString& str, int height, int width);
};
#endif // PIANO_H
