#ifndef TUATARA_H
#define TUATARA_H

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

namespace tuatara
{

    struct OutputItem
    {
        std::string text;
        std::vector<float> bbox;
    };

    std::vector<OutputItem> image_to_data(cv::Mat image, std::string weights_dir, std::string outputs_dir);

}

#endif // TUATARA_H
