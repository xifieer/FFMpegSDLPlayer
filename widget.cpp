#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

#include "SDL2/SDL.h"
#include "ffmpegdecode.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_pSDLPlayer = new SDLPlayer();
    m_pFFMpegDecode = new FFMpegDecode();
    m_pFFMpegDecode->SetSDLPlayer(m_pSDLPlayer);
}

Widget::~Widget()
{
    if(m_pFFMpegDecode)
    {
        delete m_pFFMpegDecode;
        m_pFFMpegDecode = nullptr;
    }

    if(m_pSDLPlayer)
    {
        delete m_pSDLPlayer;
        m_pSDLPlayer = nullptr;
    }

    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                 tr("音乐文件"),
                                 "",
                                 tr("Musics (*.mp3 *.mp2 *.aac *.wma *.flac)")
                                 );

    if(fileName == "") return;

    if(m_pFFMpegDecode == nullptr) return;

    m_pFFMpegDecode->OpenMusicFile(fileName.toLatin1().data());
}
