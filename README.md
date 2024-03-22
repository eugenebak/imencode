# imencode
OpenCV image encoding for pybind in C++

## Getting started

Clone repository
```shell
$ git clone https://github.com/eugenebak/imencode.git
$ cd imencode
```

Install pybind11
```shell
$ apt-get install python3-pybind11 
```

Build
```shell
$ mkdir build && cd build
$ cmake ..
$ make -j8
```

## How to use it in python
1. Paste this repo to your working directory

2. Code snippet
```python
sys.path.append("<path to .so file>")
import imencode_ext

image = ... # numpy array or cv2.imread

jpeg_image = imencode_ext.imencode_jpeg(image)
```

## TODO
- [ ] Setting python path for `.so`