# **L2D - Game Engine**

# **Building L2D**

## **Windows**

*   [MinGW-w64](https://sourceforge.net/projects/mingw-w64/)
*   [Git](https://git-scm.com/)
*   CMake 3.20.5 or higher: [Download CMake](https://cmake.org/download/)

## **Linux**

To build **L2D** on Linux, you can use the following commands to install the necessary dependencies:

```shell
sudo apt install git cmake build-essential clang -y
```

#

## **Clone the repository**

To get started, clone the **L2D** repository using the following command:

```shell
git clone https://github.com/LakoMoor/L2D.git --recursive
```

## **Quick start engine setup**

Perform the following steps to set up the engine quickly:

```shell
cd L2D
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

#
# **Start application**

## **Windows**

To launch the application on Windows, run `L2D.exe`. For development mode, open a command prompt and use the following command:

```shell
L2D.exe -dev
```

## **Linux**

To launch the application on Linux, use the following command:

```shell
./L2D
```

For development mode, use the following command:

```shell
./L2D.exe -dev
```

#

`Please note that this README will be updated with more detailed information in the future.`

#
