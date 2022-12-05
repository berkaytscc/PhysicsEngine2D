#ifndef APPLICATION_H


class Application
{
private: 
	bool debug = false; // Unclear, learn how to use it
	bool running = false;

public:
	Application() = default;
	~Application() = default;
	bool isRunning();
	void Setup();
	void Input();
	void Update();
	void Render();
	void Destroy();

};

#define APPLICATION_H
#endif // APPLICATION_H


