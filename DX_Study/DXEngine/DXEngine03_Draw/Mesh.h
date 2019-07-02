#pragma once
#include "DXUtil.h"

using namespace DirectX;

class Mesh
{
private:
	struct Vertex
	{
		XMFLOAT3 position;
		Vertex(float x, float y, float z):position(x, y , z ) {}
	};
public:
	Mesh();
	~Mesh();

	//ID3DBlob???
	bool initializeBuffers(ID3D11Device* device, ID3DBlob* vertexShaderBuffer);

	void RenderBuffers(ID3D11DeviceContext* deviceContext);

private:

	int nVertices;						//정점 개수
	ID3D11Buffer* vertexBuffer;			//정점 버퍼 저장


	//가이드 인터페이스 같은 ....
	ID3D11InputLayout* inputLayout;		//입력 레이아웃
};

