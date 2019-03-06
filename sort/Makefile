run: test 
	cat _rand | ./$(IN) > _test1
	diff _test _test1 > _diff
test: comp
	./rand > _rand && cat _rand | ./judge > _test
comp:
	gcc rand.c -o rand; gcc judge.c -o judge; gcc $(IN).c -o $(IN)
clean:
	rm -f *.exe *.out _test _rand _test1 _diff
