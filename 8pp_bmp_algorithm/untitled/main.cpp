#include <QCoreApplication>
#include <qbytearray.h>
#include <qdebug.h>
#include "MyFun.h"
#include "MyDib.h"

#define amp 2
#define h 96*amp
#define w 384*amp

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyDib* test = new MyDib();
    test->Open("11111.bmp");
    printf("%d,%d,%d,%d",test->GetHeight(),test->GetWidth(),test->GetBiBitCount(),
           test->GetSize());
 //   QByteArray asu = QByteArray::fromRawData((char*)test->GetBits(),test->GetSize()*3);
 //   qDebug() << asu.toHex();
   // Median(test->m_pDibBits,test->m_pDibBits,test->GetWidth(),test->GetHeight());
//    bpp82grayscale(test->GetHeight(), test->GetWidth(),test->m_pDibBits);

    BYTE tttt[h][w];
    bilinera_interpolation(test->m_pDibBits, test->GetHeight(),test->GetWidth(),tttt[0], h, w);
 //   interpolation(test->m_pDibBits, test->GetHeight(),test->GetWidth(),tttt[0], h, w);
    test->SetBits(&tttt[0][0]);
 //   Image_smooth(test->m_pDibBits,test->m_pDibBits,96*2,384*2);
    Binary(test->m_pDibBits,test->m_pDibBits,h,w,0x7f);
    test->Save("asssssas.bmp",h,w);

    return a.exec();
}
