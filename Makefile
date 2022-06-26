make:
	gcc pathfinding.c pathfinding.h -o pf;./pf mediummaze
clean:
	rm pf
