all:
	cd src && make && cp aco ../
clean:
	rm aco && cd src && make clean
run:
	./aco --help
run_example:
	./aco -i examples/ex16/ex16.aco -a 10 -m 10 -d 2 -e 0.2 -p 1 -g maxmin -x 0.5 -n 0.1 -v
