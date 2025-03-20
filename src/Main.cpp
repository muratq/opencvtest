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
        cv::waitKey(1); // tusa basilana kadar bekle

    }
    else
    {
        cout << "hata : resim okunamadi ! Belirtilen yol:"<<dosyaYolu<<endl;
    }
}


int main()
{

    GorselOkuGoster("C:/Users/murat/opencvtest/src/manzara.jpg");

}