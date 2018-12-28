#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QDataStream>
#include <QTime>

//const unsigned char shuipi[]=
//{
////UNICODE:0x30
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xE0, 0xF0, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9C, 0x39, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C,
//    0x1F, 0x80, 0x00, 0x03, 0xC0, 0x60, 0x00, 0x01, 0xE0, 0x19, 0x80, 0x00, 0x06, 0x00, 0x00, 0x1E,
//    0x00, 0x00, 0x03, 0x01, 0xE0, 0x70, 0xE1, 0x98, 0x07, 0x00, 0x00, 0x0F, 0xE0, 0x60, 0x00, 0x01,
//    0xE0, 0x06, 0x03, 0xC0, 0x00, 0x03, 0x9C, 0x39, 0xC0, 0x00, 0x0F, 0x06, 0x06, 0x78, 0x00, 0x7C,
//    0x3F, 0xC3, 0x9C, 0x07, 0x00, 0xF0, 0x39, 0xC0, 0x70, 0x19, 0x80, 0x00, 0x0F, 0x03, 0x9C, 0x07,
//    0x01, 0xCE, 0x07, 0x80, 0x70, 0x06, 0x01, 0x98, 0x0C, 0x00, 0x00, 0x0F, 0xE0, 0xF0, 0x39, 0xC0,
//    0x70, 0x0F, 0x00, 0xE0, 0x39, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x86, 0x06, 0x6D, 0x80, 0x60,
//    0x30, 0xC3, 0x9C, 0x0C, 0x01, 0x98, 0x39, 0xC0, 0x18, 0x19, 0x80, 0x00, 0x19, 0x83, 0x9C, 0x01,
//    0x81, 0xCE, 0x0C, 0xC0, 0x18, 0x06, 0x01, 0x98, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x98, 0x39, 0xC0,
//    0x18, 0x19, 0x80, 0x30, 0x39, 0xC1, 0xF8, 0x00, 0x00, 0x60, 0x39, 0xC6, 0x06, 0x6D, 0x80, 0x60,
//    0x60, 0x60, 0x00, 0x00, 0x03, 0x0C, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x30, 0xC0, 0x00, 0x00,
//    0x00, 0x00, 0x18, 0x60, 0x00, 0x0F, 0x00, 0xF0, 0x3F, 0xE0, 0x00, 0x0B, 0x03, 0x0C, 0x00, 0x00,
//    0x00, 0x30, 0xC0, 0x00, 0x00, 0x03, 0xFC, 0x60, 0x60, 0x60, 0x30, 0xC3, 0x0C, 0x6D, 0x80, 0x60,
//    0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x3F, 0xE0, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0C, 0x60, 0x60, 0x60, 0x30, 0xC3, 0x0C, 0x6D, 0x80, 0x60,
//    0x60, 0x66, 0x06, 0x1F, 0x81, 0xF0, 0x1F, 0x01, 0xF0, 0x1F, 0x01, 0xF8, 0x1F, 0x81, 0xF8, 0x1F,
//    0x81, 0xF0, 0x1F, 0x01, 0xF0, 0x09, 0x01, 0x98, 0x30, 0x01, 0x98, 0x1B, 0x01, 0xF8, 0x1F, 0x81,
//    0xF8, 0x00, 0x06, 0x06, 0x60, 0x66, 0x06, 0x60, 0x61, 0xF8, 0x30, 0x03, 0x0C, 0x6F, 0xE0, 0x60,
//    0x60, 0x06, 0x06, 0x3F, 0xC3, 0xF8, 0x3F, 0x83, 0xF8, 0x3F, 0x83, 0xFC, 0x3F, 0xC3, 0xFC, 0x3F,
//    0xC1, 0xF0, 0x1F, 0x01, 0xF0, 0x19, 0x81, 0x98, 0x30, 0x03, 0xFC, 0x1B, 0x03, 0xFC, 0x3F, 0xC3,
//    0xFC, 0x60, 0x66, 0x06, 0x60, 0x66, 0x06, 0x60, 0x63, 0xFC, 0x30, 0x01, 0x98, 0x6F, 0xE0, 0x60,
//    0x60, 0x06, 0x06, 0x30, 0xC3, 0x1C, 0x31, 0xC3, 0x1C, 0x31, 0xC3, 0x0E, 0x30, 0xC3, 0x0C, 0x30,
//    0xC0, 0x30, 0x03, 0x00, 0x30, 0x19, 0x81, 0x98, 0x30, 0x06, 0x66, 0x1B, 0x03, 0x0C, 0x30, 0xC3,
//    0x0C, 0x60, 0x66, 0x06, 0x60, 0x66, 0x06, 0x60, 0x63, 0x6E, 0x18, 0x01, 0x98, 0x6D, 0x83, 0xFC,
//    0x60, 0x06, 0x06, 0x60, 0x60, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC6, 0x06, 0x60, 0x66, 0x06, 0x60,
//    0x60, 0x30, 0x03, 0x00, 0x30, 0x19, 0x81, 0x98, 0x30, 0x06, 0x66, 0x33, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x30, 0xC6, 0x06, 0x60, 0x66, 0x66, 0x18, 0x07, 0xFE, 0x6D, 0x83, 0xFC,
//    0x60, 0x06, 0x06, 0x60, 0x60, 0x0C, 0x00, 0xC0, 0x0C, 0x00, 0xC6, 0x06, 0x60, 0x66, 0x06, 0x60,
//    0x60, 0x30, 0x03, 0x00, 0x30, 0x19, 0x83, 0x0C, 0x30, 0x00, 0x66, 0x33, 0xE6, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x30, 0xC6, 0x06, 0x60, 0x66, 0x66, 0x7F, 0xC7, 0xFE, 0x6D, 0x80, 0x60,
//    0x60, 0x06, 0x06, 0x60, 0x60, 0xFC, 0x0F, 0xC0, 0xFC, 0x0F, 0xC6, 0x00, 0x60, 0x66, 0x06, 0x60,
//    0x60, 0x30, 0x03, 0x00, 0x30, 0x30, 0xC3, 0x0C, 0x3F, 0xC0, 0x66, 0x33, 0xE6, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x30, 0xC6, 0x06, 0x60, 0x66, 0x60, 0x7F, 0xC0, 0x60, 0x6D, 0x80, 0x60,
//    0x60, 0x06, 0x06, 0x7F, 0xE3, 0xFC, 0x3F, 0xC3, 0xFC, 0x3F, 0xC6, 0x00, 0x7F, 0xE7, 0xFE, 0x7F,
//    0xE0, 0x30, 0x03, 0x00, 0x30, 0x30, 0xC3, 0x0C, 0x3F, 0xC1, 0xFE, 0x33, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x19, 0x86, 0x06, 0x60, 0x66, 0x60, 0x0C, 0x00, 0x60, 0x6D, 0x80, 0x60,
//    0x60, 0x06, 0x06, 0x7F, 0xE7, 0x0C, 0x70, 0xC7, 0x0C, 0x70, 0xC6, 0x00, 0x7F, 0xE7, 0xFE, 0x7F,
//    0xE0, 0x30, 0x03, 0x00, 0x30, 0x30, 0xC3, 0x0C, 0x30, 0x03, 0xFE, 0x3F, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x19, 0x86, 0x06, 0x60, 0x66, 0x60, 0x0C, 0x00, 0x60, 0x79, 0x80, 0x60,
//    0x60, 0x66, 0x06, 0x60, 0x06, 0x0C, 0x60, 0xC6, 0x0C, 0x60, 0xC6, 0x00, 0x60, 0x06, 0x00, 0x60,
//    0x00, 0x30, 0x03, 0x00, 0x30, 0x3F, 0xC3, 0xFC, 0x30, 0x06, 0x60, 0x3F, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x19, 0x86, 0x06, 0x60, 0x66, 0x60, 0x0C, 0x07, 0xFE, 0x61, 0x80, 0x60,
//    0x60, 0x66, 0x06, 0x60, 0x06, 0x0C, 0x60, 0xC6, 0x0C, 0x60, 0xC6, 0x06, 0x60, 0x06, 0x00, 0x60,
//    0x00, 0x30, 0x03, 0x00, 0x30, 0x3F, 0xC3, 0xFC, 0x30, 0x06, 0x60, 0x63, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x0B, 0x06, 0x06, 0x60, 0x66, 0x60, 0x0C, 0x07, 0xFE, 0x61, 0x80, 0x60,
//    0x60, 0x66, 0x06, 0x60, 0x06, 0x0C, 0x60, 0xC6, 0x0C, 0x60, 0xC6, 0x06, 0x60, 0x06, 0x00, 0x60,
//    0x00, 0x30, 0x03, 0x00, 0x30, 0x60, 0x66, 0x06, 0x30, 0x06, 0x60, 0x63, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0x66, 0x06, 0x0F, 0x06, 0x06, 0x60, 0x66, 0x66, 0x0C, 0x00, 0x60, 0x61, 0x80, 0x60,
//    0x30, 0xC6, 0x0E, 0x60, 0x66, 0x0C, 0x60, 0xC6, 0x0C, 0x60, 0xC3, 0x0E, 0x60, 0x66, 0x06, 0x60,
//    0x60, 0x30, 0x03, 0x00, 0x30, 0x60, 0x66, 0x06, 0x30, 0x06, 0x66, 0x63, 0x06, 0x06, 0x60, 0x66,
//    0x06, 0x60, 0xE6, 0x0E, 0x06, 0x06, 0x06, 0x60, 0x66, 0x66, 0x18, 0x00, 0x60, 0x61, 0x80, 0x60,
//    0x3F, 0xC7, 0x1E, 0x30, 0xE7, 0x1C, 0x71, 0xC7, 0x1C, 0x71, 0xC3, 0xFC, 0x30, 0xE3, 0x0E, 0x30,
//    0xE0, 0x30, 0x03, 0x00, 0x30, 0x60, 0x66, 0x06, 0x30, 0x06, 0x66, 0x63, 0x03, 0x0C, 0x30, 0xC3,
//    0x0C, 0x71, 0xE7, 0x1E, 0x06, 0x03, 0x0C, 0x30, 0xC3, 0x6E, 0x3E, 0x60, 0x60, 0x61, 0x80, 0x60,
//    0x1F, 0x83, 0xF6, 0x3F, 0xC3, 0xFE, 0x3F, 0xE3, 0xFE, 0x3F, 0xE1, 0xF8, 0x3F, 0xC3, 0xFC, 0x3F,
//    0xC0, 0x30, 0x03, 0x00, 0x30, 0x60, 0x66, 0x06, 0x3F, 0xE7, 0xFE, 0x63, 0xE3, 0xFC, 0x3F, 0xC3,
//    0xFC, 0x3F, 0x63, 0xF6, 0x06, 0x03, 0xFC, 0x3F, 0xC3, 0xFC, 0x7F, 0xE0, 0x60, 0x61, 0xE0, 0x60,
//    0x06, 0x01, 0xE6, 0x1F, 0x81, 0xEE, 0x1E, 0xE1, 0xEE, 0x1E, 0xE0, 0x60, 0x1F, 0x81, 0xF8, 0x1F,
//    0x80, 0x30, 0x03, 0x00, 0x30, 0x60, 0x66, 0x06, 0x3F, 0xE3, 0x9C, 0x63, 0xE1, 0xF8, 0x1F, 0x81,
//    0xF8, 0x1E, 0x61, 0xE6, 0x0C, 0x01, 0xF8, 0x1F, 0x81, 0xF8, 0x63, 0xC0, 0x60, 0x60, 0xE0, 0x60,
//    0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
//    0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE0,
//    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0
//};

static int enc_get_utf8_size(const unsigned char pInput)
{
    int num = 0, temp = 0x80;
    while (temp&pInput)
    {
        num++;
        temp = (temp >> 1);
    }
    return num;
}
int UTF_8ToUnicode(char* pOutput, char *pInput)
{
    int b1, b2, b3, b4, b5, b6;
    int len = enc_get_utf8_size(*pInput);
    switch (len)
    {
    case 0:
        *pOutput = *pInput;
        len += 1;
        break;
    case 2:
        b1 = *pInput;
        b2 = *(pInput + 1);
        if ((b2 & 0xC0) != 0x80)
            return 0;
        *pOutput = (b1 << 6) + (b2 & 0x3F);
        *(pOutput + 1) = (b1 >> 2) & 0x07;
        break;
    case 3:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80))
            return 0;
        *pOutput = ((b2 & 0x03) << 6) + (b3 & 0x3F);
        *(pOutput + 1) = ((b1 & 0x0F) << 4) | ((b2 >> 2) & 0x0F);
        break;
    case 4:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
            || ((b4 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b3 << 6) + (b4 & 0x3F);
        *(pOutput + 1) = (b2 << 4) + ((b3 >> 2) & 0x0F);
        *(pOutput + 2) = ((b1 << 2) & 0x1C) + ((b2 >> 4) & 0x03);
        break;
    case 5:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        b5 = *(pInput + 4);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
            || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b4 << 6) + (b5 & 0x3F);
        *(pOutput + 1) = (b3 << 4) + ((b4 >> 2) & 0x0F);
        *(pOutput + 2) = (b2 << 2) + ((b3 >> 4) & 0x03);
        *(pOutput + 3) = (b1 << 6);
        break;
    case 6:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        b5 = *(pInput + 4);
        b6 = *(pInput + 5);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
            || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80)
            || ((b6 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b5 << 6) + (b6 & 0x3F);
        *(pOutput + 1) = (b5 << 4) + ((b6 >> 2) & 0x0F);
        *(pOutput + 2) = (b3 << 2) + ((b4 >> 4) & 0x03);
        *(pOutput + 3) = ((b1 << 6) & 0x40) + (b2 & 0x3F);
        break;
    default:
        return 0;
    }
    return len;
}


int  UTF_8ToGB2312(char*pOut, char *pInput, int pLen)
{
    int res, i = 0, j = 0;
    char tempbuf[10];
    memset(tempbuf, 0, sizeof(tempbuf));
    while (i < pLen)
    {
        res = UTF_8ToUnicode(tempbuf, pInput + i);
        if (res <= 0)
            return 0;
        else if (res == 1)
        {
            *(pOut + j) = *(pInput + i);
            j += 1;
        }
        else{
            int temp =(int) (*(tempbuf+1)&0xff)<<8 | *tempbuf;
            int ret=0;
  //          uni2gbk2(ret, temp);
            j += 2;
        }
        i += res;
    }

    return 1;
}

//int u2g(char *inbuf, size_t inlen,char *outbuf, size_t outlen) {
//    iconv_t cd;
//    char **pin = &inbuf;
//    char **pout = &outbuf;

//    cd = iconv_open("GB2312","UTF-8");
//    if (cd==0)
//            return -1;
//    memset(outbuf,0,outlen);
//    if (iconv(cd,pin,&inlen,pout,&outlen) == -1)
//            return -1;
//    iconv_close(cd);

//    return 0;
//}

/***************************************************************
* outx :
*
****************************************************************/
QString print_name;
QByteArray testiii(QByteArray number,int outx,int outy,int inx){
    QByteArray ret;
    QString str;

    bool quit;
    int h;
    if(outx%8)
    {
        quit=true;
        h=outx/8+1;
    }
    else
    {
        quit=false;
        h=outx/8;
    }

    QFile file_data(print_name);

    if(!file_data.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) //
    {
        qDebug() <<"read or output file don't exist!";
    }
    else
    {
        QTextStream inhex(&file_data);

        char a = 0x0;
        int i=0,j=0,k=8;
        for(i=0;i<h;i++){
            for(k=8;k>0;k--){
                if(quit&&(i==h-1)&&k<(9-outx%8)) break;
                for(j=0;j<outy;j++)
                {
                    if((i+j*inx)<number.size() && i<inx)
                    a |= number[i+j*inx]&1<<(k-1)?1<<(7-(j%8)):0;
                    str.append(a&1<<(7-j%8)?'1':'0');
                    if(j%8==7 || j==outy-1){
                        ret.append(a);
                        a=0x0;
                    }
                }
                QString str1 = str.replace(QRegExp("0"), " ");
                qDebug() << str1;
                inhex << str1 << "\n";
                file_data.flush();
                str.clear();
            }
        }

        inhex << ret.toHex() <<"\n";
        file_data.close();
    }
    return ret;
}

//*curBufPt，一个字符的点阵缓存指针
//curCharWB，字符宽度占用的字节数
//charHD，字符的高度点行数
QByteArray Bold(QByteArray number,int curCharWB,int charHD){
    int i=0,j=0,tmp32;
    QByteArray ret  = number;
    char* curBufPt = ret.data();
    /*----加粗-------*/
//    if(FontConfig.Bold == 1)
    {
         /*---纵向加粗---*/
//        for(i = charHD-1; i > 0; i--){
//            for(j=0;j<curCharWB;j++){
//                *(curBufPt + i * curCharWB +j) |= *(curBufPt + (i-1) * curCharWB +j);
//            }
//        }
        /*横向加粗*/
        for(i=0; i<charHD; i++){
            tmp32 = 0;
            for(j=0;j<curCharWB;j++){
                tmp32 = (tmp32 << 8) |((*(curBufPt + i*curCharWB + j))&0xff);
            }
            tmp32 = tmp32 >>1;//tmp32=0;
            for(j=0;j<curCharWB;j++){
                *(curBufPt + i*curCharWB + j) |= (tmp32 >>((curCharWB - 1 - j)*8) & 0xff);
            }
        }
    }
    return ret;
}

void Delay_MSec(int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Delay_MSec_Suspend(int msec)
{

    QTime _Timer = QTime::currentTime();

    QTime _NowTimer;
    do{
              _NowTimer=QTime::currentTime();
    }while (_Timer.msecsTo(_NowTimer)<=msec);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int outx, outy, inx, data_size;
    QString file_name;
    QString tmp;
    QString out_name;
    if (argc == 5)
    {
        tmp = argv[1];
        outx = tmp.toInt();
        tmp = argv[2];
        outy = tmp.toInt();
        data_size = outx*outy/8;
        inx = data_size/outy;
        file_name = argv[3];
        out_name = QString ("%1.bin").arg (argv[4]);
        print_name = QString ("%1.txt").arg (argv[4]);
        qDebug() << outx << "  " << outy << "  " << inx << "  " << data_size << " " <<file_name << out_name;
    }
    else
    {
        outx = 12;
        outy = 24;
        inx = 2;
        data_size = 48;
        file_name = "read.bin";
        out_name = "out.bin";
        print_name = "print.txt";
    }

/*    QString hhh;
//    QString lll;
    QByteArray jjj;
    jjj = QByteArray::fromRawData((char*)shuipi,sizeof (shuipi));
    hhh = jjj.toHex();
    int size = hhh.size();
    int num = 0;
    for(int k=0;k<size/3;k++)
    {
        hhh.insert(3*(k+1)+num, QString("0"));
        num++;
//       lll.append(hhh.left(3));
//        lll.append("0");
//        hhh.remove(0,3);
    }*/

/*    QString str;
    int x =0;
    int y =0;
    while(x<24){         //行数
        for(y=0;y<9;y++) //列字节
        {
            str.append(QString("%1").arg(datadd[x*48+y],8,2));
        }
        x++;
        QString str1 = str.replace(QRegExp("0"), " ");
        qDebug() << str1;
        str.clear();
    }*/
/****************************************************************************/
    QByteArray test;

//    test = QByteArray::fromRawData((char*)shuipi,sizeof (shuipi));
//    testiii(test,12*32,24,48);  //2 =  12%8?12/8+1:12/8;
//    Bold(ttt,2,24)

    QByteArray ttt;
    qint64 i;
    QFile file_read(file_name);
    QFile file_bin(out_name);
    if(!file_read.open(QIODevice::ReadOnly) ||!file_bin.open(QIODevice::WriteOnly | QIODevice::Append)) //
    {
        qDebug() <<"read or output file don't exist!";
    }
    else
    {
        QDataStream out(&file_bin);
//        QTextStream out(&file_bin);
        QDataStream in(&file_read);
        qint64 totalBytes = file_read.size();

        QByteArray data;
//        data.resize(totalBytes);
//        in.readRawData(data.data(),totalBytes);
//        char* abc = data.data();
//        for(i=0;i<data.size()/48;i++)
//        {
//            ttt = QByteArray::fromRawData(abc+i*48,48);
//            test = testiii(Bold(ttt,2,24),12,24,2);
//            testiii(test,24,12,3);
//            out << test;
//            file_bin.flush();
//            ttt.clear();
//            test.clear();
//        }
        data.resize(data_size);
        for(i=0;i<totalBytes/data_size;i++){
            in.readRawData(data.data(),data_size);
            test=testiii(data,outx,outy,inx);//Bold(data,2,24)
           // testiii(test,outy,outx,3);
          //  test=testiii(data,12*32,24,48);//Bold(data,2,24)
            file_bin.write(test);
            file_bin.flush();
            test.clear();
        }
        data.clear();

//        while(!file_read.atEnd())
//        {
//            QByteArray line = file_read.readLine();
//            QString str(line);
//        }
    }
    file_bin.close();
    file_read.close();
/**************************************************************************/
//测试转码 unicode -> gbk ; utf8 -> unicode
/*    char *utf="测试";
    char unioncode[10];

    UTF_8ToGB2312(unioncode,utf,6);

    QByteArray jj = QByteArray::fromRawData(unioncode,6);
    qDebug() << jj.toHex();*/
    exit(0);
    return a.exec();
}
