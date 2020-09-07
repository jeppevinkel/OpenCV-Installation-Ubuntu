#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	namedWindow( "Hello World", WINDOW_AUTOSIZE );
	
	Mat output = Mat::zeros( 120, 350, CV_8UC3 );
	putText(output,
            "Hello World :)",
            Point2d(15,70),
            FONT_HERSHEY_PLAIN,
            3,
            Scalar(0,255,0),
            4);
	
	imshow("Hello World", output);

	waitKey(0);
}