#!/bin/csh
set number_runs = 669;
set size = 0;
while ( $number_runs > 0 ) 
	echo "$number_runs"
	./make-matrix -n $size -l 0 -u 1000 -o matrix.bin
	./mm-serial matrix.bin matrix.bin product.bin >> FLOPS_data_size_sec3.txt
	@ number_runs--
	@ size++

end
