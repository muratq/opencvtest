#include "opencv2\highgui\highgui.hpp"
#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\objdetect.hpp>

using namespace std;
using namespace cv;

void GorselOkuGoster(string dosyaYolu)
{
    Mat resim;  //resim verilerini sakliyor
    resim =  imread(dosyaYolu);
    if(resim.data) // resimde bi data varsa
    {
        cout<<"dosya okuma basarili"<<endl;
        namedWindow("ekran"); // pencere olusturduk
        imshow("ekran",resim); // ekrana bastir
        waitKey(0); // tusa basilana kadar bekle

    }
    else
    {
        cout << "hata : resim okunamadi ! Belirtilen yol:"<<dosyaYolu<<endl;
    }
}

void videoOkuGoster(string dosyaYolu)
{
   cv::VideoCapture video;
   video.open(dosyaYolu);
   if(video.isOpened())
   {
        cout<<"video acildi!"<<endl;
        cv::Mat anlik_resim;
        cv::namedWindow("ekran");
        int fps =0;
        int tus =0;
        fps =10;
        while(video.read(anlik_resim)) //video okunuyosa anlik resme framei at
        {
           cv::imshow("ekran",anlik_resim);
           tus = cv::waitKey(fps);
           if(tus == 27) // fps verdik
           {
                break;
           }
           else if(tus == 43)
           {
                fps++;
                cout<<"fps degeri :"<<fps<<endl;
           }
        }
        cv::destroyAllWindows();
        cout<<"video sonlandirildi"<<endl;


   }
   else
   {
        cout<<"video acilamadi"<<endl;
   }
   cv::waitKey();

}

void webcamOkuGoster(int ch)
{
    cv::VideoCapture video;

    if(video.open(ch))
    {
        cout<<"webcam acildi"<<endl;
        cv::Mat anlik_goruntu;
        cv::namedWindow("ekran");
        while(video.grab())
        {
            video.retrieve(anlik_goruntu);
            cv::imshow("ekran",anlik_goruntu);
            if(cv::waitKey(25) == 27)
            {
                break;
            }
        }
        cv::destroyAllWindows();

    }
}


void BasitResimOlustur(int genislik, int yukseklik,int blue,int green,int red)
{
    cv::Mat resim(genislik,yukseklik,CV_8UC3); //CV_8UC3, red,green,blue
    resim = cv::Scalar(blue,green,red);
    cv::namedWindow("ekran");
    cv::imshow("ekran",resim);
    cv::waitKey();


}


cv::Mat ResimdeCizgiCiz(string dosyaYolu,int x1,int y1,int x2,int y2)
{
    cv::Mat AsilResim = cv::imread(dosyaYolu);
    cv::Mat CizilmisResim;
    
    AsilResim.copyTo(CizilmisResim); // asil resmi cizilmisresime at
    cv::line(CizilmisResim,cv::Point(x1,y1),cv::Point(x2,y2),cv::Scalar(0,0,255),5); // (0,0) baslangic (300,300)
    cout<<"resmin cols u "<<CizilmisResim.cols<<endl;

    return CizilmisResim;
}

cv::Mat DikAciliDortgenCiz(string DosyaYolu)
{
    cv::Mat resim = cv::imread(DosyaYolu);
    cv::rectangle(resim,cv::Point(0,0),cv::Point(300,300),cv::Scalar(0,0,255),5);
    return resim;
}

cv::Mat ResimYaziYaz(string DosyaYolu,string yazi)
{
    cv::Mat resim = cv::imread(DosyaYolu);
    cv::Mat yaziliResim ;
    resim.copyTo(yaziliResim);
    cv::Point p(0,70);
    cv::putText(yaziliResim, yazi, p,cv::FONT_ITALIC,1,cv::Scalar(0,0,255),2);
    return yaziliResim;
}

void ResimDegerleriniOku(string dosyaYolu)
{
    cv:: Mat resim = cv::imread(dosyaYolu);
    cv::imshow("ekran",resim);
    cv::waitKey();

    for(int x =0; x<resim.cols;x++)
    {
        for(int y =0; y< resim.rows;y++)
        {
            cout<< resim.at<cv::Vec3b>(cv::Point(x,y))<<endl;
        }
    }


}




void detect_faces(void)
{

    /*cascade ile yüz tanıma*/
    CascadeClassifier face_cascade;
    if(!face_cascade.load("C:/Users/murat/opencvtest/src/haarcascade_frontalface_default.xml")){
        cout<< "haarcascade yuklenemedi!"<<endl;
    }
  
    VideoCapture cap(0);
    if(!cap.isOpened()){
        cout<<"kamera acilamadi"<<endl;
    }
    Mat frame, gray;
    vector<Rect> faces;

    while(true)
    {
        cap >> frame;
        if(frame.empty())
            break;
        cvtColor(frame,gray,COLOR_BGR2GRAY);
        face_cascade.detectMultiScale(gray,faces,1.1,3,0,Size(30,30));

        for(size_t i = 0;i < faces.size();i++)
        {
            rectangle(frame,faces[i],Scalar(255,0,0),2);
            Point p(faces[i].x, faces[i].y - 10);
            if(faces[i].width>300)
            {
                putText(frame, "cok yakin", p,cv::FONT_ITALIC,1,cv::Scalar(0,0,255),2);
            }

        }
        

        imshow("yuz algilama",frame);

        if (waitKey(10) == 'q') {
            break;
        }

    }

}




int main()
{
    detect_faces();
   
}


