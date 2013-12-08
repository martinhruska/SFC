set xlabel "Iterace"
#set xrange [0:500]
#set yrange [16400:19000]
set ylabel "Nejlepší výsledek iterace"
set terminal png
set output "best.png"
set autoscale
set grid
plot "eval/lin318/bestb.data" using 1:2 with points title ""
