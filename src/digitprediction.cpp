#include "digitprediction.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

DigitPrediction::DigitPrediction(std::string modelPath)
{
    std::cout << "Nice\n";
    try {
      // Deserialize the ScriptModule from a file using torch::jit::load().
      model = torch::jit::load(modelPath);
    }
    catch (const c10::Error& e) {
      std::cerr << "error loading the model\n";
    }

    std::cout << "Model successfully loaded!\n";
    device = torch::cuda::is_available() ? at::kCUDA : at::kCPU;
    model.to(device);
}

void DigitPrediction::predict(QImage image)
{
    // Convert to cv image of size (1, 1, 32, 32)
    cv::Mat color_mat(image.height(),image.width(),CV_8UC4,const_cast<uchar*>(image.constBits()),static_cast<size_t>(image.bytesPerLine()));
    cv::Mat grey_mat;
    cv::cvtColor(color_mat, grey_mat, cv::COLOR_RGB2GRAY);
    cv::resize(grey_mat, grey_mat, cv::Size(28, 28), cv::INTER_LINEAR);
    cv::resize(grey_mat, grey_mat, cv::Size(32, 32), cv::INTER_LINEAR);
//    cv::namedWindow("grayscale image", (550, 550));
//    cv::imshow("grayscale image", grey_mat);
//    cv::waitKey(0);
//    cv::destroyAllWindows();



    // Convert to torch input tensor
    auto tensor_image = torch::from_blob(grey_mat.data, { grey_mat.rows, grey_mat.cols, grey_mat.channels() }, torch::kByte);
    tensor_image = tensor_image.permute({ 2,0,1 });
    tensor_image = tensor_image.toType(torch::kFloat);
    tensor_image.unsqueeze_(0);
    tensor_image = 1. - tensor_image / 255.;

    // Normalize
    std::vector<double> norm_mean = {0.1307};
    std::vector<double> norm_std = {0.3081};
    tensor_image = torch::data::transforms::Normalize<>(norm_mean, norm_std)(tensor_image);

    // Predict
    std::vector<torch::jit::IValue> input;
    input.push_back(tensor_image.to(device));
    at::Tensor output = model.forward(input).toTensor();

    digit = output.argmax(1).item<int>();
    prob = output.slice(/*dim=*/1, /*start=*/digit, /*end=*/digit + 1).item<float>();
}

