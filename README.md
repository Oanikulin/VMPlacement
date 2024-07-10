# VMPlacement algortihms for two tier placement with preprocessed datasets

**About**

Repository implements several classical algorithms for two tier virtualisation (First fit, Best Fit, Worst Fit, their decreasing modification), ISP from 
*An Energy-aware Host Resource Management Framework for Two-tier Virtualized Cloud Data Centers* by *Chi Zhang1
, Yuxin Wang2
, Hao Wu
, and He Guo1* and several new modifications utilising harmonic bin-packing and modfifed first fit decreasing

You can find description for each solver in the respective directory.

**Problem in question**

Two tier virtualization is a problem of placing containers in cloud onto hosts. 
Main requirements of containers are memory and CPU.
We want to optimize
For additional security, containers should first be grouped into virtual machines (VMs), which gives a constant overhead.
This stage is called VM-selection.

After that problem is reduced to a classic 2D bin packing. It is NP-complete, so we solve it approximatly.
This stage is called VM-placement.

In new suggested algorithms, I assumed that memory and CPU request are often correlated and, if we apply classic 1D bin-packing ideas to VM-selection, than a better result can be achieved, which was generally true on checked datasets, assuming limited requirements from the original article.

Additionally, sanity check was performed, that showed ISP to be more effective than simple algorithms.

**Build**

Build can be done simply using CMake. No third party is required (e. g. using NINJA).

```
mkdir build && cd build/ && cmake -G Ninja ..
ninja Segmented  && ./solvers/segmented/Segmented ../data/jobs_c.txt ../data/host_c.txt ../data/vm.txt
```

to run Segmented placement algorithm on dataset C.

**Run**

Preprocessed datasets are in *data* folder. DataAnalysis has the same interface as solvers, but it performs some sanity checks on data and collects useful statistics.
