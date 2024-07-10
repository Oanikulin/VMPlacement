# VMPlacement algortihms for two tier placement with preprocessed datasets

**About**

Repository implements several classical algorithms for two tier virtualisation (First fit, Best Fit, Worst Fit, their decreasing modification), ISP from 
*An Energy-aware Host Resource Management Framework for Two-tier Virtualized Cloud Data Centers* by *Chi Zhang1
, Yuxin Wang2
, Hao Wu
, and He Guo1* and several new modifications utilising harmonic bin-packing and modfifed first fit decreasing

You can find description for each solver in the respective directory.

**Build**

Build can be done simply using CMake. No third party is required.

**Run**

Preprocessed datasets are in *data* folder. TestData has the same interface, but it performs some sanity checks on data and collects useful statistics.
