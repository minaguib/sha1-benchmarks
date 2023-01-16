# Modified from https://edg.uchicago.edu/tutorials/gnuplot/

# Set size of output image
set terminal png size 1200,800

# Set name of output file.  The quotes are required
set output "sha1_benchmark_comparison.png"

# Set style of plot.  We want lines
set style data lines

# Set how the data is separated in the file
set datafile separator ","

# Set the title of the plot
set title "Comparison of runtimes for various SHA1 implementations"

# The actual data to plot
# using 1:2 means column 1 is on the X axis and column 2 is on the Y
# with lines means to connect the points with lines
# t "Col 0 XY" is the title for the legend


plot "bench-git.log" using 1:2 with lines t "Git", \
     "bench-openssl.log" using 1:2 with lines t "Openssl Legacy", \
     "bench-openssl-evp.log" using 1:2 with lines t "Openssl EVP", \
     "bench-nayuki.log" using 1:2 with lines t "Nayuki"

