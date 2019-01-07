#include <QCoreApplication>
#include <qbytearray.h>
#include <qdebug.h>
#include "MyFun.h"
#include "MyDib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyDib* test = new MyDib();
    test->Open("image11.bmp");
    printf("%d,%d,%d,%d",test->GetHeight(),test->GetWidth(),test->GetBiBitCount(),
           test->GetSize());
 //   QByteArray asu = QByteArray::fromRawData((char*)test->GetBits(),test->GetSize()*3);
 //   qDebug() << asu.toHex();
   // Median(test->m_pDibBits,test->m_pDibBits,test->GetWidth(),test->GetHeight());
//    bpp82grayscale(test->GetHeight(), test->GetWidth(),test->m_pDibBits);

    BYTE tttt[240*2][320*2];
    bilinera_interpolation(test->m_pDibBits, test->GetHeight(),test->GetWidth(),tttt[0], 240*2, 320*2);
 //   Back_White(test->m_pDibBits, test->GetSize());
 //   test->SetBits(&tttt[0][0]);
    test->Save("asssssas.bmp",240,320);

    return a.exec();
}
