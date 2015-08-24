# gpuR

### Build Status
|                 | Build           |
|-----------------|-----------------|
| Linux x86       | [![Build Status](https://travis-ci.org/cdeterman/gpuR.png?branch=master)](https://travis-ci.org/cdeterman/gpuR)      |
| OSX             | [![Build Status](https://travis-ci.org/cdeterman/gpuR.png?branch=macosx)](https://travis-ci.org/cdeterman/gpuR)          |
| Windows         | Unsupported     |

Test coverage: [![Coverage Status](https://img.shields.io/coveralls/cdeterman/gpuR.svg)](https://coveralls.io/r/cdeterman/gpuR?branch=master)

Welcome to my R package for simple GPU computing.  Although there are a few
existing packages to leverage the power of GPU's they are either specific
to one brand (e.g. NVIDIA) or are not very user friendly.  The goal of this
package is to provide the user a very simple R API.  This is accomplished by
interfacing with the ViennaCL library that I have packaged in the R package
[RViennaCL](http://github.com/cdeterman/RViennaCL).  To make the R API simple,
I created new classes similar to the structure of the 
[Matrix](http://cran.r-project.org/web/packages/Matrix/index.html)
package.  By doing so, typical methods may be overloaded to make for a very
pleasing sytax.  For example, to perform vector addition the syntax is: 

```r
A <- seq.int(from=0, to=999)
B <- seq.int(from=1000, to=1)
gpuA <- gpuVector(A)
gpuB <- gpuVector(B)

C <- A + B
gpuC <- gpuA + gpuB

all(C == gpuC)
[1] TRUE
```

I also recommend you read the vignette I included with this package to
get a better understanding of its' capabilities.

```r
vignette("gpuR")
```

Please note, all the functions herein use an OpenCL backend.  If you prefer
to have a CUDA based backend, please see my other package 
[gpuRcuda](http://github.com/cdeterman/gpuRcuda) which is simply an extension
on top of this package where all functions herein are still applicable
but also have the CUDA option available.  

# INSTALL

### Dependencies
1. OpenCL headers (can be found at Khronos.org)
2. An OpenCL SDK specific to your GPU vender (AMD, NVIDIA, Intel, etc.)

**Note - the package will install if you have the headers above but will be
essentially non-functional.**

## Windows
Currently unsupported :( This package requires C++11 and until 
[Rtools](https://cran.r-project.org/bin/windows/Rtools/) has a more recent 
compiler that fully supports C++11 there is no clean way to install this
package.

## OSX
OpenCL should be present by default but you likely will not have the C++ API.
This is required currently until I find a cleaner way to include this (possibly
in the includes of this package, TBD).

You can download it on the Khronos downloads page [here](https://www.khronos.org/registry/cl/)
which provides all the OpenCL headers.  You will want whichever is the most
recent version you currently have.  To find this out, on a Mac OSX 10.10 you
open the `/System/Library/Frameworks/OpenCL.framework/Headers/cl.h` file in
your favorite text editor and find the `/* OpenCL Version */` section.  Choose
the highest version, download the corresponding `cl.hpp` file and put it in
that directory.

That is all you need for the install on a Mac :)

## Linux

The only verified installations at present consisted of using a NVIDIA 970 GTX 
or a AMD Radeon Graphics Card on a Ubuntu 14.04 system.  The installation 
consisted of:

#### Note, you currently can only have one type installed (NVIDIA or AMD)

### NVIDIA Driver and CUDA/OpenCL
#### Up-to-date Card
If you are fortunate enough to have a very recent card that you can
use the most recent drivers.  This install is much more simple
```
# Install OpenCL headers
sudo apt-get install opencl-headers

# Install NVIDIA Drivers and CUDA
sudo add-apt-repository -y ppa:xorg-edgers/ppa
sudo apt-get update
sudo apt-get install nvidia-346 nvidia-settings
sudo apt-get install cuda
```

#### Older Card
If you have an older card that doesn't support the newest drivers:

1. Purge any existing nvidia and cuda implementations 
(`sudo apt-get purge cuda* nvidia-*`)
2. Download appropriate CUDA toolkit for the specific card.  You can figure 
this out by first checking which NVIDIA driver is compatible with your card
by searching for it in [NVIDIA's Driver Downloads](http://www.nvidia.com/Download/index.aspx?lang=en-us).
Then check which cuda toolkit is compatible with the driver from this
[Backward Compatibility Table](http://docs.roguewave.com/totalview/8.14.1/html/index.html#page/User_Guides/totalviewug-about-cuda.31.4.html)
The cuda-6.5 toolkit was appropriate for me which you can download from the 
[CUDA toolkit archive](https://developer.nvidia.com/cuda-toolkit-archive).
Once downloaded, run the .run file.
3. Reboot computer
4. Switch to ttyl (Ctrl-Alt-F1)
5. Stop the X server (`sudo stop lightdm`)
6. Run the cuda run file (`sh cuda_6.5.14_linux_64.run`)
7. Select 'yes' and accept all defaults
8. Required reboot
9. Switch to ttyl, stop X server and run the cuda run file again and select 
'yes' and default for everything (including the driver again)
10. Update `PATH` to include `/usr/local/cuda-6.5/bin` and `LD_LIBRARY_PATH`
to include `/usr/local/cuda-6.5/lib64`
11. Reboot again

### AMD Driver and OpenCL
1. Purge existing fglrx drivers (`sudo sh /usr/share/ati/fglrx_uninstall.sh`)
2. Install current fglrx drivers (`sudo apt-get install fglrx-updates`)
3. Install opencl-headers (`sudo apt-get install opencl-headers`)

# Install OpenCL headers
```
sudo apt-get install opencl-headers
```

# Installing the package
### Stable
Will be posted to CRAN following completion of version 1.0.0

### Development
```r
# Dev RViennaCL
devtools::install_github("cdeterman/RViennaCL")

# Dev gpuR
devtools::install_github("cdeterman/gpuR")
```

Once all these things are set you should be able to install the package 
and begin using your GPU :)

# Things to Do
1. Obviously more vector functions and matrix implementations
2. My resources limit how much I can test (e.g. OS, GPU vendors).  Would
appreciate any feedback on how the installation and use fairs with other
platforms and GPUs.
2. Would love any suggestions :) (submit in the issues)
