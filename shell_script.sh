# For memory latency
#for i in {8000..2000000..1000}
#	 do
#		./latency $i
#done

# For memory bandwidth
for i in {8000..2000000..10000}
	 do
		./bandwidth $i 2
done