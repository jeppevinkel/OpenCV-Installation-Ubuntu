# OpenCV-Installation-Ubuntu

### Install dependencies
```bash
sudo apt-get install build-essential cmake unzip pkg-config libjpeg-dev libpng-dev libtiff-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libatlas-base-dev gfortran python3.8 python3-pip python3-pip python3-numpy
```

### Download the needed files
```bash
sudo su
cd /opt
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

### Build the sources
```bash
cd opencv
mkdir release
cd release
# Note, OPENCV_ENABLE_NONFREE installs patented libraries that are only permited for use in non-commercial projects. Set this to OFF if your project is for commercial use.
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D WITH_CUDA=OFF \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules \
    -D OPENCV_ENABLE_NONFREE=ON \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
    -D BUILD_EXAMPLES=ON ..
#replace 8 with your number of CPU cores
#You can check your number of available cores with 'cat /proc/cpuinfo | grep processor | wc -l'
make -j8
make install
ldconfig
```

### Test the installation
```bash
pkg-config --modversion opencv4
```
The ideal output here is the version of your OpenCV install

### Done
Now OpenCV should be installed, and ready for use on your computer!

### Include flags for C++
The following command can be used when compiling, to add the proper includeflags for OpenCV4
```bash
pkg-config --cflags --libs opencv4
```
