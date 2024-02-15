#pragma once

class RunTimeEditor {
public:
	bool EDITOR_MODE = true;
	void drawWireFrames() const;
	void drawFilled() const;
	void takeInput() const;
	void turnOffEditor();
};