// CHelpDlg.cpp: 实现文件
//

#include "pch.h"
#include "DllHelp.h"
#include "afxdialogex.h"
#include "CHelpDlg.h"


// CHelpDlg 对话框

IMPLEMENT_DYNAMIC(CHelpDlg, CDialogEx)

CHelpDlg::CHelpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_EdtNum(_T(""))
{

}

CHelpDlg::~CHelpDlg()
{
}

void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialogEx)
	ON_BN_CLICKED(BTN_SUN, &CHelpDlg::OnBnClickedSun)
	ON_BN_CLICKED(BTN_PLANET, &CHelpDlg::OnBnClickedPlanet)
	ON_BN_CLICKED(BTN_CHANGE, &CHelpDlg::OnBnClickedChange)
END_MESSAGE_MAP()


// CHelpDlg 消息处理程序


void CHelpDlg::OnBnClickedSun()
{

	//要修改的代码位置
	DWORD dw_code = 0x43158f;
	DWORD dwOld = 0;
	//修改内存属性
	VirtualProtect((LPVOID)dw_code, 1, PAGE_EXECUTE_READWRITE, &dwOld);

	//修改内存代码，使其自动拾取阳光 00905a40 0043158f
	__asm {
		mov eax, dw_code
		mov byte ptr [eax], 0EBh
	}

	//还原内存属性
	VirtualProtect((LPVOID)dw_code, 1, dwOld, &dwOld);

}


void CHelpDlg::OnBnClickedPlanet()
{
	int nRow = 0;	//行坐标
	int nCol = 0;	//列坐标
	int nSun = 0;	//阳光数量


	//遍历所有坐标，自动种满植物
	for (nCol = 0; nCol <= 8; nCol++) {

		for (nRow = 0; nRow <= 4; nRow++) {
			//种向日葵
			if (nCol == 0) {
				//先判断阳光是否足够
				while (nSun < 50) {

					__asm {
						push eax
						mov eax, 6a9ec0h
						mov eax, [eax]
						mov eax, [eax + 768h]
						mov eax, [eax + 5560h]
						mov nSun, eax
						pop eax
					}

				}

				//阳光足够，种植一个向日葵
				__asm {
					push edx
					push eax
					push edi
					push ebp
					push ecx

					mov edx, 0FFFFFFFFh
					push edx
					mov eax, 1
					push eax
					mov eax, nRow
					mov edi, nCol
					push edi
					mov ebp, 6a9ec0h
					mov ebp, [ebp]
					mov ebp, [ebp + 768h]
					push ebp
					mov ecx, 40d120h
					call ecx
					
					pop ecx
					pop ebp
					pop edi
					pop eax
					pop edx

					push eax
					push ebx
					//将阳光减少50个
					mov eax, 6a9ec0h
					mov eax, [eax]
					mov eax, [eax + 768h]
					mov ebx, nSun
					sub ebx, 50
					mov[eax + 5560h], ebx
					mov nSun, ebx

					pop ebx
					pop eax
				}
				continue;

			}
			//种豌豆射手
			else {

				//先判断阳光是否足够
				while (nSun < 100) {

					__asm {
						push eax
						mov eax, 6a9ec0h
						mov eax, [eax]
						mov eax, [eax + 768h]
						mov eax, [eax + 5560h]
						mov nSun, eax
						pop eax
					}

				}

				//阳光足够，种植一个豌豆射手
				__asm {
					push edx
					push eax
					push edi
					push ebp
					push ecx

					mov edx, 0FFFFFFFFh
					push edx
					mov eax, 0
					push eax
					mov eax, nRow
					mov edi, nCol
					push edi
					mov ebp, 6a9ec0h
					mov ebp, [ebp]
					mov ebp, [ebp + 768h]
					push ebp
					mov ecx, 40d120h
					call ecx

					pop ecx
					pop ebp
					pop edi
					pop eax
					pop edx

					push eax
					push ebx
					//将阳光减少100个
					mov eax, 6a9ec0h
					mov eax, [eax]
					mov eax, [eax + 768h]
					mov ebx, nSun
					sub ebx, 100
					mov[eax + 5560h], ebx
					mov nSun, ebx

					pop ebx
					pop eax
					
				}
				continue;
			}
		}
	}

}


void CHelpDlg::OnBnClickedChange()
{
	// TODO: 在此添加控件通知处理程序代码
	
}
