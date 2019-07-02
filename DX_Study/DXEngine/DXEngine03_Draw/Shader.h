#pragma once

#include "DXUtil.h"

class Shader
{
public:
	Shader();
	Shader(LPTSTR fileName);
	Shader(LPTSTR fileName , LPCSTR entry, LPCSTR profile);
	
	virtual ~Shader();

	virtual bool CompileShader(ID3D11Device* device) = 0;
	virtual bool CreateShader(ID3D11Device* device) = 0;
	virtual void BindShader(ID3D11DeviceContext* deviceContext) = 0;
	virtual void Release();

	void SetFileName(LPCSTR fileName) {
		this->fileName = fileName;
	}

	LPCSTR GetFileName() const { return fileName; };
	LPCSTR GetEntryPoint() const { return entryPoint; };
	LPCSTR GetProfile() const { return profile; };
	ID3DBlob* GetShaderBuffer() const { return shaderBuffer; };

protected:
	LPCSTR fileName;					//���̴� ���� �̸� (Ȯ���� ����).
	LPCSTR entryPoint;					//���̴� ����
	LPCSTR profile;						//���̴� ���� ����
	ID3DBlob* shaderBuffer;				//���̴� ������ ��� ����� ����
};

