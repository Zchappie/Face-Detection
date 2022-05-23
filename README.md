# Face-Detection

This project use OpenCV to detect human faces in real-time.

Two options available:

![Using dnn](data/dnn.gif)
![Using dnn](data/haar.gif)

## How to compile and run?

1. in the project folder `mkdir build`
2. navigate into the `build` folder by `cd build`
3. run cmake `cmake ..`
4. run make `make`
5. `dnn` or `haar` are the two methods that can be used to detect faces. They are passed as command line arguments.
   Namely, `./face_detection dnn` or `./face_detection haar`. Default option is `dnn` if you don't specify which method to use.

## Verify the folders and files

Here lists the full project files that are important to compile and run the project.

```shell
.
├── CMakeLists.txt
├── LICENSE
├── README.md
├── data
│   ├── deploy.prototxt
│   ├── dnn.gif
│   ├── haar.gif
│   ├── haarcascade_eye_tree_eyeglasses.xml
│   ├── haarcascade_frontalface_alt.xml
│   └── res10_300x300_ssd_iter_140000_fp16.caffemodel
├── include
│   ├── detector.h
│   └── draw.h
└── src
    ├── detector.cpp
    ├── draw.cpp
    └── face_detection.cpp
```

## Install OpenCV on M1 Mac

If you have dependency issues, here is the instructions on how to do install OpenCV in a M1 machine.

Credits: [Open CV C++ Mac M1 Installation Tutorial Video](https://www.youtube.com/watch?v=KaTA-yK7dWA&ab_channel=GlebMaksimov)

1. From terminal install `cmake` using homebrew: `brew install cmake`
2. Clone, build, install OpenCV in a new folder *OPEN_CV*
    - `git clone https://github.com/opencv/opencv.git`
    - `mkdir build` in the folder *OPEN_CV*
    - `cmake ../opencv/ .`
    - `arch -arm64 cmake ../opencv/ -DWITH_QT=OFF -DWITH_OPENGL=OFF -DFORCE_VTK=OFF -DWITH_TBB=OFF -DWITH_GDAL=OFF -DWITH_XINE=OFF -DBUILD_EXAMPLES=OFF -DBUILD_ZLIB=OFF -DBUILD_TESTS=OFF .`
    - `arch -arm64 sudo make -j 4`
    - `arch -arm64 sudo make install`

## Rubric

The project bellows to the first option of the capstone project.

| Criteria (README)                                                  | Met? |
|--------------------------------------------------------------------|------|
| A README with instructions is included with the project            | ✅    |
| The README indicates which project is chosen.                      | ✅    |
| The README includes information about each rubric point addressed. | ✅    |

| Criteria (Compiling and Testing)     | Met? |
|--------------------------------------|------|
| The submission must compile and run. | ✅    |

| Criteria (General Topics)   | Met? | Which?                                                                                                                                                                                                                                   |
|-----------------------------|------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Loops, Functions, I/O       | ✅    | The project code is clearly organized into functions.                                                                                                                                                                                    |
|                             | ✅    | The project reads detection models from an external file .                                                                                                                                                                               |
|                             | ✅    | The project accepts input from a user as part of the necessary operation of the program.                                                                                                                                                 |
| Object Oriented Programming | ✅    | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.                                                                                                                   |
|                             | ✅    | All class data members are explicitly specified as public, protected, or private.                                                                                                                                                        |
|                             | ✅    | All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.                                                  |
|                             | ✅    | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.                                                                    |
| Memory Management           | ✅    | At least two variables are defined as references, or two functions use pass-by-reference in the project code.                                                                                                                            |
|                             | ✅    | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.                                                     |
|                             | ✅    | The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. |
| Concurrency                 | ✅    | The project uses multiple threads in the execution.                                                                                                                                                                                      |
