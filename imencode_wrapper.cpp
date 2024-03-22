#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <opencv2/opencv.hpp>

namespace py = pybind11;

py::bytes imencode_jpeg(const py::array_t<unsigned char>& input_image) {
    cv::Mat image(input_image.shape(0), input_image.shape(1), CV_8UC3, (unsigned char*) input_image.data());
    
    std::vector<unsigned char> buffer;
    std::vector<int> params = {cv::IMWRITE_JPEG_QUALITY, 95}; // JPEG quality를 95로 설정 (1~100)
    cv::imencode(".jpg", image, buffer, params);
    
    return py::bytes(reinterpret_cast<char*>(buffer.data()), buffer.size());
}

PYBIND11_MODULE(imencode_ext, m) {
    m.doc() = "pybind11 plugin for JPEG encoding with OpenCV";
    m.def("imencode_jpeg", &imencode_jpeg, "A function that encodes an image to JPEG format");
}
