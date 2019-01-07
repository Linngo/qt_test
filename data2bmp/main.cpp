#include <QCoreApplication>
#include <qdebug.h>
#include <QFile>
#include <QDataStream>
#include <qbytearray.h>
#include <qstring.h>
#include <Windows.h>

#define MX                (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z)
#define DELTA             0x37//0x9e3779b9
#define S_LOOPTIME        5        //5
#define BLOCK_SIZE        36       //PAGE_SIZE,根据你所要加密的数据包长度修改此参数(单位:字节)

//unsigned long  TEA_key[4]=
//{
//   52678912,1687965762,786325461,2295634851
//  //  12,34,56,78
//};

uint8_t  TEA_key[4]=
{
  12,34,56,78
};

void btea_encrypt(uint8_t * buf, uint8_t* key )
{
    unsigned char n=BLOCK_SIZE;
    uint8_t *v= buf;
    uint8_t *k = key;
    uint8_t z = v[n - 1],y = v[0],sum = 0,e ;
    uint8_t p,q ;
    // Coding Part

    q = S_LOOPTIME + 52 / n ;
    while ( q-- > 0 )
    {
        sum += DELTA ;
        e = sum >> 2 & 3 ;
        for ( p = 0 ; p < n - 1 ; p++ )
          y = v[p + 1],
          z = v[p] += (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z);
          y = v[0] ;
        z = v[n - 1] += (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z);
    }
}

void btea_decrpyt( uint8_t* buf, uint8_t* key )
{
    uint8_t n=BLOCK_SIZE;
    uint8_t *v=buf;
    uint8_t *k=key;
    uint8_t z = v[n - 1],y = v[0],sum = 0,e ;
    uint8_t  p,q ;

    //Decoding Part...
    q = S_LOOPTIME + 52 / n ;
    sum = q * DELTA ;
    while ( sum != 0 )
    {
        e = sum >> 2 & 3 ;
        for ( p = n - 1 ; p > 0 ; p-- )
            z = v[p - 1],
            y = v[p] -= MX;
            z = v[n - 1] ;
        y = v[0] -= MX;
        sum -= DELTA ;
    }
}
/************************************************************/
//void btea_encrypt( unsigned long* buf, unsigned long* key )
//{
//    unsigned char n=BLOCK_SIZE/4;
//    unsigned long *v=(unsigned long *)buf;
//    unsigned long *k=(unsigned long *)key;
//    unsigned long z = v[n - 1],y = v[0],sum = 0,e ;
//    unsigned char p,q ;
//    // Coding Part

//    q = S_LOOPTIME + 52 / n ;
//    while ( q-- > 0 )
//    {
//        sum += DELTA ;
//        e = sum >> 2 & 3 ;
//        for ( p = 0 ; p < n - 1 ; p++ )
//          y = v[p + 1],
//          z = v[p] += MX;
//          y = v[0] ;
//        z = v[n - 1] += MX;
//    }
//}

//void btea_decrpyt( unsigned long* buf, unsigned long* key )
//{
//    unsigned char n=BLOCK_SIZE/4;
//    unsigned long *v=(unsigned long *)buf;
//    unsigned long *k=(unsigned long *)key;
//    unsigned long z = v[n - 1],y = v[0],sum = 0,e ;
//    unsigned char  p,q ;

//    //Decoding Part...
//    q = S_LOOPTIME + 52 / n ;
//    sum = q * DELTA ;
//    while ( sum != 0 )
//    {
//        e = sum >> 2 & 3 ;
//        for ( p = n - 1 ; p > 0 ; p-- )
//            z = v[p - 1],
//            y = v[p] -= MX;
//            z = v[n - 1] ;
//        y = v[0] -= MX;
//        sum -= DELTA ;
//    }
//}
//unsigned long Endat[]={1568952,865444,7845412,5421367,87453215,7851255,654234,5632452,874212};


const unsigned char aaa[1] = {0x00};

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

    //for(i=0;i<new_Height;i++)
    //{
    // dwsrcY=i*old_height/new_Height;
    // pucDest=dest_data+i*new_Width*3;
    // pucSrc=src_data+dwsrcY*old_width*3;
    // for(j=0;j<new_Width;j++)
    // {
    //  dwsrcX=j*old_width/new_Width;
    //  memcpy(pucDest+j*3,pucSrc+dwsrcX*3,3);//数据拷贝
    // }
    //}

    exit(0);
    return a.exec();
}
