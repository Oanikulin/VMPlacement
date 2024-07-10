# Segmnted modification

Modification of baseline, where we first process small containers of size greater than $0.5 \times LIMIT$. Than we iteratively place containers of size greater than $\dfrac{1}{3} \times LIMIT$ and $\dfrac{1}{6} \times LIMIT$, than maximal fitting container.

After that we perform FFD on remainders.
