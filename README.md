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
