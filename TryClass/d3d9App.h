/****************************************************
*    Author: Tianhao Wang
*    E-mail: wanglingdebian@gmail.com   
*    Date:   2015-03-05   
*    Desc:   һ��ͨ�õ�d3d9�࣬ģ������ڶ������
*****************************************************/   
#ifndef _D3D9APP_
#define _D3D9APP_

#include <d3d9.h>
#include <d3dx9.h>
#include <string>

class d3d9App {
public:
    d3d9App(HINSTANCE hInstance, std::string winTitle, D3DDEVTYPE devType, DWORD vertexProc);
    virtual ~d3d9App();

    // Direct3D�ĳ�ʼ��
    virtual void InitD3D();
    // Windows�����ڵĳ�ʼ��
    virtual void InitWindow();
    // ��Ϣ����
    virtual LRESULT MsgProc(UINT msg, WPARAM wParam, LPARAM lParam);
    // ��Ϣ���Ĳ鿴������
    virtual int MsgLoop();

    // DrawScene����Ϊ���麯���������ڼ̳�ʱ���ж���
    virtual void DrawScene() = 0;
protected:
    D3DDEVTYPE m_devType;          // ��������
    DWORD m_vertexProc;            // ���㻺��
    HINSTANCE m_appInst;           // �������Ŀ���
    HWND m_mainWnd;                // ���ھ��
    D3DPRESENT_PARAMETERS m_d3dPP;
    std::string m_winTitle;        // �������
};

extern LPDIRECT3D9 g_pd3dObject;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern d3d9App* g_d3d9App;

#endif