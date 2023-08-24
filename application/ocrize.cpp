#include <iostream>

#include <opencv2/opencv.hpp>

#include <libtuatara/tuatara.hpp>

int main(int argc, char *argv[])
{
    cv::Mat image = cv::imread("../application/test.png", cv::IMREAD_COLOR);
    std::vector<tuatara::OutputItem> text = tuatara::image_to_data(image, "../../models", ".");

    // iterate through detected text
    for (auto const &it : text)
    {
        // print detected text and corresponding textbox coordinates
        std::cout << it.text << " [";
        for (auto const &itb : it.bbox) { std::cout << itb << " ";}
        std::cout << "]\n";

        // draw a rectangle around the text
        // cv::rectangle(image, cv::Point(it.bbox[0],it.bbox[1]), cv::Point(it.bbox[2],it.bbox[3]), cv::Scalar(0, 255, 0));
    }

    // show image with detected text box
    // cv::imshow("winname", image);
    // cv::waitKey(0);
}
