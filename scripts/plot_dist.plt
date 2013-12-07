set xlabel "Iteration"
set ylabel "Deviation from best result"
set terminal png
set output "dev1.png"
set autoscale
set grid
plot "dev1.data" using 1:2 with points title ""
