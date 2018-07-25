#pragma once
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);		//dobra praksa za rad s windows aplikacijama, inaèe ga sam ispuni
	~InputClass();

	void init();

	void keyDown(unsigned int input);
	void keyUp(unsigned int input);

	bool isKeyDown(unsigned int key);
private:
	bool keys[256];
};

