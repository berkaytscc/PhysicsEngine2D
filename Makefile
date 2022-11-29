build: 
	g++ -std=c++14 ./src/*.cpp -o app
run:
	./app
clean:
	del app.exe