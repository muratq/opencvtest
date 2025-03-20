#include "opencv2\highgui\highgui.hpp"
#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>

using namespace std;

void GorselOkuGoster(string dosyaYolu)
{
    cv::Mat resim;  //resim verilerini sakliyor
    resim =  cv::imread(dosyaYolu);
    if(resim.data) // resimde bi data varsa
    {
        cout<<"dosya okuma basarili"<<endl;
        cv::namedWindow("ekran"); // pencere olusturduk
        cv::imshow("ekran",resim); // ekrana bastir
        cv::waitKey(0); // tusa basilana kadar bekle

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





int main()
{
    webcamOkuGoster(0);
    int a  =0;


    

}