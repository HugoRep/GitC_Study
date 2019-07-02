#pragma once
#include "DxApp.h"
#include "Mesh.h"
#include "VertexShader.h"
#include "PixelShader.h"

class Engine : public DxApp
{
public:
	Engine(HINSTANCE hinstance);
	virtual ~Engine();

	int Run();
	bool Init() override;
	void Update() override;
	void Render() override;

private:
	VertexShader* vertexShader;
	PixelShader* pixelShader;

	Mesh* mesh;
};