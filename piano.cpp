#include "piano.h"

Piano::Piano(int height, int width)
{
    QString whiteKeys[14] = {"C", "D", "E", "F", "G", "A", "B", "C", "D", "E", "F", "G", "A", "B"};
    QString blackKeys[10] = {"C#", "D#", "F#", "G#", "A#", "C#", "D#", "F#", "G#", "A#"};
    //Layout setup
    QGridLayout* pvbxLayout = new QGridLayout;
    QHBoxLayout* phbxLayoutWhite = new QHBoxLayout;
    phbxLayoutWhite->setContentsMargins(28, 30, 28, 20);
    phbxLayoutWhite->setSpacing(0);
    for (int i = 0; i < 14; ++i) {
        phbxLayoutWhite->addWidget(createWhiteButton(whiteKeys[i], height, width));
    }

    QHBoxLayout* phbxLayoutBlack = new QHBoxLayout;
    phbxLayoutBlack->setSpacing(0);
    phbxLayoutBlack->setContentsMargins(28, 30, 28, 20 + height/2 - 25);
    QSpacerItem* transparent = new QSpacerItem(width/24 - 7, height);
    for (int i = 0; i < 10; ++i) {
        phbxLayoutBlack->addSpacerItem(transparent);
        phbxLayoutBlack->addWidget(createBlackButton(blackKeys[i], height, width));
        i++;
        phbxLayoutBlack->addSpacerItem(transparent);
        phbxLayoutBlack->addWidget(createBlackButton(blackKeys[i], height, width));
        phbxLayoutBlack->addSpacerItem(transparent);
        phbxLayoutBlack->addSpacerItem(transparent);
        i++;
        phbxLayoutBlack->addWidget(createBlackButton(blackKeys[i], height, width));
        phbxLayoutBlack->addSpacerItem(transparent);
        i++;
        phbxLayoutBlack->addWidget(createBlackButton(blackKeys[i], height, width));
        phbxLayoutBlack->addSpacerItem(transparent);
        i++;
        phbxLayoutBlack->addWidget(createBlackButton(blackKeys[i], height, width));
        phbxLayoutBlack->addSpacerItem(transparent);
    }
    pvbxLayout->addLayout(phbxLayoutWhite, 0, 0);
    pvbxLayout->addLayout(phbxLayoutBlack, 0, 0);
    setLayout(pvbxLayout);
}

template <typename T>
void font_size (T pointer, int size)
{
    QFont font = pointer->font();
    font.setPointSize(size);
    pointer->setFont(font);
}

QPushButton* Piano::createWhiteButton(const QString& str, int height, int width){
    QPushButton* pButton = new QPushButton(str);
    pButton->setStyleSheet("color: black; background-color: white");
    pButton->setMaximumSize(width/14 - 12, height - 50);
    font_size(pButton, 40);
    QSoundEffect* pKey = new QSoundEffect;
    pKey->setSource(QUrl::fromLocalFile(QString(":/sounds/%1.wav").arg(str)));
    connect(pButton, &QPushButton::clicked, pKey, &QSoundEffect::play);
    return pButton;
}

QPushButton* Piano::createBlackButton(const QString& str, int height, int width){
    QPushButton* pButton = new QPushButton(str);
    pButton->setStyleSheet("color: white; background-color: black");
    pButton->setMaximumSize(width/24 - 7, height/2 - 25);
    font_size(pButton, 40);
    QSoundEffect* pKey = new QSoundEffect;
    pKey->setSource(QUrl::fromLocalFile(QString(":/sounds/%1.wav").arg(str)));
    connect(pButton, &QPushButton::clicked, pKey, &QSoundEffect::play);
    return pButton;
}
