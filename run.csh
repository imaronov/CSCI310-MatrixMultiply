#!/bin/csh
set number_runs = 460;
set start_size = 206;
set size_increment = 1;
while ( $number_runs > 0 ) 
	echo "$number_runs"
	./make-matrix -n $start_size -l 0 -u 1000 -o matrix.bin
	./mm-serial matrix.bin matrix.bin product.bin >> FLOPS_data_size_sec.txt
	@ number_runs--
	@ start_size += $size_increment

end
