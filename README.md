# VMPlacement algortihms for two tier placement with preprocessed datasets

**About**

Repository implements several classical algorithms for two tier virtualisation (First fit, Best Fit, Worst Fit, their decreasing modification), ISP from 
*An Energy-aware Host Resource Management Framework for Two-tier Virtualized Cloud Data Centers* by *Chi Zhang1
, Yuxin Wang2
, Hao Wu
, and He Guo1* and several new modifications utilising harmonic bin-packing and modfifed first fit decreasing

**Build**

If you do not want to use precompiled binaries (compiled with GCC 7.5 under Ubuntu 18.04), build is done using CMake. No extra libraries are required.

**Run**

All placement algorithms are compiled inside *build* folder. To run them give arguments in command line which are shawn when program is started with empty arguments.
Preprocessed datasets are in *data* folder. TestData has the same interface, but it performs some sanity checks on data and collects useful statistics.
