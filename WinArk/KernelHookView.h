#pragma once
#include "SSDTHookTable.h"
#include "ShadowSSDTTable.h"
#include "KernelNotifyTable.h"
#include "MiniFilterTable.h"


class CKernelHookView:
	public CWindowImpl<CKernelHookView>{
public:
	DECLARE_WND_CLASS(nullptr);

	const UINT TabId = 1235;
	CKernelHookView() :m_TabCtrl(this) {
	}

	BEGIN_MSG_MAP(CKernelHookView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		NOTIFY_HANDLER(TabId,TCN_SELCHANGE,OnTcnSelChange)
	END_MSG_MAP()

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTcnSelChange(int, LPNMHDR hdr, BOOL&);

	void InitSSDTHookTable();
	void InitShadowSSDTHookTable();
	void InitKernelNotifyTable();
	void InitMiniFilterTable();

	enum class TabColumn : int {
		SSDT,ShadowSSDT,ObjectCallback,MiniFilter
	};
private:
	// 动态创建出来的控件
	CContainedWindowT<CTabCtrl> m_TabCtrl;

	CSSDTHookTable* m_SSDTHookTable;
	CShadowSSDTHookTable* m_ShadowSSDTHookTable;
	CKernelNotifyTable* m_KernelNotifyTable;
	CMiniFilterTable* m_MiniFilterTable{ nullptr };
	HWND m_hwndArray[16];
	int _index = 0;
};