buildtest:
	g++ src/test/test.cpp -o src/test/test
runtest:
	make buildtest; ./src/test/test
