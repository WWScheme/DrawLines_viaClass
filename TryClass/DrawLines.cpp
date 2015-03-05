/****************************************************
*    Author: Tianhao Wang
*    E-mail: wanglingdebian@gmail.com   
*    Date:   2015-03-05   
*    Desc:   通过继承一个通用的d3d9类来实现画线程序
*****************************************************/   
#include "d3d9App.h"

// 继承通用的d3d9App类，添加了顶点指针和ID3DXLine*成员
class DrawLines : public d3d9App {
public:
	DrawLines(HINSTANCE hInstance, std::string winTitle, D3DDEVTYPE devType, DWORD vertexProc);
	~DrawLines();

	void DrawScene();
private:
	ID3DXLine* m_pLine;
	D3DXVECTOR2* m_pLineArr;
};

// 主函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int)
{
	DrawLines app(hInstance, "DrawLines", D3DDEVTYPE_HAL, D3DCREATE_HARDWARE_VERTEXPROCESSING);
	g_d3d9App = &app;

	return g_d3d9App->MsgLoop();
}

// 紧接着通用类的初始化之后进步一初始化，先创建ID3DLine对象，再指定顶点坐标
DrawLines::DrawLines(HINSTANCE hInstance, std::string winTitle, D3DDEVTYPE devType, DWORD vertexProc)
	: d3d9App(hInstance, winTitle, devType, vertexProc)
{
	if (FAILED(D3DXCreateLine(g_pd3dDevice, &m_pLine))) {
        MessageBox(0, "D3DXCreateLine FAILED", 0, 0);
        PostQuitMessage(0);
    }

    m_pLineArr = new D3DXVECTOR2[4];
    m_pLineArr[0].x = m_pLineArr[0].y = 100;
    m_pLineArr[1].x = m_pLineArr[1].y = 400;
    m_pLineArr[2].x = 400; m_pLineArr[2].y = 100;
    m_pLineArr[3].x = 100; m_pLineArr[3].y = 400;
}

DrawLines::~DrawLines()
{
	if (m_pLine)
		m_pLine->Release();
	delete m_pLineArr;
}

// 负责绘制的成员函数总是需要自行定义
void DrawLines::DrawScene()
{
	g_pd3dDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    if (FAILED(g_pd3dDevice->BeginScene())) {
        MessageBox(0, "BeginScene FAILED", 0, 0);
        PostQuitMessage(0);
    }

    m_pLine->Draw(m_pLineArr, 4, D3DCOLOR_XRGB(255, 255, 255));

    g_pd3dDevice->EndScene();
    g_pd3dDevice->Present(0, 0, 0, 0);
}