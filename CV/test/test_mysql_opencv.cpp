#include <iostream>
#include <mysql.h>
#include <opencv2/opencv.hpp>

int main() {
  std::cout << "Testing g++ command..." << std::endl;

  // Test MySQL connection
  MYSQL mysql;
  mysql_init(&mysql);
  if (!mysql_real_connect(&mysql, "localhost", "root", "youki123", "test", 0, nullptr, 0)) {
    std::cerr << "Failed to connect to MySQL database." << std::endl;
    return 1;
  }
  std::cout << "Successfully connected to MySQL database!" << std::endl;

  // Test OpenCV
  cv::Mat image = cv::imread("./test.jpg");
  if (image.empty()) {
    std::cerr << "Failed to open test image." << std::endl;
    return 1;
  }
  std::cout << "Successfully opened test image!" << std::endl;

  return 0;
}
