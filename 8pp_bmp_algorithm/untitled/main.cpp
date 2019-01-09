#include <QCoreApplication>
#include <qbytearray.h>
#include <qdebug.h>
#include "MyFun.h"
#include "MyDib.h"

#define amp 2

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyDib* test = new MyDib();
    test->Open("11.bmp");
    printf("%d,%d,%d,%d",test->GetHeight(),test->GetWidth(),test->GetBiBitCount(),
           test->GetSize());
//    bpp82grayscale(test->GetHeight(),test->GetWidth(),test->m_pDibBits);
    int h = test->GetHeight()*amp;
    int w = test->GetWidth()*amp;

    BYTE *tttt = (BYTE*)malloc(h*w*sizeof (BYTE)*3);
//    interpolation(test->m_pDibBits, test->GetHeight(),test->GetWidth(),tttt, h, w,test->GetBiBitCount()/8);
    bilinera_interpolation(test->m_pDibBits, test->GetHeight(),test->GetWidth(),tttt, h, w, test->GetBiBitCount()/8);

    test->SetBits(tttt);

 //   Erodible(test->m_pDibBits,test->m_pDibBits,w,h);
    //Binary(test->m_pDibBits,test->m_pDibBits,w,h,0x7f);
 //   Mean_method(test->m_pDibBits,test->m_pDibBits,w,h);

    test->Save("asssssas.bmp",h,w);

    return a.exec();
}
