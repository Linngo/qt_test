#include <QCoreApplication>
#include <qdebug.h>
#include <QFile>
#include <QDataStream>
#include <qbytearray.h>
#include <qstring.h>
#include <Windows.h>

#define data_size 1152//36
#define part 3
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 i =0;

//    unsigned long *tmp;
    QString file_name;
    if (argc == 2)
    {
        file_name = argv[1];
    }else
        file_name = "test.bin";

    QFile file_read(file_name);
    QFile file_bin("out.bmp");
    if(!file_read.open(QIODevice::ReadOnly) ||!file_bin.open(QIODevice::WriteOnly | QIODevice::Append)) //
    {
        qDebug() <<"read or output file don't exist!";
    }
    else
    {
        QDataStream out(&file_bin);
        QDataStream in(&file_read);
        qint64 totalBytes = file_read.size();

        BITMAPFILEHEADER head;
        memset(&head,0,sizeof(head));
        head.bfType = *((WORD *)"BM");
        head.bfOffBits = 0x3e;

        BITMAPINFOHEADER info;
        memset(&info,0,sizeof(info));
        info.biSize = 40;
        info.biWidth =  24*4;
        info.biHeight = 12*32;
        info.biPlanes = 1;
        info.biBitCount = 1;

        DWORD DataSizePerLine= (info.biWidth* info.biBitCount+31)/32*4;
        info.biSizeImage = DataSizePerLine*info.biHeight;

        RGBQUAD rgb[2];
        rgb[0]={ 0, 0, 0, 0};
        rgb[1]={0xff,0xff,0xff,0};

        head.bfSize = info.biSizeImage + 14 + info.biSize +sizeof(rgb);

        file_bin.write((char *)&head,sizeof(BITMAPFILEHEADER));
        file_bin.write((char *)&info,sizeof(BITMAPINFOHEADER));
        file_bin.write((char *)rgb,sizeof(rgb));

        QByteArray data,data1;

        data.resize(data_size);
        in.readRawData(data.data(),data_size);

        for(i=1;i<totalBytes/data_size;i++){
            data1.clear();
            data1.resize(data_size);
            in.readRawData(data1.data(),data_size);

            char *tmp = data1.data();
            int num = 0;
            for(int k=0;k<data_size/part;k++)
            {
                data.insert(part*i*(k+1)+num, tmp, part);
                num += part;
                tmp += part;
            }
        }

//        QByteArray b(data.size(),0);
//        std::copy(data.crbegin(),data.crend(),b.begin());

        file_bin.write(data);
        printf("%d",data.size());
        file_bin.flush();

/*
        for(i=0;i<totalBytes/data_size;i++){
            data.clear();
            data.resize(data_size);
            in.readRawData(data.data(),data_size);

            int num = 0;
            for(int k=0;k<data_size/3;k++)
            {
                data.insert(3*(k+1)+num,(char)'0x00');
                num++;
            }

            file_bin.write(data);
            qDebug() << data.size();
            file_bin.flush();
        }
*/
        data.clear();
    }

    file_bin.close();
    file_read.close();

    exit(0);
    return a.exec();
}
