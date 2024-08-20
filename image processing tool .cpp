#include <opencv2/opencv.hpp>
#include <iostream>

void applyFilters(cv::Mat& image) {
    cv::Mat gray, blurred, sharpened;

    // Grayscale
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::imshow("Grayscale", gray);

    // Blur
    cv::GaussianBlur(image, blurred, cv::Size(7, 7), 5);
    cv::imshow("Blurred", blurred);

    // Sharpen
    cv::Mat kernel = (cv::Mat_<float>(3,3) << 
                        0, -1, 0, 
                        -1, 5,-1, 
                        0, -1, 0);
    cv::filter2D(image, sharpened, image.depth(), kernel);
    cv::imshow("Sharpened", sharpened);
}

int main() {
    std::string path = "image.jpg";  // Change to your image path
    cv::Mat image = cv::imread(path);

    if (image.empty()) {
        std::cout << "Could not load image!\n";
        return -1;
    }

    cv::imshow("Original Image", image);

    applyFilters(image);

    cv::waitKey(0);  // Wait for any key press
    return 0;
}
