set xlabel "Iteration"
set ylabel "The best result"
set terminal png
set output "best.png"
set autoscale
set grid
plot "eval/berlin52/best1.data" using 1:2 with points title ""
